// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "GridBox.h"
#include "..\Creatures/Pathfinding.h"
#include "..\LevelObjects/Door.h"
#include "..\LevelObjects/Crate.h"
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
	TArray<FVector2D> AvailableSpaces;

	TArray<FIntArray> AdjacencyMatrix;

	UPROPERTY(BlueprintReadWrite)
	TArray<ADoor*> Doors;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	TArray<ACrate*> Crates;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SpawnGridBoxes();

	bool IsGridSpaceFree(FVector2D GridCoord);
	bool IsGridPathBlocked(FVector2D Coord1, FVector2D Coor2);

	UFUNCTION(BlueprintCallable)
	void CreateAdjacencyMatrix();
	void UpdateAdjacenyMatrix();
	TArray<FIntArray>* GetAdjacencyMatrix();

	TArray<FVector2D> GetAvailableSpaces();

	AGridBox* GetGridBox(FVector2D GridCoord);
	FVector2D GetGridCoords(int32 GridIndex);
	int32 GetGridIndex(FVector2D GridCoord);

};
