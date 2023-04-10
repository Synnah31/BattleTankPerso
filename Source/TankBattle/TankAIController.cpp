// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Tank.h"

ATankAIController::ATankAIController()
{
	PrimaryActorTick.bCanEverTick = true;
}

ATank* ATankAIController::GetControlledAITank() const
{
	ATank* var = Cast<ATank>(GetPawn());
	return var;
}

ATank* ATankAIController::GetPlayerTank() const
{
	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (!PlayerTank) { return nullptr;  }
	return PlayerTank;
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	//GetControlledAITank()->AimAt(GetPlayerTank()->GetActorLocation());
	//UE_LOG(LogTemp, Warning, TEXT("%s is controlled by AI"), *GetControlledAITank()->GetActorLabel());
}

void ATankAIController::Tick(float Deltatime)
{
	Super::Tick(Deltatime);
	GetControlledAITank()->AimAt(GetPlayerTank()->GetActorLocation());
	//GetControlledAITank()->Fire();

}
