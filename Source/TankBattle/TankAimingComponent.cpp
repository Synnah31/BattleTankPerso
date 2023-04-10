// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"
#include "CanonComponent.h"
#include "TurretComponent.h"
#include "Math/Vector.h"
#include <Kismet/GameplayStatics.h>

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Canon) { return; }

	FString NameOwner = GetOwner()->GetActorLabel();
	FString OwnerLocation = Canon->GetComponentLocation().ToString();
	FString TargetLocationTemp = HitLocation.ToString();
	//UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s from %s"), *NameOwner, *HitLocation.ToString());

	FVector TossVelocity;
	FVector StartLocation = Canon->GetSocketLocation(FName("StartProjectile"));

	bool FoundVelocity = UGameplayStatics::SuggestProjectileVelocity(
		this,
		TossVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	if (FoundVelocity) 
	{
		FVector NormalizedDirection = TossVelocity.GetSafeNormal();
		//UE_LOG(LogTemp, Warning, TEXT("Aiming at : %s"), *NormalizedDirection.ToString())
		MoveBarrelTowards(NormalizedDirection);
		
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	//Get canon rotation
	auto CanonRotation = Canon->GetForwardVector().Rotation();

	//Get aiming rotation
	auto AimAsRotator = AimDirection.Rotation();
	//UE_LOG(LogTemp, Warning, TEXT("AimAsRotator : %s"), *AimAsRotator.ToString())

	//Get difference betwenn canon & aiming rotation (delta)
	auto DeltaRotator = AimAsRotator - CanonRotation;

	//Print delta
	//UE_LOG(LogTemp, Warning, TEXT("Delta rotation : %s"), *DeltaRotator.ToString())

	Canon->Elevate(DeltaRotator.Pitch);
	Turret->RotateRight(DeltaRotator.Yaw);
}

void UTankAimingComponent::SetCanonReference(UCanonComponent* CanonReference)
{
	Canon = CanonReference;
}

void UTankAimingComponent::SetTurretReference(UTurretComponent* TurretReference)
{
	Turret = TurretReference;
}

