// Fill out your copyright notice in the Description page of Project Settings.
#define print(TEXT) if(GEngine)GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, TEXT)

#include "ChaserEnemy.h"
#include "Pathfinding.h"

void AChaserEnemy::OnPlayerMove()
{
	PrevGridPos = GridPos;
	
	int32 CurrentGridIndex = GameGrid->GetGridIndex(this->GridPos);
	int32 TargetGridIndex = GameGrid->GetGridIndex(PlayerCharacter->GetGridPos());

	TArray<FIntArray> ShortestPaths = Pathfinding::GetShortestPaths(*GameGrid->GetAdjacencyMatrix(), CurrentGridIndex, TargetGridIndex);

	int32 NextGridIndex = ShortestPaths[0].IntArray[1];

	FVector2D GridSpaceToMoveTo = GameGrid->GetGridCoords(NextGridIndex);

	SetActorLocation(FVector(GridSpaceToMoveTo * 100, 0));
	GridPos = FVector2D(GetActorLocation().X / 100, GetActorLocation().Y / 100);

}
