// Fill out your copyright notice in the Description page of Project Settings.


#include "GridActor.h"

AGridActor::AGridActor()
{
    // Set this actor to call Tick() every frame
    PrimaryActorTick.bCanEverTick = true;

    // Create the root component
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    // Assuming "MyGridMesh" is the name of the mesh asset you imported
	/*static ConstructorHelpers::FObjectFinder<UStaticMesh> GridMeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/StaticMesh.StaticMesh'"));
	if (GridMeshAsset.Succeeded())
	{
		GridMesh->SetStaticMesh(GridMeshAsset.Object);
	}*/

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

