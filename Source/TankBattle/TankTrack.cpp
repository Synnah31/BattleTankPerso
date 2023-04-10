// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"

void UTankTrack::SetThrottle(float speed)
{
    FVector ForceApplied = GetForwardVector() * speed * TrackMaxDrivingForce; //Dans un moteur de jeu, si on multiplie des FVector par des float, ça nous renvois des FVector 
    FVector Location = GetComponentLocation();

    UPrimitiveComponent* PrimComp = Cast<UPrimitiveComponent>(GetOwner()-> GetRootComponent()); //GetTrack

    PrimComp->AddForceAtLocation
    (
        ForceApplied,
        Location
    );

	//UE_LOG(LogTemp, Warning, TEXT("%f speed"), speed);
}
