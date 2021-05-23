// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LevelObject.h"
#include "LevelEnd.generated.h"

/**
 * 
 */
UCLASS()
class ONEMOVEATATIME_API ALevelEnd : public ALevelObject
{
	GENERATED_BODY()

private:

	UPROPERTY(VisibleAnywhere)
	int32 CurrentChapter;

	UPROPERTY(VisibleAnywhere)
	int32 CurrentLevelNumber;

	UPROPERTY(VisibleAnywhere)
	FString NextLevelName;

public:

	UFUNCTION(BlueprintCallable)
	void SetNextLevelName(FString CurrentLevelName);

	UFUNCTION(BlueprintCallable)
	void SetNextLevelNameChapterEnd(FString CurrentLevelName);

	UFUNCTION(BlueprintCallable)
		FString GetNextLevelName();

};
