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
			FActorSpawnParameters Params;
			Params.Owner = this;
			
			AGridBox* NewBox = GetWorld()->SpawnActor<AGridBox>(GridBoxType, GridBoxPositions[i] + GetActorLocation(), FRotator(0, 0, 0), Params);
			GridBoxes.Add(NewBox->GetGridCoord(), NewBox);
			GridCoords.Add(NewBox->GetGridCoord());
		}
	}
}

bool AGameGrid::IsGridSpaceFree(FVector2D GridCoord)
{
	if (GridBoxes.Contains(GridCoord) && !GridBoxes[GridCoord]->DoesContainCrate())
	{
		return true;
	}

	return false;
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

void AGameGrid::CreateAdjacencyMatrix()
{
	AvailableSpaces.Empty();
	for (int i{ 0 }; i < GridCoords.Num(); i++)
	{
		if (!GridBoxes[GridCoords[i]]->DoesContainCrate())
		{
			AvailableSpaces.Push(GridCoords[i]);
		}
	}
	
	AdjacencyMatrix = Pathfinding::CreateAdjacencyMatrix(AvailableSpaces);
	UpdateAdjacenyMatrix();
}

void AGameGrid::UpdateAdjacenyMatrix()
{
	if (Doors.Num() > 0) {
		for (int i{ 0 }; i < Doors.Num(); i++)
		{
			if (Doors[i]->GetGridBoxCoords().Num() > 0) {
				TArray<FVector2D> Coords = Doors[i]->GetGridBoxCoords();
				int32 Coord1Index = AvailableSpaces.Find(Coords[0]);
				int32 Coord2Index = AvailableSpaces.Find(Coords[1]);

				if (Doors[i]->GetIsActive())
				{
					AdjacencyMatrix[Coord1Index].IntArray[Coord2Index] = 0;
					AdjacencyMatrix[Coord2Index].IntArray[Coord1Index] = 0;
				}
				else
				{
					AdjacencyMatrix[Coord1Index].IntArray[Coord2Index] = 1;
					AdjacencyMatrix[Coord2Index].IntArray[Coord1Index] = 1;
				}
			}
		}
	}
}

TArray<FIntArray>* AGameGrid::GetAdjacencyMatrix()
{
	return &AdjacencyMatrix;
}

TArray<FVector2D> AGameGrid::GetAvailableSpaces()
{
	return AvailableSpaces;
}

AGridBox* AGameGrid::GetGridBox(FVector2D GridCoord)
{
	if (GridBoxes.Contains(GridCoord))
	{
		return GridBoxes[GridCoord];
	}

	return nullptr;
}


FVector2D AGameGrid::GetGridCoords(int32 GridIndex)
{
	return GridCoords[GridIndex];
}
