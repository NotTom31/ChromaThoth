#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorHealthManager.generated.h"

/**
 * A class to manage health for actors in a game, with functionality for registering and unregistering actors,
 * setting and getting health values, applying damage, healing actors, and testing actor health in the editor.
 */
UCLASS(Blueprintable)
class YOURGAME_API AActorHealthManager : public AActor
{
    GENERATED_BODY()

public:
    // Constructor
    AActorHealthManager();

    // The default health value for actors when they are registered
    UPROPERTY(BlueprintReadWrite, Category = "Health")
    float DefaultHealth;

    // The maximum health value that actors can have
    UPROPERTY(BlueprintReadWrite, Category = "Health")
    float MaxHealth;

    // A flag to indicate whether to show actors' health in the editor
    UPROPERTY(BlueprintReadWrite, Category = "Editor")
    bool bShowHealthInEditor;

    // Registers an actor with the health manager, setting its health to the default health value
    UFUNCTION(BlueprintCallable, Category = "Health")
    void RegisterActor(AActor* Actor);

    // Unregisters an actor from the health manager, removing its health data
    UFUNCTION(BlueprintCallable, Category = "Health")
    void UnregisterActor(AActor* Actor);

    // Sets the health value for a specified actor, ensuring it does not exceed the MaxHealth value
    UFUNCTION(BlueprintCallable, Category = "Health")
    void SetHealth(AActor* Actor, float HealthValue);

    // Gets the current health value of a specified actor
    UFUNCTION(BlueprintCallable, Category = "Health")
    float GetHealth(AActor* Actor) const;

    // Tests the current health of all registered actors in the editor, outputting the results to the log or other editor UI
    UFUNCTION(CallInEditor, Category = "Editor")
    void TestActorHealthInEditor();

    // Applies damage to a specified actor, reducing its health by the specified damage amount, and ensuring it does not fall below zero
    UFUNCTION(BlueprintCallable, Category = "Health")
    void ApplyDamage(AActor* Actor, float DamageAmount);

    // Restores health to a specified actor, increasing its health by the specified heal amount, and ensuring it does not exceed the MaxHealth value
    UFUNCTION(BlueprintCallable, Category = "Health")
    void HealActor(AActor* Actor, float HealAmount);

private:
    // A map that stores a reference to actors and their current health values
    UPROPERTY()
    TMap<AActor*, float> HealthData;
};
