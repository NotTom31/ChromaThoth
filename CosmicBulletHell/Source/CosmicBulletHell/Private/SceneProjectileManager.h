#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.h"
#include "SceneProjectileManager.generated.h"

UENUM(BlueprintType)
enum class EProjectileShapePattern : uint8
{
    PSP_Spiral,
    PSP_Ring,
    PSP_Grid,
    PSP_Random,
    // ... add more patterns as needed
};

UCLASS()
class COSMICBULLETHELL_API ASceneProjectileManager : public AActor
{
    GENERATED_BODY()

public:
    ASceneProjectileManager();

    UPROPERTY(BlueprintReadWrite, Category = "Projectile Management")
    int32 MaxPoolSizePerCategory;

    UPROPERTY(BlueprintReadWrite, Category = "Projectile Management")
    TMap<FName, TSubclassOf<AProjectile>> ProjectileBlueprints;

    UPROPERTY(BlueprintReadWrite, Category = "Projectile Management")
    float SpawnRate;

    UPROPERTY(BlueprintReadWrite, Category = "Projectile Pattern")
    EProjectileShapePattern ShapePattern;

    UPROPERTY(BlueprintReadWrite, Category = "Projectile Pattern")
    float PatternUpdateTime;

    UFUNCTION(BlueprintCallable, Category = "Projectile Management")
    AProjectile* SpawnProjectile(FName Type, FVector SpawnLocation, FRotator SpawnRotation);

    UFUNCTION(BlueprintCallable, Category = "Projectile Management")
    void RecycleProjectile(FName Type, AProjectile* Projectile);

    UFUNCTION(BlueprintCallable, Category = "Projectile Management")
    void ClearProjectilePool(FName Type);

    UFUNCTION()
    void UpdatePattern();

protected:
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
    virtual void Tick(float DeltaTime) override;

private:
    TMap<FName, TArray<AProjectile*>> ProjectilePools;
    float LastPatternUpdateTime;
};

