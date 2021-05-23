// Fill out your copyright notice in the Description page of Project Settings.
#define ASCII_CONVERT -48

#include "LevelEnd.h"


void ALevelEnd::SetNextLevelName(FString CurrentLevelName)
{
	CurrentChapter = (int32)(CurrentLevelName.GetCharArray()[5]) + ASCII_CONVERT;
	CurrentLevelNumber = (int32)(CurrentLevelName.GetCharArray()[7]) + ASCII_CONVERT;
	
	int32 NextLevelNumber = CurrentLevelNumber + 1;

	NextLevelName = "Level" + FString::FromInt(CurrentChapter) + "-" + FString::FromInt(NextLevelNumber);
}

void ALevelEnd::SetNextLevelNameChapterEnd(FString CurrentLevelName)
{
	CurrentChapter = (int32)(CurrentLevelName.GetCharArray()[5]) + ASCII_CONVERT;
	
	int32 NextChapterNumber = CurrentChapter + 1;

	NextLevelName = "Level" + FString::FromInt(NextChapterNumber) + "-" + FString::FromInt(1);
}

FString ALevelEnd::GetNextLevelName()
{
	return NextLevelName;
}