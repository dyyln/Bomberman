// Fill out your copyright notice in the Description page of Project Settings.


#include "BombermanBreakableTile.h"

bool ABombermanBreakableTile::BombExplodedInRange()
{
	Destroy();

	return true;
}
