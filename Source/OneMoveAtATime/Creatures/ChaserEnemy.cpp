// Fill out your copyright notice in the Description page of Project Settings.
#define print(TEXT) if(GEngine)GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, TEXT)

#include "ChaserEnemy.h"
#include "Pathfinding.h"
#include "..\OMAATGameInstance.h"

void AChaserEnemy::BeginPlay()
{
	Super::BeginPlay();

	
}

void AChaserEnemy::OnPlayerMove()
{
	FindPlayer();
	FindPossibleMoves();
	SelectNextMove();
	Move();
}

void AChaserEnemy::FindPlayer()
{
	TargetGridCoord = PlayerCharacter->GetGridPos();
	TargetGridIndex = GameGrid->GetGridIndex(TargetGridCoord);
}

void AChaserEnemy::FindPossibleMoves()
{
	CurrentGridIndex = GameGrid->GetGridIndex(this->GridPos);
	TargetGridIndex = GameGrid->GetGridIndex(PlayerCharacter->GetGridPos());

	TArray<FIntArray> ShortestPaths = Pathfinding::GetShortestPaths(*GameGrid->GetAdjacencyMatrix(), CurrentGridIndex, TargetGridIndex);

	TArray<FVector2D> NextGridCoords;

	for (int i{ 0 }; i < ShortestPaths.Num(); i++)
	{
		NextGridCoords.Push(GameGrid->GetGridCoords(ShortestPaths[i].IntArray[1]));
	}

	PossibleMoves = NextGridCoords;
}

void  AChaserEnemy::SelectNextMove()
{
	FVector2D OptimalChoice = PossibleMoves[0];
	int32 CurrentMinimum = FMath::Abs(TargetGridCoord.X - OptimalChoice.X) + FMath::Abs(TargetGridCoord.Y - OptimalChoice.Y);

	if (PossibleMoves.Num() > 1)
	{
		for (int i{ 1 }; i < PossibleMoves.Num(); i++)
		{
			int32 DistanceFromTarget = FMath::Abs(TargetGridCoord.X - PossibleMoves[i].X) + FMath::Abs(TargetGridCoord.Y - PossibleMoves[i].Y);
			if (DistanceFromTarget < CurrentMinimum)
			{
				OptimalChoice = PossibleMoves[i];
				CurrentMinimum = DistanceFromTarget;
			}
		}
	}

	NextMoveGridCoord = OptimalChoice;
}

void AChaserEnemy::Move()
{
	PrevGridPos = GridPos;
	SetActorLocation(FVector((NextMoveGridCoord * MoveSpeed), GetActorLocation().Z));
	GridPos = FVector2D(GetActorLocation().X / 100, GetActorLocation().Y / 100);
	CurrentGridIndex = GameGrid->GetGridIndex(GridPos);
}
 