// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "OneMoveAtATimeGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class ONEMOVEATATIME_API AOneMoveAtATimeGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
protected:

	void BeginPlay() override;
};
