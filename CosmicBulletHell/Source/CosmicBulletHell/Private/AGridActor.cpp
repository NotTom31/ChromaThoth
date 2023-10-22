// GridActor.cpp
#include "GridActor.h"

AGridActor::AGridActor()
{
    // Set this actor to call Tick() every frame
    PrimaryActorTick.bCanEverTick = true;

    // Create the root component
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

    // Create the grid visualization mesh
    GridMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GridMesh"));
    GridMesh->SetupAttachment(RootComponent);

    // Set default values
    GridWidth = 10;
    GridHeight = 10;
    CellSize = 100.0f;

    // Initialize the visualization mesh
    // You need to create a simple grid mesh (a plane) and set it as the static mesh of GridMesh
    // In Unreal, this mesh can be created in the Editor or programmatically loaded and assigned
    // Refer to Unreal Engine documentation for details on setting up a mesh.

    // Set the scale of the grid based on cell size and dimensions
    FVector GridScale(GridWidth * CellSize, GridHeight * CellSize, 1.0f);
    GridMesh->SetWorldScale3D(GridScale);
}

void AGridActor::BeginPlay()
{
    Super::BeginPlay();
}

void AGridActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
