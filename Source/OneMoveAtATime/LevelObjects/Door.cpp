// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

TArray<FVector2D> ADoor::GetGridBoxCoords()
{
	TArray<FVector2D> GridBoxCoords;
	if (GridBox1 != nullptr && GridBox2 != nullptr) {
		GridBoxCoords.Push(GridBox1->GetGridCoord());
		GridBoxCoords.Push(GridBox2->GetGridCoord());
	}

	return GridBoxCoords;
}

bool ADoor::GetIsActive()
{
	return this->bIsActive;
}