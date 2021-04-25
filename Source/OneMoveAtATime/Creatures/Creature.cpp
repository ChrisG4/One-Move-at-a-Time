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
	if (GameGrid != nullptr && GameGrid->IsGridSpaceFree(GridPos + FVector2D(0, 1)))
	{
		SetActorLocation(GetActorLocation() + FVector(0, MoveSpeed, 0));
		GridPos += FVector2D(0, 1);
	}
}

void ACreature::MoveDown()
{
	if (GameGrid != nullptr && GameGrid->IsGridSpaceFree(GridPos + FVector2D(0, -1)))
	{
		SetActorLocation(GetActorLocation() + FVector(0, -MoveSpeed, 0));
		GridPos += FVector2D(0, -1);
	}
}

void ACreature::MoveLeft()
{
	if (GameGrid != nullptr && GameGrid->IsGridSpaceFree(GridPos + FVector2D(1, 0)))
	{
		SetActorLocation(GetActorLocation() + FVector(MoveSpeed, 0, 0));
		GridPos += FVector2D(1, 0);
	}
}

void ACreature::MoveRight()
{
	if (GameGrid != nullptr && GameGrid->IsGridSpaceFree(GridPos + FVector2D(-1, 0)))
	{
		SetActorLocation(GetActorLocation() + FVector(-MoveSpeed, 0, 0));
		GridPos += FVector2D(-1, 0);
	}
}

