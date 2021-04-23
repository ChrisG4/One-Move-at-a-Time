// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("MoveUp", IE_Pressed, this, &APlayerCharacter::MoveUp);
	PlayerInputComponent->BindAction("MoveDown", IE_Pressed, this, &APlayerCharacter::MoveDown);
	PlayerInputComponent->BindAction("MoveLeft", IE_Pressed, this, &APlayerCharacter::MoveLeft);
	PlayerInputComponent->BindAction("MoveRight", IE_Pressed, this, &APlayerCharacter::MoveRight);
}

void APlayerCharacter::MoveUp()
{
	if (GameGrid != nullptr && GameGrid->IsGridSpaceFree(GridPos + FVector2D(0, 1)))
	{
		SetActorLocation(GetActorLocation() + FVector(0, MoveSpeed, 0));
		GridPos += FVector2D(0, 1);
	}
}

void APlayerCharacter::MoveDown()
{
	if (GameGrid != nullptr && GameGrid->IsGridSpaceFree(GridPos + FVector2D(0, -1)))
	{
		SetActorLocation(GetActorLocation() + FVector(0, -MoveSpeed, 0));
		GridPos += FVector2D(0, -1);
	}
}

void APlayerCharacter::MoveLeft()
{
	if (GameGrid != nullptr && GameGrid->IsGridSpaceFree(GridPos + FVector2D(1, 0)))
	{
		SetActorLocation(GetActorLocation() + FVector(MoveSpeed, 0, 0));
		GridPos += FVector2D(1, 0);
	}
}

void APlayerCharacter::MoveRight()
{
	if (GameGrid != nullptr && GameGrid->IsGridSpaceFree(GridPos + FVector2D(-1, 0)))
	{
		SetActorLocation(GetActorLocation() + FVector(-MoveSpeed, 0, 0));
		GridPos += FVector2D(-1, 0);
	}
}