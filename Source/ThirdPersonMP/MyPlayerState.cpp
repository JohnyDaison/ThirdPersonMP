// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPlayerState.h"
#include "Net/UnrealNetwork.h"

void AMyPlayerState::GetLifetimeReplicatedProps(TArray <FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//Replicate current health.
	DOREPLIFETIME(AMyPlayerState, PlayerHealth);
}

void AMyPlayerState::SetPlayerHealth(float healthValue)
{
	if (GetLocalRole() == ROLE_Authority)
	{
		PlayerHealth = healthValue;
	}
}