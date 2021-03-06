// Fill out your copyright notice in the Description page of Project Settings.

#include "Creature.h"

// Sets default values
ACreature::ACreature()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACreature::BeginPlay()
{
	Super::BeginPlay();
	
	PrevGridPos = FVector2D(GetActorLocation().X / MoveSpeed, GetActorLocation().Y / MoveSpeed);
	GridPos = PrevGridPos;
}

// Called every frame
void ACreature::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ACreature::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

AGameGrid* ACreature::GetGameGrid()
{
	if (GameGrid != nullptr)
	{
		return GameGrid;
	}

	else return nullptr;
}

FVector2D ACreature::GetGridPos()
{
	return GridPos;
}

FVector2D ACreature::GetPrevGridPos()
{
	return PrevGridPos;
}

bool ACreature::CanMoveToGridSpace(FVector2D GridSpace)
{
	if (GameGrid != nullptr && GameGrid->IsGridSpaceFree(GridSpace)
		&& !GameGrid->IsGridPathBlocked(GridPos, GridSpace))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ACreature::MoveTo(FVector2D Coord)
{
	if (CanMoveToGridSpace(Coord))
	{
		PrevGridPos = GridPos;
		GridPos = Coord;
		SetActorLocation(FVector(Coord.X * UOMAATGameInstance::GridBoxSize, Coord.Y * UOMAATGameInstance::GridBoxSize, GetActorLocation().Z));
	}
}

void ACreature::MoveUp()
{
	PrevGridPos = GridPos;
	if (CanMoveToGridSpace(GridPos + UpVec))
	{
		GridPos += UpVec;
		SetActorLocation(GetActorLocation() + FVector(UpVec * MoveSpeed, 0));

	}
}

void ACreature::MoveDown()
{
	PrevGridPos = GridPos;
	if (CanMoveToGridSpace(GridPos + DownVec))
	{
		GridPos += DownVec;
		SetActorLocation(GetActorLocation() + FVector(DownVec * MoveSpeed, 0));
		
	}
}

void ACreature::MoveLeft()
{
	PrevGridPos = GridPos;
	if (CanMoveToGridSpace(GridPos + LeftVec))
	{
		GridPos += LeftVec;
		SetActorLocation(GetActorLocation() + FVector(LeftVec * MoveSpeed, 0));
		
	}
}

void ACreature::MoveRight()
{
	PrevGridPos = GridPos;
	if (CanMoveToGridSpace(GridPos + RightVec))
	{
		GridPos += RightVec;
		SetActorLocation(GetActorLocation() + FVector(RightVec * MoveSpeed, 0));
	}
}

