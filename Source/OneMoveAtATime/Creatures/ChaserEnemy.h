// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "..\Player/PlayerCharacter.h"
#include "ChaserEnemy.generated.h"


UENUM()
enum State
{
	Idle UMETA(DisplayName = "Idle"),
	Chasing UMETA(DisplayName = "Chasing"),
};

UCLASS()
class ONEMOVEATATIME_API AChaserEnemy : public AEnemy
{
	GENERATED_BODY()
	
protected:

	void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite)
	APlayerCharacter* PlayerCharacter;

	UPROPERTY(VisibleAnywhere, Category = "Pathfinding")
	int32 CurrentGridIndex;

	UPROPERTY(VisibleAnywhere, Category = "Pathfinding")
	FVector2D TargetGridCoord;

	UPROPERTY(VisibleAnywhere, Category = "Pathfinding")
	int32 TargetGridIndex;

	UPROPERTY(VisibleAnywhere, Category = "Pathfinding")
	FVector2D NextMoveGridCoord;

	UPROPERTY(VisibleAnywhere, Category = "Pathfinding")
	int32 NextMoveGridIndex;

	UPROPERTY(VisibleAnywhere, Category = "Pathfinding")
	TArray<FVector2D> PossibleMoves;

	UPROPERTY(VisibleAnywhere, Category = "Vision", BlueprintReadWrite)
	TArray<FVector2D> VisionCoords;

	State CurrentState;

public:

	void OnPlayerMove() override;

	UFUNCTION(BlueprintImplementableEvent)
	void CreateVisionSprites();

	void SetVisionCoords();
	void CheckVision();

	UFUNCTION(BlueprintImplementableEvent)
	void OnBeginChase();

	void FindPlayer();

	void FindPossibleMoves();
	void SelectNextMove();
	void Move();

	void CheckIfStuck() override;
};
