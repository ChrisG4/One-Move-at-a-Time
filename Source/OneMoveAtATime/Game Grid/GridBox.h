// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "..\OMAATGameInstance.h"
#include "..\LevelObjects/Crate.h"
#include "GridBox.generated.h"

/**
 * 
 */
UCLASS()
class ONEMOVEATATIME_API AGridBox : public ATriggerBox
{
	GENERATED_BODY()
	
protected:

	void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	FVector2D GridCoord;

	const int32 BoxSize = UOMAATGameInstance::GridBoxSize;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	bool bContainsCrate = false;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		bool bContainsEnemy = false;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		ACrate* OccupyingCrate;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		AActor* OccupyingEntity;

public:
	AGridBox();

	bool IsPlacementValid();
	void SetGridCoord();
	FVector2D GetGridCoord();

	bool DoesContainEnemy();

	void SetContainsCrate(bool DoesContainCrate);
	bool DoesContainCrate();

	UFUNCTION()
	ACrate* GetOccupyingCrate();
	UFUNCTION()
	AActor* GetOccupyingEntity();
};
