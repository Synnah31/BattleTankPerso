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
	//GetControlledAITank()->AimAt(GetPlayerTank()->GetActorLocation());
	//UE_LOG(LogTemp, Warning, TEXT("%s is controlled by AI"), *GetControlledAITank()->GetActorLabel());
}

void ATankAIController::Tick(float Deltatime)
{
	Super::Tick(Deltatime);
	//Récupérer Tank (en Pawn)
	//Récupérer AimingComponent sur le pawn OwnTank = FindComponentByClass<UTankAimingComponent>();
	UTankAimingComponent* AimingComponent = GetControlledAITank()->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(GetPlayerTank()->GetActorLocation());
	//GetControlledAITank()->Fire();

}
