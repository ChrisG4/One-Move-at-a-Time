// Fill out your copyright notice in the Description page of Project Settings.


#include "OMAATGameInstance.h"

void UOMAATGameInstance::Print(FString Text)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, Text);
	}
}