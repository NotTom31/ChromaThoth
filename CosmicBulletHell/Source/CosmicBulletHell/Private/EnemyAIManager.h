#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyAIManager.generated.h"

/**
 * Struct to define the conditions and properties for phase transitions.
 */
USTRUCT(BlueprintType)
struct FPhaseTransition
{
    GENERATED_BODY()

    // Define properties and methods for phase transition conditions and actions.
    // For example, phase transition trigger conditions, actions to perform during transitions, etc.

    // Placeholder for transition condition, replace with actual condition properties
    UPROPERTY(BlueprintReadWrite, Category = "Phase Transition")
    bool bTransitionCondition;

    // Placeholder for action to perform during transition, replace with actual action properties or methods
    UFUNCTION(BlueprintCallable, Category = "Phase Transition")
    void TransitionAction();
};

/**
 * Efficiently manages the spawning, behavior, phase transitions, and despawning of enemy AI actors capable of generating Bullet Hell-style bullet patterns within an Unreal Engine game project.
 */
UCLASS(BlueprintSpawnableComponent)
class YOURGAME_API AEnemyAIManager : public AActor
{
    GENERATED_BODY()

public:
    // Constructor
    AEnemyAIManager();

    // The class of enemy AI actors to spawn and manage.
    UPROPERTY(BlueprintReadWrite, Category = "Enemy AI")
    TSubclassOf<AActor> EnemyAIClass;

    // Points in the world where enemy AI actors can spawn.
    UPROPERTY(BlueprintReadWrite, Category = "Enemy AI")
    TArray<AActor*> SpawnPoints;

    // The maximum number of enemy AI actors that can exist at one time.
    UPROPERTY(BlueprintReadWrite, Category = "Enemy AI")
    int MaxEnemyCount;

    // The class of bullet pattern actors to be used by enemy AI actors.
    UPROPERTY(BlueprintReadWrite, Category = "Bullet Hell")
    TSubclassOf<AActor> BulletPatternClass;

    // Defines phase transitions for enemy AI actors based on conditions such as elapsed time or health thresholds.
    UPROPERTY(BlueprintReadWrite, Category = "Bullet Hell")
    TMap<int, FPhaseTransition> PhaseTransitions;

    // Central method to handle spawning, despawning, and transitioning phases of enemy AI actors based on game conditions.
    UFUNCTION(BlueprintCallable, Category = "Enemy AI")
    void ManageEnemies();

    // Returns a list of all currently managed enemy AI actors.
    UFUNCTION(BlueprintCallable, Category = "Enemy AI")
    TArray<AActor*> GetEnemies() const;

    // Triggers the bullet patterns for all managed enemy AI actors.
    UFUNCTION(BlueprintCallable, Category = "Bullet Hell")
    void TriggerBulletPatterns();

protected:
    // A list of currently managed enemy AI actors.
    UPROPERTY(VisibleAnywhere, Category = "Enemy AI")
    TArray<AActor*> ManagedEnemies;

    // The current phase of enemy AI behavior.
    UPROPERTY(VisibleAnywhere, Category = "Bullet Hell")
    int CurrentPhase;

    // Spawns enemy AI actors at specified spawn points until the maximum enemy count is reached.
    void SpawnEnemies();

    // Despawns all managed enemy AI actors.
    void DespawnEnemies();

    // Transitions all managed enemy AI actors to a new phase based on defined phase transitions.
    UFUNCTION(BlueprintCallable, Category = "Bullet Hell")
    void TransitionEnemyPhase(int NewPhase);

    // Evaluates the behavior of all managed enemy AI actors, adjusting bullet patterns and transitioning phases as necessary.
    void EvaluateEnemyBehavior();

private:
    // Helper method to evaluate and apply a phase transition to a specific enemy AI actor.
    void ApplyPhaseTransition(AActor* Enemy, const FPhaseTransition& PhaseTransition);

    // Helper method to check the transition condition for a specific enemy AI actor.
    bool CheckTransitionCondition(AActor* Enemy, const FPhaseTransition& PhaseTransition) const;

    // ... Additional private helper methods and properties can be defined here.
};
