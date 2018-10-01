// Copyright Catlin Zilinski.  But not really.

#include "Public/Projectile.h"

#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("MovementComponent");
	MovementComponent->bAutoActivate = false;

}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AProjectile::LaunchProjectile(float InitialSpeed) {
	UE_LOG(LogTemp, Warning, TEXT("Projectile fires at %f"), InitialSpeed);
	MovementComponent->SetVelocityInLocalSpace(FVector::ForwardVector * InitialSpeed);
	MovementComponent->Activate();
}

