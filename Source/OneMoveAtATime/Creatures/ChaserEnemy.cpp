// Fill out your copyright notice in the Description page of Project Settings.
#define print(TEXT) if(GEngine)GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, TEXT)

#include "ChaserEnemy.h"
#include "Pathfinding.h"
#include "..\OMAATGameInstance.h"

void AChaserEnemy::BeginPlay()
{
	Super::BeginPlay();

	CurrentState = Idle;
	bIsStuck = true;
}

void AChaserEnemy::OnPlayerMove()
{
	switch (CurrentState)
	{
	case Idle:
		SetVisionCoords();
		CheckVision();
		break;

	case Chasing:
		FindPlayer();
		FindPossibleMoves();
		SelectNextMove();
		CheckIfStuck();
		Move();
	}
}

void AChaserEnemy::SetVisionCoords()
{
	if (CurrentState == Idle)
	{
		VisionCoords.Empty();
		VisionCoords.Push(GridPos);

		//GETS COLUMNS AND ROWS
		TArray<FVector2D> DirectionVecs = { UpVec, DownVec, LeftVec, RightVec };
		for (int i{ 0 }; i < DirectionVecs.Num(); i++)
		{
			for (int j{ 1 }; 1 == 1; j++)
			{

				if (GameGrid->IsGridSpaceFree(GridPos + j * DirectionVecs[i]) && !GameGrid->IsGridPathBlocked(GridPos + (j - 1) * DirectionVecs[i], GridPos + j * DirectionVecs[i])
					&& !GameGrid->DoesSpaceContainEnemy(GridPos + j * DirectionVecs[i]))
				{
					VisionCoords.Push(GridPos + j * DirectionVecs[i]);
				}
				else
				{
					break;
				}
			}
		}

		if (GameGrid->IsGridSpaceFree(GridPos + UpVec) && GameGrid->IsGridSpaceFree(GridPos + LeftVec) && GameGrid->IsGridSpaceFree(GridPos + UpVec + LeftVec))
		{
			VisionCoords.Push(GridPos + UpVec + LeftVec);
		}
		if (GameGrid->IsGridSpaceFree(GridPos + UpVec) && GameGrid->IsGridSpaceFree(GridPos + RightVec) && GameGrid->IsGridSpaceFree(GridPos + UpVec + RightVec))
		{
			VisionCoords.Push(GridPos + UpVec + RightVec);
		}
		if (GameGrid->IsGridSpaceFree(GridPos + DownVec) && GameGrid->IsGridSpaceFree(GridPos + LeftVec) && GameGrid->IsGridSpaceFree(GridPos + DownVec + LeftVec))
		{
			VisionCoords.Push(GridPos + DownVec + LeftVec);
		}
		if (GameGrid->IsGridSpaceFree(GridPos + DownVec) && GameGrid->IsGridSpaceFree(GridPos + RightVec) && GameGrid->IsGridSpaceFree(GridPos + DownVec + RightVec))
		{
			VisionCoords.Push(GridPos + DownVec + RightVec);
		}

		CreateVisionSprites();
	}
}

void AChaserEnemy::CheckVision()
{
	for (int i{ 0 }; i < VisionCoords.Num(); i++)
	{
		if (PlayerCharacter->GetGridPos() == VisionCoords[i])
		{
			CurrentState = Chasing;
			OnBeginChase();
		}
	}
}

void AChaserEnemy::FindPlayer()
{
	TargetGridCoord = PlayerCharacter->GetGridPos();
}

void AChaserEnemy::FindPossibleMoves()
{
	CurrentGridIndex = GameGrid->GetAvailableSpaces().Find(GridPos);
	TargetGridIndex = GameGrid->GetAvailableSpaces().Find(PlayerCharacter->GetGridPos());

	TArray<FIntArray> ShortestPaths = Pathfinding::GetShortestPaths(*GameGrid->GetAdjacencyMatrix(), CurrentGridIndex, TargetGridIndex);

	TArray<FVector2D> NextGridCoords;

	for (int i{ 0 }; i < ShortestPaths.Num(); i++)
	{
		FVector2D NextGridCoord = GameGrid->GetAvailableSpaces()[ShortestPaths[i].IntArray[1]];
		NextGridCoords.Push(NextGridCoord);
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
}

void AChaserEnemy::CheckIfStuck()
{
	if (NextMoveGridCoord == GridPos)
	{
		bIsStuck = true;
	}
	else
	{
		bIsStuck = false;
	}
}
 