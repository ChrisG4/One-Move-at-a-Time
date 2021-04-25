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
}

void APlayerPawn::PlayerMoveUp()
{
	if (MainPlayer != nullptr && MainPlayer->CanMoveToGridSpace(MainPlayer->GetGridPos() + FVector2D(0, -1)))
	{
		MainPlayer->MoveUp();
		MoveEnemies();
		DidPlayerDie();
	}
}

void APlayerPawn::PlayerMoveDown()
{
	if (MainPlayer != nullptr && MainPlayer->CanMoveToGridSpace(MainPlayer->GetGridPos() + FVector2D(0, 1)))
	{
		MainPlayer->MoveDown();
		MoveEnemies();
		DidPlayerDie();
	}
}

void APlayerPawn::PlayerMoveLeft()
{
	if (MainPlayer != nullptr && MainPlayer->CanMoveToGridSpace(MainPlayer->GetGridPos() + FVector2D(-1, 0)))
	{
		MainPlayer->MoveLeft();
		MoveEnemies();
		DidPlayerDie();
	}
}

void APlayerPawn::PlayerMoveRight()
{
	if (MainPlayer != nullptr && MainPlayer->CanMoveToGridSpace(MainPlayer->GetGridPos() + FVector2D(1, 0)))
	{
		MainPlayer->MoveRight();
		MoveEnemies();
		DidPlayerDie();
	}
}

void APlayerPawn::MoveEnemies()
{
	for (int i{ 0 }; i < Enemies.Num(); i++)
	{
		Enemies[i]->OnPlayerMove();
	}
}

bool APlayerPawn::DidPlayerDie()
{
	for (int i{ 0 }; i < Enemies.Num(); i++)
	{
		if (Enemies[i]->GetGridPos() == MainPlayer->GetGridPos() ||
			(Enemies[i]->GetPrevGridPos() == MainPlayer->GetGridPos()) && (Enemies[i]->GetGridPos() == MainPlayer->GetPrevGridPos()))
		{
			if (GEngine)GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "PLAYER DEAD");
			return true;
		}
	}

	return false;
}