// Fill out your copyright notice in the Description page of Project Settings.


#include "GameGrid.h"

// Sets default values
AGameGrid::AGameGrid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGameGrid::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnGridBoxes();

	AdjacencyMatrix = Pathfinding::CreateAdjacencyMatrix(GridCoords);
}

// Called every frame
void AGameGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGameGrid::SpawnGridBoxes()
{
	if (GridBoxType != nullptr && GridBoxPositions.Num() > 0) {
		for (int i{ 0 }; i < GridBoxPositions.Num(); i++)
		{
			AGridBox* NewBox = GetWorld()->SpawnActor<AGridBox>(GridBoxType, GridBoxPositions[i] + GetActorLocation(), FRotator(0, 0, 0));
			GridBoxes.Add(NewBox->GetGridCoord(), NewBox);
			GridIndexes.Add(NewBox->GetGridCoord(), i);
			GridCoords.Add(NewBox->GetGridCoord());
		}
	}
}

bool AGameGrid::IsGridSpaceFree(FVector2D GridCoord)
{
	if (GridBoxes.Contains(GridCoord))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool AGameGrid::IsGridPathBlocked(FVector2D Coord1, FVector2D Coord2)
{
	TArray<FVector2D> CoordsToCheck1{ Coord1, Coord2 };
	TArray<FVector2D> CoordsToCheck2{ Coord2, Coord1 };

	for (int i{ 0 }; i < Doors.Num(); i++)
	{
		if (Doors[i]->GetIsActive()
			&& (CoordsToCheck1 == Doors[i]->GetGridBoxCoords() || CoordsToCheck2 == Doors[i]->GetGridBoxCoords()))
		{
			return true;
		}
	}

	return false;
}

TArray<FIntArray>* AGameGrid::GetAdjacencyMatrix()
{
	return &AdjacencyMatrix;
}

int32 AGameGrid::GetGridIndex(FVector2D GridCoord)
{
	if (GridIndexes.Contains(GridCoord))
	{
		return GridIndexes[GridCoord];
	}
	else
	{
		return 0;
	}
}

FVector2D AGameGrid::GetGridCoords(int32 GridIndex)
{
	return GridCoords[GridIndex];
}
