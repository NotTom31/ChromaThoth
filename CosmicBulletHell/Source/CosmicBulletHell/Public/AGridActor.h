#pragma once

#include "GameFramework/Actor.h"
#include "GridActor.generated.h"

UCLASS()
class MYPROJECT_API AGridActor : public AActor
{
    GENERATED_BODY()

public:
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
