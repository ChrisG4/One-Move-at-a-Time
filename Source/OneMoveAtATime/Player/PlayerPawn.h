// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerCharacter.h"
#include "..\Creatures\Enemy.h"
#include "PlayerPawn.generated.h"

UCLASS()
class ONEMOVEATATIME_API APlayerPawn : public APawn
{
	GENERATED_BODY()



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		APlayerCharacter* MainPlayer;

	UPROPERTY(EditAnywhere)
		TArray<AEnemy*> Enemies;

public:	
	APlayerPawn();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void PlayerMoveUp();
	void PlayerMoveDown();
	void PlayerMoveLeft();
	void PlayerMoveRight();

	void MoveEnemies();

};
