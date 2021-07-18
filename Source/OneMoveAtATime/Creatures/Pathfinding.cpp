// Fill out your copyright notice in the Description page of Project Settings.


#include "Pathfinding.h"

Pathfinding::Pathfinding()
{
}

Pathfinding::~Pathfinding()
{
}

TArray<FIntArray> Pathfinding::CreateAdjacencyMatrix(const TArray<FVector2D> GridBoxes)
{
	TArray<FIntArray> AdjacencnyMatrix;

	for (int i{ 0 }; i < GridBoxes.Num(); i++)
	{
		FIntArray AdjRow;

		for (int j{ 0 }; j < GridBoxes.Num(); j++)
		{

			if (AreBoxesTouching(GridBoxes, GridBoxes[i], GridBoxes[j]))
			{
				AdjRow.IntArray.Push(1);
			}
			else
			{
				AdjRow.IntArray.Push(0);
			}
		}

		AdjacencnyMatrix.Push(AdjRow);
	}

	return AdjacencnyMatrix;
}

bool Pathfinding::AreBoxesTouching(const TArray<FVector2D> Coords, const FVector2D Coord1, const FVector2D Coord2)
{
	FVector2D TraversalVector = Coord2 - Coord1;

	if (
		//VERTICAL AND HORIZONTAL
		Coord1.X == Coord2.X && FMath::Abs(Coord1.Y - Coord2.Y) == 1 ||
		Coord1.Y == Coord2.Y && FMath::Abs(Coord1.X - Coord2.X) == 1 ||
		//DIAGONAL
		(
			FMath::Abs(Coord1.X - Coord2.X) == 1 && FMath::Abs(Coord1.Y - Coord2.Y) == 1
			&& (Coords.Contains(FVector2D(Coord1.X + TraversalVector.X, Coord1.Y))) &&
			(Coords.Contains(FVector2D(Coord1.X, Coord1.Y + TraversalVector.Y)))
		)
		)
	{
		return true;
	}

	return false;
}

TArray<FIntArray> Pathfinding::GetShortestPaths(const TArray<FIntArray> AdjacencyMatrix, int32 StartSpace, int32 EndSpace)
{
	//CONTAINERS
	TArray<FIntArray> PossiblePaths;
	TArray<FIntArray> NewPaths;
	TArray<FIntArray> FinalPaths;
	TArray<int32> VisitedSpaces;
	TArray<int32> NewlyVisitedSpaces;

	//CHECK IF SHOULD STAY STILL
	if (StartSpace == EndSpace)
	{
		StayStill(FinalPaths, StartSpace);
		return FinalPaths;
	}

	//INITIALISE POSSIBLE PATHS
	FIntArray StartSpaceArray;
	StartSpaceArray.IntArray.Push(StartSpace);
	PossiblePaths.Push(StartSpaceArray);

	//FIND SHORTEST PATH
	do
	{		
		for (int i{ 0 }; i < PossiblePaths.Num(); i++)
		{
			for (int j{ 0 }; j < AdjacencyMatrix.Num(); j++)
			{
				if (!VisitedSpaces.Contains(j)
					&& AdjacencyMatrix[PossiblePaths[i].IntArray.Last()].IntArray[j] == 1)

				{
					FIntArray NewPath = PossiblePaths[i];
					NewPath.IntArray.Push(j);

					if (j != EndSpace)
					{
						NewPaths.Push(NewPath);
					}
					else if (j == EndSpace)
					{
						FinalPaths.Push(NewPath);
					}

					if (!NewlyVisitedSpaces.Contains(j))
					{
						NewlyVisitedSpaces.Push(j);
					}
				}
			}
		}

		//NO POSSIBLE PATH
		if (NewPaths.Num() == 0 && FinalPaths.Num() == 0)
		{
			StayStill(FinalPaths, StartSpace);
			return FinalPaths;
		}

		//UPDATE CURRENT PATHS AND GRID SPACES
		PossiblePaths = NewPaths;
		NewPaths.Empty();
		for (int i{ 0 }; i < NewlyVisitedSpaces.Num(); i++)
		{
			VisitedSpaces.Push(NewlyVisitedSpaces[i]);
		}
		NewlyVisitedSpaces.Empty();


	} while (FinalPaths.Num() == 0);

	return FinalPaths;
}

void Pathfinding::StayStill(TArray<FIntArray>& FinalPaths, int StartSpace)
{
	FIntArray StayStill;
	StayStill.IntArray = TArray<int32>{ 0, StartSpace};
	FinalPaths.Push(StayStill);
}
