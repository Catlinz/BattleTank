// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Tank), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downward speed and +1 is max up movement.
	void Elevate(float RelativeSpeed);
	
	
private:
	UPROPERTY(EditDefaultsOnly, Category = Movement)
	float MaxDegreesPerSecond = 10.f;

	UPROPERTY(EditDefaultsOnly, Category = Movement)
	float MaxElevationInDegrees = 40.f;

	UPROPERTY(EditDefaultsOnly, Category = Movement)
	float MinElevationInDegrees = 0.f;
};
