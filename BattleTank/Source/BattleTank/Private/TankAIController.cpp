// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/TankAIController.h"
#include "Engine/World.h"

#include "TankPlayerController.h"


ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	auto Tank = GetPlayerTank();

	if (Tank) {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller got player tank '%s'!"), *Tank->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller failed to get player tank!"));
	}
}


ATank* ATankAIController::GetPlayerTank() const {
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

	if (PlayerController) {
		return (Cast<ATankPlayerController>(PlayerController))->GetControlledTank();
	}
	else {
		return nullptr;
	}
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	
	/// Don't do anything if no controlled tank or no player controlled tank
	auto Tank = GetControlledTank();
	auto PlayerTank = GetPlayerTank();

	if (!Tank || !PlayerTank) { return; }

	/// Aim at the player
	Tank->AimAt(PlayerTank->GetActorLocation());

	/// Fire if ready

}
