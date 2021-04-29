// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LevelObject.h"
#include "Crate.generated.h"

UCLASS()
class ONEMOVEATATIME_API ACrate : public ALevelObject
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACrate();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	FVector2D GridCoord;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FVector2D GetGridCoord();

	void PushCrate(FVector2D Location);
};
