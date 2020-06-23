// Fill out your copyright notice in the Description page of Project Settings.


#include "BombermanPlayerState.h"
#include <Runtime\Engine\Public\Net\UnrealNetwork.h>

void ABombermanPlayerState::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ABombermanPlayerState, current_bombs);
	DOREPLIFETIME(ABombermanPlayerState, MAX_BOMBS);
}

int ABombermanPlayerState::get_current_bombs() {
	return current_bombs;
}

bool ABombermanPlayerState::can_spawn_bomb() {
	return current_bombs < MAX_BOMBS;
}

void ABombermanPlayerState::add_bomb()
{
	current_bombs++;
}


void ABombermanPlayerState::remove_bomb()
{
	current_bombs--;
}
