// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "Projectile.h"				//A supprimer
#include "CanonComponent.h"			//A supprimer
#include "TankAimingComponent.h"	//A supprimer
#include "TankMovementComponent.h"	//A supprimer

// Sets default values
ATank::ATank()						//Ctrl+F ATank ne doit plus être nul-part sauf dans Tank.cpp et Tank.h... Remplacé par ::APawn (?)
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Tank"));		//Constructeur = seul truc à garder
}

/*void ATank::AimAt(FVector HitLocation)		//
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
	//UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s"), *GetName(), *HitLocation.ToString());		//Testé dans TankAimingComponent
}*/ 

// Called when the game starts or when spawned
/*void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}*/

//// Called to bind functionality to input
//void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//
//}


//void ATank::SetCanonReference(UCanonComponent* CanonReferenceToSet)		//A supprimer (voir todo dans TankAImingComponent)
//{
//	TankAimingComponent->SetCanonReference(CanonReferenceToSet);
//	LocalCanon = CanonReferenceToSet;
//}

//void ATank::SetTurretReference(UTurretComponent* TurretReferenceToSet)
//{
//	TankAimingComponent->SetTurretReference(TurretReferenceToSet);
//}

//void ATank::Fire()
//{
//
//		bool IsReloaded = (FPlatformTime::Seconds() - LastTimeFire) > ReloadTime;
//		if (!ProjectileBlueprint) { return; }
//		//UE_LOG(LogTemp, Warning, TEXT("IsReload %b"), IsReloaded);
//
//		if (LocalCanon && IsReloaded)
//		{
//
//			FVector SpawnProjectileLocation = LocalCanon->GetSocketLocation(FName("StartProjectile"));
//			FRotator SpawnProjectileRotation = LocalCanon->GetSocketRotation(FName("StartProjectile"));
//
//			auto Projectile = GetWorld()->SpawnActor<AProjectile>(
//				ProjectileBlueprint,
//				SpawnProjectileLocation,
//				SpawnProjectileRotation
//				);
//
//			Projectile->LaunchProjectile(LaunchSpeed);
//			LastTimeFire = FPlatformTime::Seconds();
//			//UE_LOG(LogTemp, Warning, TEXT("Fire !!"));
//		}
//	
//}






