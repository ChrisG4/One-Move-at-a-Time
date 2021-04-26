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

	UPROPERTY(BlueprintReadWrite)
	APlayerCharacter* PlayerCharacter;

public:

	void OnPlayerMove() override;
};
