#include "ActorHealthManager.h"
#include "Engine/Engine.h"  // Required for GEngine

AActorHealthManager::AActorHealthManager()
{
    // Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;

    // Set default values
    DefaultHealth = 100.0f;
    MaxHealth = 100.0f;
    bShowHealthInEditor = true;
}

void AActorHealthManager::RegisterActor(AActor* Actor)
{
    if (Actor)
    {
        HealthData.Add(Actor, DefaultHealth);
    }
}

void AActorHealthManager::UnregisterActor(AActor* Actor)
{
    if (Actor)
    {
        HealthData.Remove(Actor);
    }
}

void AActorHealthManager::SetHealth(AActor* Actor, float HealthValue)
{
    if (Actor && HealthData.Contains(Actor))
    {
        HealthData[Actor] = FMath::Clamp(HealthValue, 0.0f, MaxHealth);
    }
}

float AActorHealthManager::GetHealth(AActor* Actor) const
{
    if (Actor && HealthData.Contains(Actor))
    {
        return HealthData[Actor];
    }
    return -1.0f;  // Return -1.0f if the actor is not registered
}

void AActorHealthManager::TestActorHealthInEditor()
{
    for (const TPair<AActor*, float>& Entry : HealthData)
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("%s Health: %f"), *Entry.Key->GetName(), Entry.Value));
        }
    }
}

void AActorHealthManager::ApplyDamage(AActor* Actor, float DamageAmount)
{
    if (Actor && HealthData.Contains(Actor))
    {
        HealthData[Actor] = FMath::Max(HealthData[Actor] - DamageAmount, 0.0f);
    }
}

void AActorHealthManager::HealActor(AActor* Actor, float HealAmount)
{
    if (Actor && HealthData.Contains(Actor))
    {
        HealthData[Actor] = FMath::Min(HealthData[Actor] + HealAmount, MaxHealth);
    }
}
