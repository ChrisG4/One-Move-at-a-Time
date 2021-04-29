// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}


void APlayerCharacter::MoveUp()
{
	Super::MoveUp();
}

void APlayerCharacter::MoveDown()
{
	Super::MoveDown();
}

void APlayerCharacter::MoveLeft()
{
	Super::MoveLeft();
}

void APlayerCharacter::MoveRight()
{
	Super::MoveRight();
}

void APlayerCharacter::CheckForBox(FVector2D GridCoord)
{
	ACrate* CrateCheck = nullptr;

	if (GameGrid->GetGridBox(GridCoord) == nullptr)
	{
		return;
	}
	
	if (GameGrid->GetGridBox(GridCoord)->GetOccupyingCrate() != nullptr)
	{
		CrateCheck = GameGrid->GetGridBox(GridCoord)->GetOccupyingCrate();
	}
	
	if (CrateCheck != nullptr)
	{
		FVector2D PositionToPushTo = (2 * CrateCheck->GetGridCoord()) - this->GridPos;
		if (GameGrid->IsGridSpaceFree(PositionToPushTo))
		{
			if (GEngine)GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, ("To Push to : " + FString::SanitizeFloat(PositionToPushTo.X) + " " + FString::SanitizeFloat(PositionToPushTo.Y)));
			CrateCheck->PushCrate(PositionToPushTo);
		}
	}
}