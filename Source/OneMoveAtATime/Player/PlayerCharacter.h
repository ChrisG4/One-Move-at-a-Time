// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "..\Creatures/Creature.h"
#include "..\OMAATGameInstance.h"
#include "..\Game Grid/GameGrid.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class ONEMOVEATATIME_API APlayerCharacter : public ACreature
{
	GENERATED_BODY()
		
protected:

	void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
		AGameGrid* GameGrid;

	FVector2D GridPos = FVector2D (0, 0);

public:

	UFUNCTION(BlueprintCallable)
		void MoveUp();
	UFUNCTION(BlueprintCallable)
		void MoveDown();
	UFUNCTION(BlueprintCallable)
		void MoveLeft();
	UFUNCTION(BlueprintCallable)
		void MoveRight();


};
