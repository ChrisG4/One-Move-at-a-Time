// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AEnemy::OnPlayerMove()
{
	MoveDown();
}