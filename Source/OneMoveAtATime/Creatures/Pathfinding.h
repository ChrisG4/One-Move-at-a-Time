// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Pathfinding.generated.h"

USTRUCT()
struct FIntArray
{
	GENERATED_BODY()
public:
	TArray<int32> IntArray;
};

class ONEMOVEATATIME_API Pathfinding
{
public:
	Pathfinding();
	~Pathfinding();

	TArray<FIntArray> CreateAdjacencyMatrix(TArray<FVector2D> GridBoxes);
	bool AreBoxesTouching(FVector2D Coord1, FVector2D Coord2);

	TArray<FIntArray> GetShortestPaths(TArray<FIntArray> AdjacencyMatrix, int32 StartNode, int32 EndNode);

};

