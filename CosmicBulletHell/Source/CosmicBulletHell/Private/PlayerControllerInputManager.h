    // Code flows like rivers,
    // Antropy's gift to the world,
    // Reuse, just cite source.

    #pragma once

    #include "CoreMinimal.h"
    #include "GameFramework/Actor.h"
    #include "Components/InputComponent.h"
    #include "PlayerControllerInputManager.generated.h"

    /**
     * A class responsible for managing player controller input events and behaviors within an Unreal Engine game project.
     */
    UCLASS(BlueprintSpawnableComponent)
    class YOURGAME_API APlayerControllerInputManager : public AActor
    {
        GENERATED_BODY()

    public:
        // Constructor
        APlayerControllerInputManager();

        // Destructor
        virtual ~APlayerControllerInputManager();

        // Pointer to the input component associated with the player controller.
        UPROPERTY(BlueprintReadWrite, Category = "Input")
        UInputComponent* PlayerInputComponent;

        // Initializes input for the player controller.
        UFUNCTION(BlueprintCallable, Category = "Input")
        void InitializeInput();

        // Processes player input events.
        UFUNCTION(BlueprintCallable, Category = "Input")
        void ProcessInput(float DeltaTime);

    protected:
        // Flag to check if input has been initialized.
        UPROPERTY(BlueprintReadOnly, Category = "Input")
        bool bIsInputInitialized;

        // Binds input actions to their respective handlers.
        UFUNCTION(BlueprintCallable, Category = "Input")
        void BindInputActions();

    private:
        // Time stamp of the last input event processed.
        float LastInputTimeStamp;

        // Updates the time stamp of the last input event processed.
        void UpdateLastInputTimeStamp(float TimeStamp);

        // Handles the Jump action.
        UFUNCTION()
        void HandleJump();

        // Handles the Fire action.
        UFUNCTION()
        void HandleFire();

    public:
        // Called when the game starts or when spawned
        virtual void BeginPlay() override;

        // Called every frame
        virtual void Tick(float DeltaTime) override;

        // Called to bind functionality to input
        virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    };
