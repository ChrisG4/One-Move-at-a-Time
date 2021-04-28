// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "..\Game Grid\GridBox.h"
#include "Door.generated.h"

UCLASS()
class ONEMOVEATATIME_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//ASSIGNED IN BLUEPRINTS
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		AGridBox* GridBox1;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		AGridBox* GridBox2;
	
	UPROPERTY(VisibleAnywhere)
	bool bIsActive = true;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	TArray<FVector2D> GetGridBoxCoords();
	bool GetIsActive();
};
