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

	static TArray<FIntArray> CreateAdjacencyMatrix(const TArray<FVector2D> GridBoxes);
	static bool AreBoxesTouching(const TArray<FVector2D> Coords, const FVector2D Coord1,  const FVector2D Coord2);

	static TArray<FIntArray> GetShortestPaths(const TArray<FIntArray> AdjacencyMatrix, int32 StartNode, int32 EndNode);
	static void StayStill(TArray<FIntArray>& FinalPaths, int StartSpace);

};

