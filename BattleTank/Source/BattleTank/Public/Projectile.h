// Copyright Catlin Zilinski.  But not really.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

class UProjectileMovementComponent;

UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()

private:
	UProjectileMovementComponent * MovementComponent = nullptr;
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

	void LaunchProjectile(float InitialSpeed);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
