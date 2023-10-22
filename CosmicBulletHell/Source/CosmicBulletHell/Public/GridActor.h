// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GridActor.generated.h"

UCLASS()
class COSMICBULLETHELL_API AGridActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGridActor();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, Category = "Grid Settings")
    int32 GridWidth;

    UPROPERTY(EditAnywhere, Category = "Grid Settings")
    int32 GridHeight;

    UPROPERTY(EditAnywhere, Category = "Grid Settings")
    float CellSize;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Grid Visualization")
    UStaticMeshComponent* GridMesh;

};
