// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("MoveUp", IE_Pressed, this, &APlayerCharacter::MoveUp);
	PlayerInputComponent->BindAction("MoveDown", IE_Pressed, this, &APlayerCharacter::MoveDown);
	PlayerInputComponent->BindAction("MoveLeft", IE_Pressed, this, &APlayerCharacter::MoveLeft);
	PlayerInputComponent->BindAction("MoveRight", IE_Pressed, this, &APlayerCharacter::MoveRight);
}

void APlayerCharacter::MoveUp()
{
	SetActorLocation(GetActorLocation() + FVector(0, MoveSpeed, 0));
}

void APlayerCharacter::MoveDown()
{
	SetActorLocation(GetActorLocation() + FVector(0, -MoveSpeed, 0));
}

void APlayerCharacter::MoveLeft()
{
	SetActorLocation(GetActorLocation() + FVector(MoveSpeed, 0, 0));
}

void APlayerCharacter::MoveRight()
{
	SetActorLocation(GetActorLocation() + FVector(-MoveSpeed, 0, 0));
}