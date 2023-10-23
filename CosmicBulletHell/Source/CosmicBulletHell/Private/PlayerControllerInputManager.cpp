// Code flows like rivers,
// Antropy's gift to the world,
// Reuse, just cite source.



#include "PlayerControllerInputManager.h"
#include "Engine/Engine.h"  // For accessing the engine's input system
#include "GameFramework/PlayerController.h"  // For accessing the player controller

APlayerControllerInputManager::APlayerControllerInputManager()
{
    // Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    // Initialize properties
    PlayerInputComponent = CreateDefaultSubobject<UInputComponent>(TEXT("PlayerInputComponent"));
    bIsInputInitialized = false;
    LastInputTimeStamp = 0.0f;
}

void APlayerControllerInputManager::InitializeInput()
{
    if(PlayerInputComponent)
    {
        // Bind input actions to their respective handlers.
        BindInputActions();
        bIsInputInitialized = true;
    }
}

void APlayerControllerInputManager::ProcessInput(float DeltaTime)
{
    if(bIsInputInitialized)
    {
        // Update the time stamp of the last input event processed.
        UpdateLastInputTimeStamp(GetWorld()->GetTimeSeconds());
    }
}

void APlayerControllerInputManager::BindInputActions()
{
    if(PlayerInputComponent)
    {
        // Assume that there are input actions defined named "Jump" and "Fire"
        PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APlayerControllerInputManager::HandleJump);
        PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APlayerControllerInputManager::HandleFire);
    }
}

void APlayerControllerInputManager::UpdateLastInputTimeStamp(float TimeStamp)
{
    LastInputTimeStamp = TimeStamp;
}

void APlayerControllerInputManager::HandleJump()
{
    // Assume logic to handle jump input here...
}

void APlayerControllerInputManager::HandleFire()
{
    // Assume logic to handle fire input here...
}

// Called when the game starts or when spawned
void APlayerControllerInputManager::BeginPlay()
{
    Super::BeginPlay();
    
    // Optionally, initialize input in BeginPlay
    InitializeInput();
}

// Called every frame
void APlayerControllerInputManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Optionally, process input every frame
    ProcessInput(DeltaTime);
}
