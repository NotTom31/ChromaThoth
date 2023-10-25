#include "EnemyAIManager.h"
#include "YourGame/YourEnemyAI.h"
#include "YourGame/YourBulletPattern.h"
#include "Engine/World.h"

AEnemyAIManager::AEnemyAIManager()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AEnemyAIManager::ManageEnemies()
{
    // Check if the number of enemies is less than the maximum allowed
    if (ManagedEnemies.Num() < MaxEnemyCount)
    {
        SpawnEnemies();
    }

    EvaluateEnemyBehavior();

    // Example: Transition phase every 30 seconds (assuming a phase duration of 30 seconds)
    if (GetWorld()->GetTimeSeconds() - CurrentPhaseStartTime >= 30.0f)
    {
        TransitionEnemyPhase(CurrentPhase + 1);
    }
}

TArray<AActor*> AEnemyAIManager::GetEnemies() const
{
    return ManagedEnemies;
}

void AEnemyAIManager::TriggerBulletPatterns()
{
    for (AActor* Enemy : ManagedEnemies)
    {
        AYourEnemyAI* YourEnemy = Cast<AYourEnemyAI>(Enemy);
        if (YourEnemy)
        {
            YourEnemy->TriggerBulletPattern();
        }
    }
}

void AEnemyAIManager::SpawnEnemies()
{
    UWorld* World = GetWorld();
    if (World)
    {
        for (AActor* SpawnPoint : SpawnPoints)
        {
            AActor* SpawnedEnemy = World->SpawnActor<AActor>(EnemyAIClass, SpawnPoint->GetActorLocation(), SpawnPoint->GetActorRotation());
            if (SpawnedEnemy)
            {
                ManagedEnemies.Add(SpawnedEnemy);
            }
        }
    }
}

void AEnemyAIManager::DespawnEnemies()
{
    for (AActor* Enemy : ManagedEnemies)
    {
        Enemy->Destroy();
    }
    ManagedEnemies.Empty();
}

void AEnemyAIManager::TransitionEnemyPhase(int NewPhase)
{
    CurrentPhase = NewPhase;
    CurrentPhaseStartTime = GetWorld()->GetTimeSeconds();  // Reset the phase start time

    for (AActor* Enemy : ManagedEnemies)
    {
        AYourEnemyAI* YourEnemy = Cast<AYourEnemyAI>(Enemy);
        if (YourEnemy)
        {
            YourEnemy->TransitionToPhase(NewPhase);
        }
    }
}

void AEnemyAIManager::EvaluateEnemyBehavior()
{
    for (AActor* Enemy : ManagedEnemies)
    {
        AYourEnemyAI* YourEnemy = Cast<AYourEnemyAI>(Enemy);
        if (YourEnemy)
        {
            YourEnemy->EvaluateBehavior();
        }
    }
}

void AEnemyAIManager::ApplyPhaseTransition(AActor* Enemy, const FPhaseTransition& PhaseTransition)
{
    // Assuming YourEnemyAI has a method to apply phase transition
    AYourEnemyAI* YourEnemy = Cast<AYourEnemyAI>(Enemy);
    if (YourEnemy)
    {
        YourEnemy->ApplyPhaseTransition(PhaseTransition);
    }
}

bool AEnemyAIManager::CheckTransitionCondition(AActor* Enemy, const FPhaseTransition& PhaseTransition) const
{
    // Assuming YourEnemyAI has a method to check phase transition condition
    AYourEnemyAI* YourEnemy = Cast<AYourEnemyAI>(Enemy);
    if (YourEnemy)
    {
        return YourEnemy->CheckTransitionCondition(PhaseTransition);
    }
    return false;
}
