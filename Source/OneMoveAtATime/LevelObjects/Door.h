// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LevelObject.h"
#include "..\Game Grid\GridBox.h"
#include "PressurePlate.h"
#include "Door.generated.h"

USTRUCT()
struct FInput
{
	GENERATED_BODY()
	
	//INVERTED INPUT = Button not being pressed is active
	UPROPERTY(EditAnywhere)
	bool InvertInput;

	UPROPERTY(EditAnywhere)
	APressurePlate* PressurePlate;
};

UCLASS()
class ONEMOVEATATIME_API ADoor : public ALevelObject
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

	UPROPERTY(EditAnywhere, Category = "Switches")
		TArray<FInput> PressurePlates;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	TArray<FVector2D> GetGridBoxCoords();

	void UpdateActive();
	
	UFUNCTION(BlueprintImplementableEvent)
	void UpdateVisibility(bool IsActive);

	bool GetIsActive();
};
