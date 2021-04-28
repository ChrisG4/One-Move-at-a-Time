// Fill out your copyright notice in the Description page of Project Settings.

#include "LevelObject.h"
#include "..\OMAATGameInstance.h"

// Sets default values
ALevelObject::ALevelObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALevelObject::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ALevelObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

