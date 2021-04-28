// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "..\OMAATGameInstance.h"
#include "..\Game Grid/GameGrid.h"
#include "Creature.generated.h"

UCLASS()
class ONEMOVEATATIME_API ACreature : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACreature();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	int32 MoveSpeed = UOMAATGameInstance::GridBoxSize;

	UPROPERTY(BlueprintReadWrite)
		AGameGrid* GameGrid;

	UPROPERTY(VisibleAnywhere, Category = "Grid Information")
		FVector2D GridPos;

	UPROPERTY(VisibleAnywhere, Category = "Grid Information")
		FVector2D PrevGridPos;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//GET CREATURE INFO
	AGameGrid* GetGameGrid();

	FVector2D GetGridPos();
	FVector2D GetPrevGridPos();
	
	//MOVEMENT CHECKS
	bool CanMoveToGridSpace(FVector2D GridSpace);

	//MOVEMENT FUNCTIONS
	virtual void MoveUp();
	virtual void MoveDown();
	virtual void MoveLeft();
	virtual void MoveRight();

};
