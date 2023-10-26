#include "UIComponentManager.h"

AUIComponentManager::AUIComponentManager()
{
    PrimaryActorTick.bCanEverTick = true;
    IsUIUpdateEnabled = true;
    UpdateFrequency = 0.1f;  // Default to updating every 0.1 seconds
    LastUpdateTime = 0.0f;
}

void AUIComponentManager::BeginPlay()
{
    Super::BeginPlay();
}

void AUIComponentManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (IsUIUpdateEnabled && (GetWorld()->GetTimeSeconds() - LastUpdateTime >= UpdateFrequency))
    {
        UpdateUI();
        LastUpdateTime = GetWorld()->GetTimeSeconds();
    }
}

void AUIComponentManager::RegisterHealthComponent(AActor* OwningActor, UUIHealthComponent* HealthComponent)
{
    if (OwningActor && HealthComponent)
    {
        HealthComponentMap.Add(OwningActor, HealthComponent);
    }
}

void AUIComponentManager::UnregisterHealthComponent(AActor* OwningActor)
{
    if (OwningActor)
    {
        HealthComponentMap.Remove(OwningActor);
    }
}

UUIHealthComponent* AUIComponentManager::GetHealthComponent(AActor* OwningActor)
{
    return OwningActor ? HealthComponentMap.FindRef(OwningActor) : nullptr;
}

void AUIComponentManager::UpdateUI()
{
    for (auto& Entry : HealthComponentMap)
    {
        UUIHealthComponent* HealthComponent = Entry.Value;
        if (HealthComponent)
        {
            // Assume UpdateHealthUI is a method in UUIHealthComponent to update the UI
            HealthComponent->UpdateHealthUI();
        }
    }
}

void AUIComponentManager::UpdateSpecificUI(AActor* OwningActor)
{
    UUIHealthComponent* HealthComponent = GetHealthComponent(OwningActor);
    if (HealthComponent)
    {
        HealthComponent->UpdateHealthUI();
    }
}

void AUIComponentManager::ApplyUIStyle()
{
    // Apply UIManagerStyle to Slate UI
    // This method will need to be filled out with the specific logic to apply the style to Slate UI
}
