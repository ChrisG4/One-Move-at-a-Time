// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "PatrolEnemy.generated.h"

/**
 * 
 */

UENUM()
enum Direction
{
	Up UMETA(DisplayName = "Up"), 
	Down UMETA(DisplayName = "Down"), 
	Left UMETA(DisplayName = "Left"), 
	Right UMETA(DisplayName = "Right"),
};

UCLASS()
class ONEMOVEATATIME_API APatrolEnemy : public AEnemy
{
	GENERATED_BODY()
	
protected:

	void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Patrolling")
		TEnumAsByte<Direction> InitialMoveDirection;
	
	UPROPERTY(VisibleAnywhere, Category = "Patrolling")
		TEnumAsByte<Direction> CurrentMoveDirection;

public:

	void OnPlayerMove() override;

	UFUNCTION()
	void CheckIfStuck() override;
	void UpdateMoveDirection();

	UFUNCTION(BlueprintCallable)
		void OnTeleport(Direction NewDirection);
};
