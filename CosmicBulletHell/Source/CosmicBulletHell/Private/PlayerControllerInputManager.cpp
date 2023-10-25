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

    // Create a new InputComponent instance
    PlayerInputComponent = CreateDefaultSubobject<UInputComponent>(TEXT("PlayerInputComponent"));
}

void APlayerControllerInputManager::InitializeInput()
{
    if(PlayerInputComponent)
    {
        // Bind input actions and axes
        SetupPlayerInputComponent(PlayerInputComponent);
    }
}

void APlayerControllerInputManager::ProcessInput(float DeltaTime)
{
    // Implement the logic to process input events.
    // This could include querying the state of PlayerInputComponent,
    // and responding to input events accordingly.
    // Example: Check if the "Jump" action is pressed
    if (PlayerInputComponent->WasJustPressed(EKeys::SpaceBar))
    {
        // Handle jump logic here
        HandleJump();
    }
}

void APlayerControllerInputManager::SetupPlayerInputComponent(UInputComponent* PlayerInputComp)
{
    PlayerInputComponent = PlayerInputComp;
    
    // Ensure PlayerInputComponent is valid before proceeding
    if(PlayerInputComponent)
    {
        BindInputActions();
    }
}

void APlayerControllerInputManager::BindInputActions()
{
    // Bind the Jump and Fire actions, and the MoveForward axis
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APlayerControllerInputManager::HandleJump);
    PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APlayerControllerInputManager::HandleFire);
    PlayerInputComponent->BindAxis("MoveForward", this, &APlayerControllerInputManager::HandleMoveForward);
}

void APlayerControllerInputManager::HandleJump()
{
    // Implement your jump logic here
    UE_LOG(LogTemp, Warning, TEXT("Jump action triggered"));
}

void APlayerControllerInputManager::HandleFire()
{
    // Implement your fire logic here
    UE_LOG(LogTemp, Warning, TEXT("Fire action triggered"));
}

void APlayerControllerInputManager::HandleMoveForward(float Value)
{
    // Implement your move forward logic here
    // Value will be in the range -1.0 to 1.0
    UE_LOG(LogTemp, Warning, TEXT("MoveForward axis value: %f"), Value);
}
