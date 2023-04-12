// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;
/**
 * 
 */
UCLASS()
class TANKBATTLE_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category = Setup)
		APawn* GetControlledTank() const; //TODO Rename

private:


	void AimTowardCrosshair();

	bool GetSightRayHitLocation(FVector &OutHitLocation) const;

	bool GetLookVectorHitPosition(FVector LookDirection, FVector& HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;



	virtual void BeginPlay() override;

	virtual void Tick(float Deltatime) override;



	UPROPERTY(EditAnywhere)
		float CrosshairPositionX = 0.5f;

	UPROPERTY(EditAnywhere)
		float CrosshairPositionY = 0.33f;

	UPROPERTY(EditAnywhere)
		float RayCastRange = 1000000.f;
	
};
