#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "HelperFunctions.generated.h"

/**
 * A collection of static helper functions to be used across the project.
 */
UCLASS()
class COSMICBULLETHELL_API UHelperFunctions : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    /**
     * Ensures the value remains within the specified range.
     * @param Value - The value to be clamped.
     * @param MinValue - The minimum permissible value.
     * @param MaxValue - The maximum permissible value.
     * @return The clamped value.
     */
    UFUNCTION(BlueprintPure, Category = "Helper|Math")
    static float ClampValue(float Value, float MinValue, float MaxValue);

    /**
     * Formats the damage value for display as floating combat text.
     * @param DamageValue - The damage value to be formatted.
     * @return Formatted text for floating combat text.
     */
    UFUNCTION(BlueprintPure, Category = "Helper|UI")
    static FText FormatFloatingCombatText(float DamageValue);

    /**
     * Maps input to the corresponding key based on platform for unified input handling.
     * @param KeyInput - The keyboard or gamepad input to be mapped.
     * @return The corresponding input based on platform.
     */
    UFUNCTION(BlueprintPure, Category = "Helper|Input")
    static FKey InputMapping(FKey KeyInput);

    /**
     * Determines if the game is being played on a device with a touchscreen.
     * @return True if the current device has a touchscreen, false otherwise.
     */
    UFUNCTION(BlueprintPure, Category = "Helper|Device", meta = (BlueprintThreadSafe))
    static bool IsTouchscreenDevice();

    /**
     * Applies the specified style settings to the Slate UI.
     * @param UIManagerStyle - The style settings to be applied.
     */
    UFUNCTION(BlueprintCallable, Category = "Helper|UI")
    static void ApplySlateStyle(const FUIManagerStyle& UIManagerStyle);

    /**
     * Spawns a projectile in the game scene with the specified parameters.
     * @param ProjectileClass - The class of projectile to spawn.
     * @param SpawnLocation - The location at which to spawn the projectile.
     * @param SpawnRotation - The rotation of the spawned projectile.
     * @return The spawned projectile actor.
     */
    UFUNCTION(BlueprintCallable, Category = "Helper|Gameplay")
    static AActor* SpawnProjectile(TSubclassOf<AActor> ProjectileClass, FVector SpawnLocation, FRotator SpawnRotation);

    /**
     * Performs a trace from the mouse cursor to find the actor under the mouse.
     * @param PlayerController - The player controller to use for the trace.
     * @return The actor under the mouse cursor, or nullptr if none.
     */
    UFUNCTION(BlueprintCallable, Category = "Helper|Input")
    static AActor* GetActorUnderMouse(APlayerController* PlayerController);

    /**
     * Plays the specified audio asset in the scene.
     * @param AudioAsset - The audio asset to play.
     * @param VolumeMultiplier - The volume multiplier for the audio playback.
     */
    UFUNCTION(BlueprintCallable, Category = "Helper|Audio")
    static void PlaySceneAudio(USoundBase* AudioAsset, float VolumeMultiplier);

    /** Event triggered when an actor's health value changes.
     * @param NewHealthValue - The new health value of the actor.
     */
    DECLARE_EVENT_OneParam(UHelperFunctions, FOnHealthValueChanged, float)
    static FOnHealthValueChanged OnHealthValueChanged;
};
