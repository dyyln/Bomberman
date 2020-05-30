// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BombermanBaseTile.h"
#include "Damagable.h"
#include "BombermanBreakableTile.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_API ABombermanBreakableTile : public ABombermanBaseTile, public IDamagable
{
	GENERATED_BODY()

	virtual bool BombExplodedInRange() override;
};
