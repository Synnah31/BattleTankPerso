// Fill out your copyright notice in the Description page of Project Settings.


#include "TurretComponent.h"
#include "Math/UnrealMathUtility.h"

void UTurretComponent::RotateRight(float DegreesPerSecond)
{
	//UE_LOG(LogTemp, Warning, TEXT("Rotate at : %f"), DegreesPerSecond); //TODO Delete

	auto RelativeSpeedClamped = FMath::Clamp<float>(DegreesPerSecond, -1, +1);

	auto RotateChange = RelativeSpeedClamped * MaxRotationDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = GetRelativeRotation().Yaw + RotateChange;


	SetRelativeRotation(FRotator(0.f, RawNewRotation, 0.f));
}
