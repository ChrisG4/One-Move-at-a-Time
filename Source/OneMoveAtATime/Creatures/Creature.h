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

	UPROPERTY(EditAnywhere, Category = "Grid Information")
		AGameGrid* GameGrid;

	UPROPERTY(VisibleAnywhere, Category = "Grid Information")
		FVector2D GridPos;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
		void MoveUp();
	UFUNCTION(BlueprintCallable)
		void MoveDown();
	UFUNCTION(BlueprintCallable)
		void MoveLeft();
	UFUNCTION(BlueprintCallable)
		void MoveRight();

};
