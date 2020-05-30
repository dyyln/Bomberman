// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interface.h"
#include "Damagable.generated.h"

/**
 * 
 */
UINTERFACE(MinimalAPI, Blueprintable)
class UDamagable : public UInterface
{
	GENERATED_BODY()
	
};

class IDamagable {
	GENERATED_BODY()

public:

	// Called when a bomb explodes near this actor
	UFUNCTION()
	virtual bool BombExplodedInRange() = 0;
};
