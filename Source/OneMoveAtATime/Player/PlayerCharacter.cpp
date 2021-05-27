// Fill out your copyright notice in the Description page of Project Settings.
#define print(TEXT) if(GEngine)GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Green, TEXT)

#include "PlayerCharacter.h"
#include "..\Creatures\Enemy.h"
#include "..\Creatures\ChaserEnemy.h"

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}


void APlayerCharacter::CheckForBox(FVector2D GridCoord)
{
	ACrate* CrateCheck = nullptr;
	FVector2D PositionToPushTo = (2 * GridCoord - this->GridPos);

	if (GameGrid->GetGridBox(GridCoord) != nullptr && GameGrid->GetGridBox(PositionToPushTo) != nullptr)
	{

		if (GameGrid->GetGridBox(GridCoord)->GetOccupyingCrate() != nullptr)
		{
			CrateCheck = GameGrid->GetGridBox(GridCoord)->GetOccupyingCrate();
		}


		if (GameGrid->GetGridBox(PositionToPushTo)->GetOccupyingEntity() != nullptr) {
			if (Cast<AEnemy>(GameGrid->GetGridBox(PositionToPushTo)->GetOccupyingEntity()) != nullptr)
			{
				if (Cast<AEnemy>(GameGrid->GetGridBox(PositionToPushTo)->GetOccupyingEntity())->IsStuck() || Cast<AChaserEnemy>(GameGrid->GetGridBox(PositionToPushTo)->GetOccupyingEntity()))
				{
					return;
				}
			}
		}

		if (CrateCheck != nullptr)
		{
			if (GameGrid->IsGridSpaceFree(PositionToPushTo) && !GameGrid->IsGridPathBlocked(GridPos, GridCoord) && !GameGrid->IsGridPathBlocked(GridCoord, PositionToPushTo))
			{
				if (GEngine)GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, ("To Push to : " + FString::SanitizeFloat(PositionToPushTo.X) + " " + FString::SanitizeFloat(PositionToPushTo.Y)));
				CrateCheck->PushCrate(PositionToPushTo);
			}
		}

	}
}