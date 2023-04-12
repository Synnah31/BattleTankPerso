// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class UTankAimingComponent;
class ATank;							//TODO Delete ? Replace by class APawn; ?

/**
 * 
 */
UCLASS()
class TANKBATTLE_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public : 
	ATankAIController();		

protected :
	virtual void BeginPlay() override;

private: 

	APawn* GetControlledAITank() const;	//TODO Rename

	APawn* GetPlayerPawn() const; 

public :
	virtual void Tick(float Deltatime) override;

	//TODO Comment
	float AcceptanceRadius = 300.f;
	
};
