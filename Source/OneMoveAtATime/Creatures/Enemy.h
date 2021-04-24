// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Creature.h"
#include "..\OMAATGameInstance.h"
#include "Enemy.generated.h"

/**
 * 
 */
UCLASS()
class ONEMOVEATATIME_API AEnemy : public ACreature
{
	GENERATED_BODY()

protected:

	void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

public:

	virtual void OnPlayerMove();
	
};
