// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "TankAimingComponent.h""


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//UE_LOG(LogTemp, Warning, TEXT("%s is MY FUCKIN TANK"), *GetControlledTank()->GetActorLabel());


}

void ATankPlayerController::Tick(float Deltatime)
{
	AimTowardCrosshair();
}



APawn* ATankPlayerController::GetControlledTank() const
{
	return GetPawn();
}



void ATankPlayerController::AimTowardCrosshair()
{
	if (!GetControlledTank()) { return; }
		
	FVector HitLocation; //Out Parameter
	if (GetSightRayHitLocation(HitLocation))
	{
		UTankAimingComponent* AimingComponent = GetControlledTank()->FindComponentByClass<UTankAimingComponent>();		///Sécurité pointeur null
		if (!AimingComponent) { return; }
		AimingComponent->AimAt(HitLocation);
		
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{

	int VPSizeX, VPSizeY;
	GetViewportSize(VPSizeX, VPSizeY);
	FVector2D CrosshairPositionInScreen = FVector2D(VPSizeX * CrosshairPositionX, VPSizeY * CrosshairPositionY);

	FVector LookDirection;
	if (GetLookDirection(CrosshairPositionInScreen, LookDirection))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Look Direction : %s"), *LookDirection.ToString())
		return GetLookVectorHitPosition(LookDirection, OutHitLocation);
	}
	return false;
}

bool ATankPlayerController::GetLookVectorHitPosition(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = StartLocation + (LookDirection * RayCastRange);
	bool hitSucced = GetWorld()->LineTraceSingleByChannel
	(
		HitResult,
		StartLocation,
		EndLocation,
		ECC_Visibility
	);

	if (hitSucced)
	{
		HitLocation = HitResult.Location;
		//UE_LOG(LogTemp, Warning, TEXT("Hit Location : %s"), *HitLocation.ToString());
		return true;
	}

	HitLocation = FVector(0.f); //Line didn't drew
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}


