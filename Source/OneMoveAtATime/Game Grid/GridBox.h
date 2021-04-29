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
	bool bIsBoxBlocked = false;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		ACrate* OccupyingCrate;

public:
	AGridBox();

	bool IsPlacementValid();
	void SetGridCoord();

	FVector2D GetGridCoord();

	void SetIsBoxBlocked(bool IsBoxBlocked);
	bool IsBoxBlocked();
	ACrate* GetOccupyingCrate();

};
