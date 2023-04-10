// Fill out your copyright notice in the Description page of Project Settings.


//#include "TankMovementComponent.h"
//#include "TankTrack.h"
//
//void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
//{
//	if (!LeftTrackToSet || !RightTrackToSet)
//	{
//		return;
//	}
//
//	LeftTrack = LeftTrackToSet;
//	RightTrack = RightTrackToSet;
//}
//
//void UTankMovementComponent::IntendMoveForward(float Throttle)
//{
//	if (!LeftTrack || !RightTrack) { return; }
//	LeftTrack->SetThrottle(Throttle);
//	RightTrack->SetThrottle(Throttle);
//}
//
//void UTankMovementComponent::IntendTurnRight(float Throttle)
//{
//	if (!LeftTrack || !RightTrack) { return; }
//	LeftTrack->SetThrottle(Throttle);
//	RightTrack->SetThrottle(-Throttle);
//}
//
//void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
//{
//	auto TankForwardDirection = GetOwner()->GetActorForwardVector(), GetSafeNormal();
//	auto AIForwardINtentin = MoveVelocity.GetSafeNormal();
//
//	auto ForwardDirection = FVector::DotProduct(TankForwardDirection, AIForwardIntention);
//		auto RotateDirection = FVector::CrossProduct(AIForwardIntention, TankForwardDirection);
//}

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }

	//UE_LOG(LogTemp, Warning, TEXT("%s MoveForward : %f"), *GetName(), Throw);

	//TODO:
	// Forward : Put both tracks on POSITIVE value
	// Backward : Put both tracks on NEGATIVE value

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }

	//UE_LOG(LogTemp, Warning, TEXT("%s MoveRight : %f"), *GetName(), Throw);
	//TODO:
	// Left : Put track left on NEGATIVE value, track right on POSITIVE value
	// Right : Put track left on POSITIVE value, track right on NEGATIVE value

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) { return; }

	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	//auto TankName = GetOwner()->GetName();
	auto TankForwardVector = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	//auto TankMoveVelocity = MoveVelocity.ToString();

	auto ForwardDirection = FVector::DotProduct(TankForwardVector, AIForwardIntention);
	auto RotateDirection = FVector::CrossProduct(AIForwardIntention, TankForwardVector);

	//UE_LOG(LogTemp, Warning, TEXT("%s Delta angle = %s"), ForwardDirection);

	IntendMoveForward(ForwardDirection);
	IntendTurnRight(RotateDirection.Z);

}