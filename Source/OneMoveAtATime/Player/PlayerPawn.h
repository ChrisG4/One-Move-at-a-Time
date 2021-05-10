// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerCharacter.h"
#include "..\Creatures\PatrolEnemy.h"
#include "..\Creatures\ChaserEnemy.h"
#include "PlayerPawn.generated.h"

UCLASS()
class ONEMOVEATATIME_API APlayerPawn : public APawn
{
	GENERATED_BODY()



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite)
		APlayerCharacter* MainPlayer;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		TArray<APatrolEnemy*> PatrolEnemies;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		TArray<AChaserEnemy*> ChaserEnemies;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		TArray<AEnemy*> AllEnemies;

	UPROPERTY(EditDefaultsOnly)
		USoundBase* PlayerMoveSound;

public:	
	APlayerPawn();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	void PlayerMove(FVector2D MovementVector);

	void PlayerMoveUp();
	void PlayerMoveDown();
	void PlayerMoveLeft();
	void PlayerMoveRight();

	void UpdateGameGrid();
	void MoveEnemies();

	bool DidPlayerDie();
	void CheckEnemyCollisions();
};
