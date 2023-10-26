
#include "SceneProjectileManager.h"
#include "Engine/World.h"

ASceneProjectileManager::ASceneProjectileManager()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    MaxPoolSizePerCategory = 100;  // Default max pool size per category
    SpawnRate = 10.0f;  // Default spawn rate
    ShapePattern = EProjectileShapePattern::PSP_Random;  // Default shape pattern
    PatternUpdateTime = 1.0f;  // Default pattern update time
}

void ASceneProjectileManager::BeginPlay()
{
    Super::BeginPlay();
    LastPatternUpdateTime = GetWorld()->GetTimeSeconds();
}

void ASceneProjectileManager::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    ClearProjectilePool(NAME_None);  // Clear all projectile pools on end play
    Super::EndPlay(EndPlayReason);
}

void ASceneProjectileManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    
    float CurrentTime = GetWorld()->GetTimeSeconds();
    if (CurrentTime - LastPatternUpdateTime >= PatternUpdateTime)
    {
        UpdatePattern();
        LastPatternUpdateTime = CurrentTime;
    }
}

AProjectile* ASceneProjectileManager::SpawnProjectile(FName Type, FVector SpawnLocation, FRotator SpawnRotation)
{
    if (ProjectileBlueprints.Contains(Type))
    {
        TArray<AProjectile*>& Pool = ProjectilePools.FindOrAdd(Type);

        AProjectile* Projectile = nullptr;
        if (Pool.Num() > 0)
        {
            // Reuse a projectile from the pool
            Projectile = Pool.Pop();
            Projectile->SetActorLocationAndRotation(SpawnLocation, SpawnRotation);
            Projectile->SetActorHiddenInGame(false);
        }
        else if (Pool.Num() < MaxPoolSizePerCategory)
        {
            // Spawn a new projectile
            Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprints[Type], SpawnLocation, SpawnRotation);
        }

        return Projectile;
    }

    return nullptr;
}

void ASceneProjectileManager::RecycleProjectile(FName Type, AProjectile* Projectile)
{
    if (Projectile && ProjectilePools.Contains(Type) && ProjectilePools[Type].Num() < MaxPoolSizePerCategory)
    {
        Projectile->SetActorHiddenInGame(true);
        ProjectilePools[Type].Add(Projectile);
    }
}

void ASceneProjectileManager::ClearProjectilePool(FName Type)
{
    if (Type == NAME_None)
    {
        // Clear all projectile pools
        for (auto& PoolPair : ProjectilePools)
        {
            for (AProjectile* Projectile : PoolPair.Value)
            {
                Projectile->Destroy();
            }
            PoolPair.Value.Empty();
        }
        ProjectilePools.Empty();
    }
    else if (ProjectilePools.Contains(Type))
    {
        // Clear specified projectile pool
        for (AProjectile* Projectile : ProjectilePools[Type])
        {
            Projectile->Destroy();
        }
        ProjectilePools[Type].Empty();
    }
}

void ASceneProjectileManager::UpdatePattern()
{
    // Implement logic for updating projectile output shape based on ShapePattern, SpawnRate, and other relevant properties.
    // This is a placeholder, and the actual implementation would depend on the game's specific requirements.
}
