// Copyright Catlin Zilinski.  But not really.

#include "Public/TankTurret.h"

#include "Engine/World.h"

void UTankTurret::Rotate(float RelativeSpeed) {
	// Make sure to clamp the RelativeSpeed between -1 and 1
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	auto YawChage = MaxDegreesPerSecond * RelativeSpeed * GetWorld()->DeltaTimeSeconds;
	auto NewYaw = RelativeRotation.Yaw + YawChage;
	
	SetRelativeRotation(FRotator(0, NewYaw, 0));
}


