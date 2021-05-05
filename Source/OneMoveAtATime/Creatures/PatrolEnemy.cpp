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
		if (!CanMoveToGridSpace(GridPos + UpVec))
		{
			CurrentMoveDirection = Down;
		}
		break;
	case Down:
		if (!CanMoveToGridSpace(GridPos + DownVec))
		{
			CurrentMoveDirection = Up;
		}
		break;
	case Left:
		if (!CanMoveToGridSpace(GridPos + LeftVec))
		{
			CurrentMoveDirection = Right;
		}
		break;
	case Right:
		if (!CanMoveToGridSpace(GridPos + RightVec))
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
		if (!CanMoveToGridSpace(GridPos + UpVec) && !CanMoveToGridSpace(GridPos + DownVec))
		{
			bIsStuck = true;
			return;
		}
	}
	
	if (CurrentMoveDirection == Left || CurrentMoveDirection == Right)
	{
		if (!CanMoveToGridSpace(GridPos + LeftVec) && !CanMoveToGridSpace(GridPos + RightVec))
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

	CheckIfStuck();
}

void APatrolEnemy::OnTeleport(Direction NewDirection)
{
	CurrentMoveDirection = NewDirection;
}
