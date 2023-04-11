// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
//#include "Tank.h"
#include "TankAimingComponent.h""

ATankAIController::ATankAIController()	//ATank !!!
{
	PrimaryActorTick.bCanEverTick = true;
}

APawn* ATankAIController::GetControlledAITank() const
{
	return GetPawn();
}

APawn* ATankAIController::GetPlayerTank() const
{
	return GetWorld()->GetFirstPlayerController()->GetPawn();
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float Deltatime)
{
	Super::Tick(Deltatime);

	UTankAimingComponent* AimingComponent = GetControlledAITank()->FindComponentByClass<UTankAimingComponent>();
	if (!AimingComponent) { return; }
	AimingComponent->AimAt(GetPlayerTank()->GetActorLocation());
	AimingComponent->Fire();

}
