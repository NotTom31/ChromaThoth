#include "UIHealthComponent.h"
#include "Blueprint/WidgetBlueprintLibrary.h"  // For Create Widget
#include "YourGameHealthBarWidget.h"  // Assume you have a UUserWidget derived class for health bar
#include "YourGameHealthTextWidget.h"  // Assume you have a UUserWidget derived class for health text

UUIHealthComponent::UUIHealthComponent()
{
    // Set default values
    bIsHealthDisplayInitialized = false;
    ActorHealthManagerRef = nullptr;
    HealthBarWidget = nullptr;
    HealthTextWidget = nullptr;
    // Set default styles for HealthBarStyle and HealthTextStyle if needed
}

void UUIHealthComponent::UpdateHealthDisplay()
{
    if(bIsHealthDisplayInitialized && ActorHealthManagerRef)
    {
        float CurrentHealth = ActorHealthManagerRef->GetCurrentHealth();
        float MaxHealth = ActorHealthManagerRef->GetMaxHealth();
        
        // Assume these methods exist on your HealthBar and HealthText widgets
        if(HealthBarWidget)
        {
            Cast<UYourGameHealthBarWidget>(HealthBarWidget)->SetHealthPercentage(CurrentHealth / MaxHealth);
        }
        if(HealthTextWidget)
        {
            Cast<UYourGameHealthTextWidget>(HealthTextWidget)->SetHealthText(FText::Format(TEXT("{0} / {1}"), CurrentHealth, MaxHealth));
        }
    }
}

void UUIHealthComponent::SetupHealthManagerReference(AActorHealthManager* HealthManager)
{
    if(HealthManager)
    {
        ActorHealthManagerRef = HealthManager;
    }
}

void UUIHealthComponent::CreateHealthBar()
{
    if(!HealthBarWidget)
    {
        HealthBarWidget = CreateWidget<UUserWidget>(GetWorld(), UYourGameHealthBarWidget::StaticClass());
        if(HealthBarWidget)
        {
            HealthBarWidget->AddToViewport();
        }
    }
}

void UUIHealthComponent::CreateHealthText()
{
    if(!HealthTextWidget)
    {
        HealthTextWidget = CreateWidget<UUserWidget>(GetWorld(), UYourGameHealthTextWidget::StaticClass());
        if(HealthTextWidget)
        {
            HealthTextWidget->AddToViewport();
        }
    }
}

void UUIHealthComponent::InitializeHealthDisplay()
{
    CreateHealthBar();
    CreateHealthText();
    bIsHealthDisplayInitialized = true;
}

void UUIHealthComponent::BeginPlay()
{
    Super::BeginPlay();
    
    if(!bIsHealthDisplayInitialized)
    {
        InitializeHealthDisplay();
    }
}

void UUIHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    
    if(bIsHealthDisplayInitialized)
    {
        UpdateHealthDisplay();
    }
}
