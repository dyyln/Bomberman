// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interface.h"
#include "BombermanDamagable.generated.h"

/**
 * 
 */
UINTERFACE(MinimalAPI, Blueprintable)
class UBombermanDamagable : public UInterface
{
	GENERATED_BODY()
	
};

class IBombermanDamagable {
	GENERATED_BODY()

public:

	// Called when a bomb explodes near this actor
	UFUNCTION()
	virtual void BombExplodedInRange() = 0;
};
