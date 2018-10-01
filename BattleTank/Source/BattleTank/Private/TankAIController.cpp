// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAIController.h"
#include "Engine/World.h"

#include "TankPlayerController.h"
#include "Public/Tank.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	
	/// Don't do anything if no controlled tank or no player controlled tank
	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ATank* ControlledTank = Cast<ATank>(GetPawn());

	if (!ControlledTank || !PlayerTank) { return; }

	/// Aim at the player
	ControlledTank->AimAt(PlayerTank->GetActorLocation());

	/// Fire if ready
	ControlledTank->Fire();  // Limit fireing rate
}
