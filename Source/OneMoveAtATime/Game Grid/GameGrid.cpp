// Fill out your copyright notice in the Description page of Project Settings.


#include "GameGrid.h"

// Sets default values
AGameGrid::AGameGrid()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGameGrid::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnGridBoxes();
}

// Called every frame
void AGameGrid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGameGrid::SpawnGridBoxes()
{
	if (GridBoxType != nullptr && GridBoxPositions.Num() > 0) {
		for (int i{ 0 }; i < GridBoxPositions.Num(); i++)
		{
			AGridBox* NewBox = GetWorld()->SpawnActor<AGridBox>(GridBoxType, GridBoxPositions[i] + GetActorLocation(), FRotator(0, 0, 0));
			GridBoxes.Add(NewBox->GetGridCoord(), NewBox);

			GridCoords.Add(NewBox->GetGridCoord());
		}
	}
}

bool AGameGrid::IsGridSpaceFree(FVector2D GridCoord)
{
	if (GridBoxes.Contains(GridCoord))
	{
		return true;
	}
	else
	{
		return false;
	}
}

