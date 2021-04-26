// Fill out your copyright notice in the Description page of Project Settings.


#include "Pathfinding.h"

Pathfinding::Pathfinding()
{
}

Pathfinding::~Pathfinding()
{
}

TArray<FIntArray> Pathfinding::CreateAdjacencyMatrix(TArray<FVector2D> GridBoxes)
{
	TArray<FIntArray> AdjacencnyMatrix;

	for (int i{ 0 }; i < GridBoxes.Num(); i++)
	{
		FIntArray AdjRow;

		for (int j{ 0 }; j < GridBoxes.Num(); j++)
		{

			if (AreBoxesTouching(GridBoxes[i], GridBoxes[j]))
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

bool Pathfinding::AreBoxesTouching(FVector2D Coord1, FVector2D Coord2)
{
	//VERTICAL AND HORIZONTAL
	if (
		Coord1.X == Coord2.X && FMath::Abs(Coord1.Y - Coord2.Y) == 1 ||
		Coord1.Y == Coord2.Y && FMath::Abs(Coord1.X - Coord2.X) == 1
		)
	{
		return true;
	}

	return false;
}

TArray<FIntArray> Pathfinding::GetShortestPaths(TArray<FIntArray> AdjacencyMatrix, int32 StartSpace, int32 EndSpace)
{
	TArray<FIntArray> PossiblePaths;
	TArray<FIntArray> NewPaths;
	TArray<FIntArray> FinalPaths;
	TArray<int32> VisitedSpaces;
	TArray<int32> NewlyVisitedSpaces;

	FIntArray StartSpaceArray;
	StartSpaceArray.IntArray.Push(StartSpace);
	PossiblePaths.Push(StartSpaceArray);

	if (StartSpace == EndSpace)
	{
		FIntArray StayStill;
		StayStill.IntArray.Push(StartSpace);
		StayStill.IntArray.Push(StartSpace);
		FinalPaths.Push(StayStill);
		goto StayStill;
	}


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
		//UPDATE POSSIBLE PATHS
		PossiblePaths = NewPaths;
		//UPDATE VISITED NODES
		for (int i{ 0 }; i < NewlyVisitedSpaces.Num(); i++)
		{
			VisitedSpaces.Push(NewlyVisitedSpaces[i]);
		}


	} while (FinalPaths.Num() == 0);

StayStill:;

	return FinalPaths;
}