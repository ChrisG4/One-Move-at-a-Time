// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "..\Creatures/Creature.h"
#include "..\OMAATGameInstance.h"
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

	int32 MoveSpeed = UOMAATGameInstance::GridBoxSize;

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
