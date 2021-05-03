// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LevelObject.h"
#include "Portal.generated.h"

/**
 * 
 */
UCLASS()
class ONEMOVEATATIME_API APortal : public ALevelObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (MakeEditWidget = "true"))
		FVector OutputLocation1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (MakeEditWidget = "true"))
		FVector OutputLocation2;
	
};
