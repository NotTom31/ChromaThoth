#include "SceneAudioManager.h"
#include "Kismet/GameplayStatics.h"  // For UGameplayStatics::SpawnSoundAttached

ASceneAudioManager::ASceneAudioManager()
{
    // Set this actor to call Tick() every frame.
    PrimaryActorTick.bCanEverTick = false;  // Set to true if needed

    // Set default values
    MasterVolume = 1.0f;
}

void ASceneAudioManager::BeginPlay()
{
    Super::BeginPlay();

    // Start background music
    if (BackgroundMusic)
    {
        PlaySound("BackgroundMusic");
    }
}

void ASceneAudioManager::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    Super::EndPlay(EndPlayReason);

    // Stop all sounds
    for (auto& AudioCompPair : AudioComponents)
    {
        UAudioComponent* AudioComp = AudioCompPair.Value;
        if (AudioComp && AudioComp->IsPlaying())
        {
            AudioComp->Stop();
        }
    }
    AudioComponents.Empty();
}

bool ASceneAudioManager::PlaySound(FName SoundID)
{
    USoundBase* SoundToPlay = nullptr;

    // Check if sound is background music
    if (SoundID == "BackgroundMusic")
    {
        SoundToPlay = BackgroundMusic;
    }
    else
    {
        // Fetch sound from ambient sounds map
        SoundToPlay = AmbientSounds.FindRef(SoundID);
    }

    if (SoundToPlay)
    {
        UAudioComponent* AudioComp = UGameplayStatics::SpawnSoundAttached(
            SoundToPlay,
            GetRootComponent(),
            SoundID,
            FVector::ZeroVector,
            EAttachLocation::KeepRelativeOffset,
            true,
            MasterVolume
        );

        if (AudioComp)
        {
            AudioComponents.Add(SoundID, AudioComp);
            return true;
        }
    }
    return false;
}

bool ASceneAudioManager::StopSound(FName SoundID)
{
    UAudioComponent** AudioCompPtr = AudioComponents.Find(SoundID);

    if (AudioCompPtr && *AudioCompPtr && (*AudioCompPtr)->IsPlaying())
    {
        (*AudioCompPtr)->Stop();
        AudioComponents.Remove(SoundID);
        return true;
    }
    return false;
}

void ASceneAudioManager::SetMasterVolume(float Volume)
{
    MasterVolume = FMath::Clamp(Volume, 0.0f, 1.0f);

    for (auto& AudioCompPair : AudioComponents)
    {
        UAudioComponent* AudioComp = AudioCompPair.Value;
        if (AudioComp)
        {
            AudioComp->SetVolumeMultiplier(MasterVolume);
        }
    }
}

USoundClass* ASceneAudioManager::GetSoundCategory(FName CategoryID)
{
    return SoundCategories.FindRef(CategoryID);
}
