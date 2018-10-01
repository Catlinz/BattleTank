// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"
#include "Public/Tank.h"


ATank * ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();

	auto Tank = GetControlledTank();
	if (!Tank) {
		UE_LOG(LogTemp, Error, TEXT("%s failed to get controlled tank on play"), *Tank->GetName());
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair() {
	auto Tank = GetControlledTank();

	if (!Tank) { return; }

	FVector HitLocation;  // Out parameter
	if (GetSightRayHitLocation(HitLocation)) {
		Tank->AimAt(HitLocation);
	}
	
}

// Get world location of linetrace through crosshair, true if hit landscape.
bool ATankPlayerController::GetSightRayHitLocation(FVector& out_HitLocation) const
{
	// Find crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	const FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrossHairYLocation);


	// "De-project" the screen position of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection)) 
	{
		// Line-trace along that LookDirection, and see what we hit up to a max range.
		if (GetLookVectorHitLocation(LookDirection, out_HitLocation)) {
			return true;
		}
	}
	
	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& out_LookDirection) const {
	FVector CameraWorldLocation;  // To be discarded.
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, out_LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& out_HitLocation) const {
	FHitResult HitResult;
	FVector TraceStartLocation = PlayerCameraManager->GetCameraLocation();
	FVector TraceEndLocation = TraceStartLocation + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		TraceStartLocation,
		TraceEndLocation,
		ECollisionChannel::ECC_Visibility,
		FCollisionQueryParams(NAME_None, false, GetPawn())
	)) {
		out_HitLocation = HitResult.Location;
		return true;
	}
	else {
		out_HitLocation = FVector::ZeroVector;
		return false;
	}
}

