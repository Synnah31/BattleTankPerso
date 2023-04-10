// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UENUM()
enum class EAimingState : uint8
{
	Aiming,
	Reloading,
	EnnemiLocked
};

class UCanonComponent;
class UTurretComponent;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKBATTLE_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = Setup)
		EAimingState AimingState = EAimingState::EnnemiLocked;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AimAt(FVector HitLocation, float LaunchSpeed);

	UCanonComponent* Canon = nullptr;

	UTurretComponent* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);

	void SetCanonReference(UCanonComponent* CanonReference);

	void SetTurretReference(UTurretComponent* TurretReference);

	

		
};
