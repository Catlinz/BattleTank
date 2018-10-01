// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "TankPlayerController.generated.h"

class ATank;

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	// Returns the Tank pawn that is being possessed.
	ATank * GetControlledTank() const;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	// Start the tank moving the barrel so that a shot would hit where 
	// the crosshair intersects the world.
	void AimTowardsCrosshair();
	
	bool GetSightRayHitLocation(FVector& out_HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& out_LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& out_HitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5;
	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.33333;
	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;
	
};
