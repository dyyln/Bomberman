// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "BombermanGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_API ABombermanGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:

	int enemies_remaining = 0;
};
