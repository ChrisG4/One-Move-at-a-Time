// Fill out your copyright notice in the Description page of Project Settings.


#include "PatrolEnemy.h"

void APatrolEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	CurrentMoveDirection = InitialMoveDirection;
}

void APatrolEnemy::UpdateMoveDirection()
{
	switch (CurrentMoveDirection)
	{
	case Up:
		if (!GameGrid->IsGridSpaceFree(GridPos + FVector2D(0, -1)))
		{
			CurrentMoveDirection = Down;
		}
		break;
	case Down:
		if (!GameGrid->IsGridSpaceFree(GridPos + FVector2D(0, 1)))
		{
			CurrentMoveDirection = Up;
		}
		break;
	case Left:
		if (!GameGrid->IsGridSpaceFree(GridPos + FVector2D(-1, 0)))
		{
			CurrentMoveDirection = Right;
		}
		break;
	case Right:
		if (!GameGrid->IsGridSpaceFree(GridPos + FVector2D(1, 0)))
		{
			CurrentMoveDirection = Left;
		}
		break;
	default:
		break;
	}
}

void APatrolEnemy::OnPlayerMove()
{
	UpdateMoveDirection();

	switch (CurrentMoveDirection)
	{
	case Up:
		MoveUp();
		break;
	case Down:
		MoveDown();
		break;
	case Left:
		MoveLeft();
		break;
	case Right:
		MoveRight();
		break;
	default:
		break;
	}
}
