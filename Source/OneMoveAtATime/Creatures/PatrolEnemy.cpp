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
		if (!CanMoveToGridSpace(GridPos + FVector2D(0, -1)))
		{
			CurrentMoveDirection = Down;
		}
		break;
	case Down:
		if (!CanMoveToGridSpace(GridPos + FVector2D(0, 1)))
		{
			CurrentMoveDirection = Up;
		}
		break;
	case Left:
		if (!CanMoveToGridSpace(GridPos + FVector2D(-1, 0)))
		{
			CurrentMoveDirection = Right;
		}
		break;
	case Right:
		if (!CanMoveToGridSpace(GridPos + FVector2D(1, 0)))
		{
			CurrentMoveDirection = Left;
		}
		break;
	default:
		break;
	}
}

void APatrolEnemy::CheckIfStuck()
{
	if (CurrentMoveDirection == Up || CurrentMoveDirection == Down)
	{
		if (!CanMoveToGridSpace(GridPos + FVector2D(0, -1)) && !CanMoveToGridSpace(GridPos + FVector2D(0, 1)))
		{
			bIsStuck = true;
			return;
		}
	}
	
	if (CurrentMoveDirection == Left || CurrentMoveDirection == Right)
	{
		if (!CanMoveToGridSpace(GridPos + FVector2D(-1, 0)) && !CanMoveToGridSpace(GridPos + FVector2D(1, 0)))
		{
			bIsStuck = true;
			return;
		}
	}

	bIsStuck = false;
}

void APatrolEnemy::OnPlayerMove()
{
	UpdateMoveDirection();
	CheckIfStuck();

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
