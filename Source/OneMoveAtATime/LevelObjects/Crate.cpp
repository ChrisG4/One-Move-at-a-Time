// Fill out your copyright notice in the Description page of Project Settings.


#include "Crate.h"
#include "..\OMAATGameInstance.h"

// Sets default values
ACrate::ACrate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACrate::BeginPlay()
{
	Super::BeginPlay();
	
	GridCoord = FVector2D(GetActorLocation().X / UOMAATGameInstance::GridBoxSize, GetActorLocation().Y / UOMAATGameInstance::GridBoxSize);
}

// Called every frame
void ACrate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector2D ACrate::GetGridCoord()
{
	return this->GridCoord;
}


void ACrate::PushCrate(FVector2D Location)
{
	SetActorLocation(FVector(Location.X * UOMAATGameInstance::GridBoxSize, Location.Y * UOMAATGameInstance::GridBoxSize, GetActorLocation().Z));
	GridCoord = FVector2D(GetActorLocation().X / UOMAATGameInstance::GridBoxSize, GetActorLocation().Y / UOMAATGameInstance::GridBoxSize);
}

