// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "GridBox.h"
#include "..\Creatures/Pathfinding.h"
#include "GameGrid.generated.h"

UCLASS()
class ONEMOVEATATIME_API AGameGrid : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameGrid();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGridBox> GridBoxType;

	UPROPERTY(EditAnywhere, meta = (MakeEditWidget = "true"))
	TArray<FVector> GridBoxPositions;

	UPROPERTY()
	TMap<FVector2D, AGridBox*> GridBoxes;

	TMap<FVector2D, int32> GridIndexes;

	TArray<FVector2D> GridCoords;

	TArray<FIntArray> AdjacencyMatrix;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SpawnGridBoxes();

	bool IsGridSpaceFree(FVector2D GridCoord);

	TArray<FIntArray>* GetAdjacencyMatrix();

	FVector2D GetGridCoords(int32 GridIndex);
	int32 GetGridIndex(FVector2D GridCoord);

};
