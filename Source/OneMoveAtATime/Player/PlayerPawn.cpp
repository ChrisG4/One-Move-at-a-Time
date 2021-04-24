// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("MoveUp", IE_Pressed, this, &APlayerPawn::PlayerMoveUp);
	PlayerInputComponent->BindAction("MoveDown", IE_Pressed, this, &APlayerPawn::PlayerMoveDown);
	PlayerInputComponent->BindAction("MoveLeft", IE_Pressed, this, &APlayerPawn::PlayerMoveLeft);
	PlayerInputComponent->BindAction("MoveRight", IE_Pressed, this, &APlayerPawn::PlayerMoveRight);

	PlayerInputComponent->BindAction("MoveUp", IE_Pressed, this, &APlayerPawn::MoveEnemies);
	PlayerInputComponent->BindAction("MoveDown", IE_Pressed, this, &APlayerPawn::MoveEnemies);
	PlayerInputComponent->BindAction("MoveLeft", IE_Pressed, this, &APlayerPawn::MoveEnemies);
	PlayerInputComponent->BindAction("MoveRight", IE_Pressed, this, &APlayerPawn::MoveEnemies);

}

void APlayerPawn::PlayerMoveUp()
{
	if (MainPlayer != nullptr)
	{
		MainPlayer->MoveUp();
	}
}

void APlayerPawn::PlayerMoveDown()
{
	if (MainPlayer != nullptr)
	{
		MainPlayer->MoveDown();
	}
}

void APlayerPawn::PlayerMoveLeft()
{
	if (MainPlayer != nullptr)
	{
		MainPlayer->MoveLeft();
	}
}

void APlayerPawn::PlayerMoveRight()
{
	if (MainPlayer != nullptr)
	{
		MainPlayer->MoveRight();
	}
}

void APlayerPawn::MoveEnemies()
{
	for (int i{ 0 }; i < Enemies.Num(); i++)
	{
		Enemies[i]->OnPlayerMove();
	}
}