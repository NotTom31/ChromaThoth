#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Blueprint/UserWidget.h"
#include "ActorHealthManager.h"
#include "FloatingCombatTextManager.generated.h"

/**
 * A class responsible for managing and displaying floating combat text
 * when actors take damage, utilizing a pool of reusable widgets for optimized performance.
 */
UCLASS()
class YOURGAME_API AFloatingCombatTextManager : public AActor
{
    GENERATED_BODY()

public:
    // Constructor
    AFloatingCombatTextManager();

    // The font used to render combat text
    UPROPERTY(BlueprintReadWrite, Category = "Combat Text")
    UFont* CombatTextFont;

    // The color of the combat text
    UPROPERTY(BlueprintReadWrite, Category = "Combat Text")
    FColor CombatTextColor;

    // The duration for which the combat text is displayed
    UPROPERTY(BlueprintReadWrite, Category = "Combat Text")
    float CombatTextDuration;

    // The initial velocity of the combat text
    UPROPERTY(BlueprintReadWrite, Category = "Combat Text")
    FVector CombatTextVelocity;

    // Displays floating combat text showing the amount of damage taken by the specified actor
    UFUNCTION(BlueprintCallable, Category = "Combat Text")
    void DisplayCombatText(AActor* Actor, float DamageAmount);

    // Sets up a reference to the ActorHealthManager to be used for retrieving damage data
    UFUNCTION(BlueprintCallable, Category = "Combat Text")
    void SetupHealthManagerReference(AActorHealthManager* HealthManager);

protected:
    // Reference to the ActorHealthManager to retrieve damage data
    UPROPERTY()
    AActorHealthManager* ActorHealthManagerRef;

    // A pool of reusable combat text widgets to optimize performance
    UPROPERTY()
    TArray<UUserWidget*> CombatTextPool;

    // Subscribes the FloatingCombatTextManager to the damage events of the ActorHealthManager
    UFUNCTION()
    void SubscribeToDamageEvents();

    // Handler function to be called when an actor takes damage, triggering the display of combat text
    UFUNCTION()
    void OnActorDamaged(AActor* Actor, float DamageAmount);

    // Returns a combat text widget to the pool for reuse
    UFUNCTION()
    void ReturnCombatTextToPool(UUserWidget* CombatTextWidget);

    // Unreal Engine event called at the start of play
    virtual void BeginPlay() override;
};
