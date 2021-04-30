// Fill out your copyright notice in the Description page of Project Settings.
#include "GridBox.h"
#include "DrawDebugHelpers.h"
#include "GameGrid.h"
#include "..\OMAATGameInstance.h"

AGridBox::AGridBox()
{
}

void AGridBox::BeginPlay()
{
	Super::BeginPlay();

	if (!IsPlacementValid())
	{
		this->Destroy();
		if (GEngine)
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, TEXT("Invalid Box Placement at " + GetActorLocation().ToString()));
	}
	
	SetGridCoord();
	DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Green, true, -1, 0, 2);
}

bool AGridBox::IsPlacementValid()
{
	FVector Pos = GetActorLocation();
	int32 intX = Pos.X;
	int32 intY = Pos.Y;

	if (intX % BoxSize == 0 && intY % BoxSize == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void AGridBox::SetGridCoord()
{
	FVector BoxPos = GetActorLocation();

	int XCoord = BoxPos.X / BoxSize;
	int YCoord = BoxPos.Y / BoxSize;

	GridCoord = FVector2D(XCoord, YCoord);
}

FVector2D AGridBox::GetGridCoord()
{
	return this->GridCoord;
}

bool AGridBox::DoesContainEnemy()
{
	return this->bContainsEnemy;
}

void AGridBox::SetContainsCrate(bool DoesContainCrate)
{
	this->bContainsCrate = DoesContainCrate;
}

bool AGridBox::DoesContainCrate()
{
	return bContainsCrate;
}

ACrate* AGridBox::GetOccupyingCrate()
{
	if (OccupyingCrate != nullptr)
	{
		return  OccupyingCrate;
	}

	return nullptr;
}

AActor* AGridBox::GetOccupyingEntity()
{
	if (OccupyingEntity != nullptr)
	{
		return OccupyingEntity;
	}

	return nullptr;
}