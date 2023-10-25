#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UIHealthComponent.h"
#include "UIComponentManager.generated.h"

USTRUCT(BlueprintType)
struct FUIManagerStyle
{
    GENERATED_BODY()
    
    // Add styling properties for Slate UI here
};

UCLASS()
class COSMICBULLETHELL_API AUIComponentManager : public AActor
{
    GENERATED_BODY()

public:
    AUIComponentManager();

    UPROPERTY(BlueprintReadWrite, Category = "UI")
    bool IsUIUpdateEnabled;

    UPROPERTY(BlueprintReadWrite, Category = "UI")
    FUIManagerStyle UIManagerStyle;

    UPROPERTY(BlueprintReadWrite, Category = "UI")
    float UpdateFrequency;

    UFUNCTION(BlueprintCallable, Category = "UI")
    void RegisterHealthComponent(AActor* OwningActor, UUIHealthComponent* HealthComponent);
    
    UFUNCTION(BlueprintCallable, Category = "UI")
    void UnregisterHealthComponent(AActor* OwningActor);
    
    UFUNCTION(BlueprintCallable, Category = "UI")
    UUIHealthComponent* GetHealthComponent(AActor* OwningActor);
    
    UFUNCTION(BlueprintCallable, Category = "UI")
    void UpdateUI();
    
    UFUNCTION(BlueprintCallable, Category = "UI")
    void UpdateSpecificUI(AActor* OwningActor);
    
    UFUNCTION(BlueprintCallable, Category = "UI")
    void ApplyUIStyle();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY()
    TMap<AActor*, UUIHealthComponent*> HealthComponentMap;

    float LastUpdateTime;
};
