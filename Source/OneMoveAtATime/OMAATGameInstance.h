// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "OMAATGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ONEMOVEATATIME_API UOMAATGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	static const int32 GridBoxSize = 100;

	static void Print(FString Text);
	
};
