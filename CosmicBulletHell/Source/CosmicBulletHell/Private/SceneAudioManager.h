#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sound/SoundBase.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundClass.h"
#include "SceneAudioManager.generated.h"

/**
 * Manager for controlling and categorizing audio within a scene.
 */
UCLASS()
class YOURGAME_API ASceneAudioManager : public AActor
{
    GENERATED_BODY()

public:
    // Constructor
    ASceneAudioManager();

    // Background music asset
    UPROPERTY(BlueprintReadWrite, Category = "Audio")
    USoundBase* BackgroundMusic;

    // Map of ambient sound assets
    UPROPERTY(BlueprintReadWrite, Category = "Audio")
    TMap<FName, USoundBase*> AmbientSounds;

    // Map of sound categories
    UPROPERTY(BlueprintReadWrite, Category = "Audio")
    TMap<FName, USoundClass*> SoundCategories;

    // Master volume control
    UPROPERTY(BlueprintReadWrite, Category = "Audio")
    float MasterVolume;

    // Starts playback of a specified sound
    UFUNCTION(BlueprintCallable, Category = "Audio")
    bool PlaySound(FName SoundID);

    // Stops playback of a specified sound
    UFUNCTION(BlueprintCallable, Category = "Audio")
    bool StopSound(FName SoundID);

    // Sets the master volume level
    UFUNCTION(BlueprintCallable, Category = "Audio")
    void SetMasterVolume(float Volume);

    // Retrieves the sound class of a specified category
    UFUNCTION(BlueprintCallable, Category = "Audio")
    USoundClass* GetSoundCategory(FName CategoryID);

protected:
    // Map of audio components
    UPROPERTY()
    TMap<FName, UAudioComponent*> AudioComponents;

    // Unreal Engine event called at the start of play
    virtual void BeginPlay() override;

    // Unreal Engine event called when play ends
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
