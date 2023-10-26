#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Styling/SlateTypes.h"  // For FProgressBarStyle and FSlateFontInfo
#include "ActorHealthManager.h"  // Ensure this include path is correct
#include "Blueprint/UserWidget.h"  // For UUserWidget
#include "UIHealthComponent.generated.h"

/**
 * A component for managing and displaying health UI using Slate or UMG.
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class YOURGAME_API UUIHealthComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    // Constructor
    UUIHealthComponent();

    // The style of the health bar
    UPROPERTY(BlueprintReadWrite, Category = "Health UI")
    FProgressBarStyle HealthBarStyle;

    // The style of the health text
    UPROPERTY(BlueprintReadWrite, Category = "Health UI")
    FSlateFontInfo HealthTextStyle;

    // Updates the health display based on the current health data from the ActorHealthManager
    UFUNCTION(BlueprintCallable, Category = "Health UI")
    void UpdateHealthDisplay();

    // Sets up a reference to the ActorHealthManager to be used for retrieving health data
    UFUNCTION(BlueprintCallable, Category = "Health UI")
    void SetupHealthManagerReference(AActorHealthManager* HealthManager);

protected:
    // A reference to the Slate or UMG Health Bar Widget
    UPROPERTY()
    UUserWidget* HealthBarWidget;

    // A reference to the Slate or UMG Health Text Widget
    UPROPERTY()
    UUserWidget* HealthTextWidget;

    // Reference to the ActorHealthManager to retrieve health data
    UPROPERTY()
    AActorHealthManager* ActorHealthManagerRef;

    // Flag indicating whether the health display has been initialized
    UPROPERTY()
    bool bIsHealthDisplayInitialized;

    // Creates a Slate or UMG health bar widget using the specified style and attaches it to the UI
    void CreateHealthBar();

    // Creates a Slate or UMG text widget for displaying health values and attaches it to the UI
    void CreateHealthText();

    // Calls CreateHealthBar and CreateHealthText to initialize health UI elements
    void InitializeHealthDisplay();

    // Unreal Engine event called at the start of play
    virtual void BeginPlay() override;

    // Unreal Engine event called every frame
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};

