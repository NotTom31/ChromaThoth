    // Code flows like rivers,
    // Antropy's gift to the world,
    // Reuse, just cite source.

    // Code generated for the APlayerControllerInputManager class to manage
    // Keyboard, Gamepad, and Touch screen input events within an Unreal Engine game project.

    #pragma once

    #include "CoreMinimal.h"
    #include "GameFramework/Actor.h"
    #include "Components/InputComponent.h"
    #include "PlayerControllerInputManager.generated.h"

    /**
     * A class responsible for managing Keyboard, Gamepad, and Touch screen input events within an Unreal Engine game project.
     */
    UCLASS(BlueprintSpawnableComponent)
    class YOURGAME_API APlayerControllerInputManager : public AActor
    {
        GENERATED_BODY()

    public:
        // Constructor
        APlayerControllerInputManager();

        // The input component associated with the player controller.
        UPROPERTY(BlueprintReadWrite, Category = "Input")
        UInputComponent* PlayerInputComponent;

        // Initializes input handling for Keyboard, Gamepad, and Touch screen.
        UFUNCTION(BlueprintCallable, Category = "Input")
        void InitializeInput();

        // Processes input events every frame.
        UFUNCTION(BlueprintCallable, Category = "Input")
        void ProcessInput(float DeltaTime);

        // Binds input actions and axes for Keyboard, Gamepad, and Touch screen.
        void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent);

    protected:
        // Binds actions for Keyboard, Gamepad, and Touch screen to their respective handlers.
        UFUNCTION(BlueprintCallable, Category = "Input")
        void BindInputActions();
    };

