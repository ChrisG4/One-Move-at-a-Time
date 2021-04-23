// Fill out your copyright notice in the Description page of Project Settings.
#include "GridBox.h"

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
	
	SetGridIndex();
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

void AGridBox::SetGridIndex()
{
	FVector BoxPos = GetActorLocation();

	int XCoord = BoxPos.X / BoxSize;
	int YCoord = BoxPos.Y / BoxSize;

	GridCoord = FVector2D(XCoord, YCoord);
}