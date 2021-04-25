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
	
	GridPos = FVector2D(GetActorLocation().X/MoveSpeed, GetActorLocation().Y/MoveSpeed);
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

void ACreature::MoveUp()
{
	FVector2D UpVec = FVector2D(0, -1);
	if (GameGrid != nullptr && GameGrid->IsGridSpaceFree(GridPos + UpVec))
	{
		SetActorLocation(GetActorLocation() + FVector(UpVec * MoveSpeed, 0));
		GridPos += UpVec;
	}
}

void ACreature::MoveDown()
{
	FVector2D DownVec = FVector2D(0, 1);
	if (GameGrid != nullptr && GameGrid->IsGridSpaceFree(GridPos + DownVec))
	{
		SetActorLocation(GetActorLocation() + FVector(DownVec * MoveSpeed, 0));
		GridPos += DownVec;
	}
}

void ACreature::MoveLeft()
{
	FVector2D LeftVec = FVector2D(-1, 0);
	if (GameGrid != nullptr && GameGrid->IsGridSpaceFree(GridPos + LeftVec))
	{
		SetActorLocation(GetActorLocation() + FVector(LeftVec * MoveSpeed, 0));
		GridPos += LeftVec;
	}
}

void ACreature::MoveRight()
{
	FVector2D RightVec = FVector2D(1, 0);
	if (GameGrid != nullptr && GameGrid->IsGridSpaceFree(GridPos + RightVec))
	{
		SetActorLocation(GetActorLocation() + FVector(RightVec * MoveSpeed, 0));
		GridPos += RightVec;
	}
}

