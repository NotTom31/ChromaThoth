#include "HelperFunctions.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Engine/Engine.h"

float UHelperFunctions::ClampValue(float Value, float MinValue, float MaxValue)
{
    return FMath::Clamp(Value, MinValue, MaxValue);
}

FText UHelperFunctions::FormatFloatingCombatText(float DamageValue)
{
    // Assuming you want the damage value to be rounded to the nearest whole number
    int32 RoundedDamage = FMath::RoundToInt(DamageValue);
    return FText::AsNumber(RoundedDamage);
}

FKey UHelperFunctions::InputMapping(FKey KeyInput)
{
    // Placeholder logic, you would replace this with actual input mapping logic
    return KeyInput;
}

bool UHelperFunctions::IsTouchscreenDevice()
{
    // Example logic to determine if the platform supports touch
    EPlatformCategory PlatformCategory = UDeviceProfileManager::Get().GetActiveProfile()->GetPlatformCategory();
    return PlatformCategory == EPlatformCategory::Mobile;
}

void UHelperFunctions::ApplySlateStyle(const FUIManagerStyle& UIManagerStyle)
{
    // Placeholder, replace with logic to apply the Slate style
}

AActor* UHelperFunctions::SpawnProjectile(TSubclassOf<AActor> ProjectileClass, FVector SpawnLocation, FRotator SpawnRotation)
{
    if (ProjectileClass == nullptr)
    {
        UE_LOG(LogTemp, Warning, TEXT("UHelperFunctions::SpawnProjectile - ProjectileClass is null"));
        return nullptr;
    }

    UWorld* World = GetWorld();
    if (World == nullptr)
    {
        UE_LOG(LogTemp, Warning, TEXT("UHelperFunctions::SpawnProjectile - World is null"));
        return nullptr;
    }

    FActorSpawnParameters SpawnParams;
    AActor* SpawnedActor = World->SpawnActor<AActor>(ProjectileClass, SpawnLocation, SpawnRotation, SpawnParams);
    return SpawnedActor;
}

AActor* UHelperFunctions::GetActorUnderMouse(APlayerController* PlayerController)
{
    if (PlayerController == nullptr)
    {
        UE_LOG(LogTemp, Warning, TEXT("UHelperFunctions::GetActorUnderMouse - PlayerController is null"));
        return nullptr;
    }

    FHitResult HitResult;
    PlayerController->GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, true, HitResult);
    return HitResult.GetActor();
}

void UHelperFunctions::PlaySceneAudio(USoundBase* AudioAsset, float VolumeMultiplier)
{
    if (AudioAsset == nullptr)
    {
        UE_LOG(LogTemp, Warning, TEXT("UHelperFunctions::PlaySceneAudio - AudioAsset is null"));
        return;
    }

    UGameplayStatics::PlaySound2D(GetWorld(), AudioAsset, VolumeMultiplier);
}

UHelperFunctions::FOnHealthValueChanged UHelperFunctions::OnHealthValueChanged;
