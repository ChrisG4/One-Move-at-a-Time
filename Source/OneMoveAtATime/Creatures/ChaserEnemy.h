// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "..\Player/PlayerCharacter.h"
#include "ChaserEnemy.generated.h"

/**
 * 
 */
UCLASS()
class ONEMOVEATATIME_API AChaserEnemy : public AEnemy
{
	GENERATED_BODY()
	
protected:

	void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite)
	APlayerCharacter* PlayerCharacter;

	int32 CurrentGridIndex;

	FVector2D TargetGridCoord;
	int32 TargetGridIndex;

	FVector2D NextMoveGridCoord;
	int32 NextMoveGridIndex;

	TArray<FVector2D> PossibleMoves;

public:

	void OnPlayerMove() override;
	void FindPlayer();

	void FindPossibleMoves();
	void SelectNextMove();
	void Move();
};
