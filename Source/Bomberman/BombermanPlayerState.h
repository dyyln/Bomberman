// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "BombermanPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_API ABombermanPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	// Current number of active bombs the player has
	int get_current_bombs();

	// Returns true if we can spawn a bomb
	bool can_spawn_bomb();

	// Increase the count of active bombs
	void add_bomb();

	// Reduce the count of active bombs
	void remove_bomb();

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

private:
	UPROPERTY(Replicated)
	int current_bombs = 0;

	UPROPERTY(Replicated)
	int MAX_BOMBS = 1;
};
