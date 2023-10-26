#include "FloatingCombatTextManager.h"
#include "Kismet/GameplayStatics.h"
#include "YourGameCombatTextWidget.h"  // Assume you have a custom UUserWidget derived class for displaying combat text

AFloatingCombatTextManager::AFloatingCombatTextManager()
{
    // Set default values
    CombatTextFont = nullptr;  // Assume you set a default font in the engine or via blueprint
    CombatTextColor = FColor::Red;
    CombatTextDuration = 2.0f;
    CombatTextVelocity = FVector(0, 0, 100);  // Simple upward movement
}

void AFloatingCombatTextManager::DisplayCombatText(AActor* Actor, float DamageAmount)
{
    if (Actor && CombatTextFont)
    {
        UYourGameCombatTextWidget* CombatTextWidget = nullptr;

        // Check for available combat text widgets in the pool
        for (int32 Index = 0; Index < CombatTextPool.Num(); ++Index)
        {
            if (!CombatTextPool[Index]->IsVisible())
            {
                CombatTextWidget = Cast<UYourGameCombatTextWidget>(CombatTextPool[Index]);
                break;
            }
        }

        // If no available widget found in the pool, create a new one
        if (!CombatTextWidget)
        {
            CombatTextWidget = CreateWidget<UYourGameCombatTextWidget>(GetWorld(), UYourGameCombatTextWidget::StaticClass());
            CombatTextPool.Add(CombatTextWidget);
        }

        if (CombatTextWidget)
        {
            // Set combat text properties
            CombatTextWidget->SetText(FText::AsNumber(DamageAmount));
            CombatTextWidget->SetColor(CombatTextColor);
            CombatTextWidget->SetWorldLocation(Actor->GetActorLocation());
            CombatTextWidget->SetDuration(CombatTextDuration);
            CombatTextWidget->SetVelocity(CombatTextVelocity);

            // Display combat text
            CombatTextWidget->AddToViewport();
        }
    }
}

void AFloatingCombatTextManager::SetupHealthManagerReference(AActorHealthManager* HealthManager)
{
    ActorHealthManagerRef = HealthManager;
    SubscribeToDamageEvents();
}

void AFloatingCombatTextManager::SubscribeToDamageEvents()
{
    if (ActorHealthManagerRef)
    {
        // Assume ActorHealthManager has a delegate called OnActorDamaged
        ActorHealthManagerRef->OnActorDamaged.AddDynamic(this, &AFloatingCombatTextManager::OnActorDamaged);
    }
}

void AFloatingCombatTextManager::OnActorDamaged(AActor* Actor, float DamageAmount)
{
    DisplayCombatText(Actor, DamageAmount);
}

void AFloatingCombatTextManager::ReturnCombatTextToPool(UUserWidget* CombatTextWidget)
{
    if (CombatTextWidget)
    {
        CombatTextWidget->RemoveFromViewport();
    }
}

void AFloatingCombatTextManager::BeginPlay()
{
    Super::BeginPlay();
    SubscribeToDamageEvents();
}
