// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Pawn.h"
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
class UTrackComponent;			
class AProjectile;				

class UTankMovementComponent;	
class UNavMovementComponent;


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

	UCanonComponent* Canon = nullptr;		//Utilisation de Canon à la place du LocalCanon de Tank.h

	UTurretComponent* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);

	void SetCanonReference(UCanonComponent* CanonReference);

	void SetTurretReference(UTurretComponent* TurretReference);

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AProjectile> ProjectileBlueprint;

	UNavMovementComponent* MovementComponent = nullptr;

	UPROPERTY(EditDefaultsOnly)
		float LaunchSpeed = 10000.f;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) /*override*/;

	//todo Créer une fonction Initialize appellable en Blueprint.
	//Elle prend en parametre le Canon et la Tourelle et elle va permettre de set reference
	UFUNCTION(BlueprintCallable)
		void Initialize(UCanonComponent* CanonToSet, UTurretComponent* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void Fire();

	double LastTimeFire = 0;

	UPROPERTY(EditDefaultsOnly)
		float ReloadTime = 3.f;
		
};
