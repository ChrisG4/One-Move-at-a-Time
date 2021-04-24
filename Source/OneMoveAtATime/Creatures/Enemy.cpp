// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AEnemy::OnPlayerMove()
{
	SetActorLocation(GetActorLocation() + FVector(0, MoveSpeed, 0));

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, "Enemy Moved");
	}
}