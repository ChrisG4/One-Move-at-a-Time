// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("MoveUp", IE_Pressed, this, &APlayerPawn::PlayerMoveUp);
	PlayerInputComponent->BindAction("MoveDown", IE_Pressed, this, &APlayerPawn::PlayerMoveDown);
	PlayerInputComponent->BindAction("MoveLeft", IE_Pressed, this, &APlayerPawn::PlayerMoveLeft);
	PlayerInputComponent->BindAction("MoveRight", IE_Pressed, this, &APlayerPawn::PlayerMoveRight);
}

void APlayerPawn::PlayerMove(FVector2D MovementVec)
{
	if (MainPlayer != nullptr)
	{
		FVector2D TargetSpace = MainPlayer->GetGridPos() + MovementVec;

		MainPlayer->CheckForBox(TargetSpace);

		if (MainPlayer->CanMoveToGridSpace(TargetSpace))
		{
			if (PlayerMoveSound != nullptr)
				UGameplayStatics::PlaySound2D(GetWorld(), PlayerMoveSound, 1.0f, 1.0f, 0.0f);

			MainPlayer->MoveTo(TargetSpace);
			MoveEnemies();
			UpdateGameGrid();
			CheckEnemyCollisions();
			DidPlayerDie();
		}
	}
}

void APlayerPawn::PlayerMoveUp()
{
	PlayerMove(FVector2D(0, -1));
}

void APlayerPawn::PlayerMoveDown()
{
	PlayerMove(FVector2D(0, 1));
}

void APlayerPawn::PlayerMoveLeft()
{
	PlayerMove(FVector2D(-1, 0));
}

void APlayerPawn::PlayerMoveRight()
{
	PlayerMove(FVector2D(1, 0));
}

void APlayerPawn::UpdateGameGrid()
{
	MainPlayer->GetGameGrid()->UpdateGameGrid();
}

void APlayerPawn::MoveEnemies()
{
	MainPlayer->GetGameGrid()->CreateAdjacencyMatrix();

	for (int i{ 0 }; i < PatrolEnemies.Num(); i++)
	{
		PatrolEnemies[i]->OnPlayerMove();
	}

	for (int i{ 0 }; i < ChaserEnemies.Num(); i++)
	{
		ChaserEnemies[i]->OnPlayerMove();
	}
}

bool APlayerPawn::DidPlayerDie()
{	
	for (int i{ 0 }; i < AllEnemies.Num(); i++)
	{
		if (AllEnemies[i]->GetGridPos() == MainPlayer->GetGridPos() ||
			(AllEnemies[i]->GetPrevGridPos() == MainPlayer->GetGridPos()) && (AllEnemies[i]->GetGridPos() == MainPlayer->GetPrevGridPos()))
		{
			if (GEngine)GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, "PLAYER DEAD");
			return true;
		}
	}

	return false;
}

void APlayerPawn::CheckEnemyCollisions()
{
	for (int i{ 0 }; i < AllEnemies.Num(); i++)
	{
		for (int j{ 0 }; j < AllEnemies.Num(); j++)
		{
			if (i != j && AllEnemies[i] != nullptr && AllEnemies[j] != nullptr
				&& (AllEnemies[i]->GetGridPos() == AllEnemies[j]->GetGridPos()
					|| (AllEnemies[i]->GetPrevGridPos() == AllEnemies[j]->GetGridPos() && AllEnemies[i]->GetGridPos() == AllEnemies[j]->GetPrevGridPos())))
			{
				AllEnemies[i]->Destroy();
				AllEnemies[j]->Destroy();
			}
		}
	}

	for (int i{ AllEnemies.Num() - 1}; i >= 0; i--)
	{
		if (!IsValid(AllEnemies[i]))
		{
			AllEnemies.RemoveAt(i);
		}
	}

	for (int i{ PatrolEnemies.Num() - 1 }; i >= 0; i--)
	{
		if (!IsValid(PatrolEnemies[i]))
		{
			PatrolEnemies.RemoveAt(i);
		}
	}

	for (int i{ ChaserEnemies.Num() - 1 }; i >= 0; i--)
	{
		if (!IsValid(ChaserEnemies[i]))
		{
			ChaserEnemies.RemoveAt(i);
		}
	}
}