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

	static TArray<FIntArray> CreateAdjacencyMatrix(TArray<FVector2D> GridBoxes);
	static bool AreBoxesTouching(TArray<FVector2D> Coords, FVector2D Coord1, FVector2D Coord2);

	static TArray<FIntArray> GetShortestPaths(TArray<FIntArray> AdjacencyMatrix, int32 StartNode, int32 EndNode);

};

