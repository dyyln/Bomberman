// Fill out your copyright notice in the Description page of Project Settings.


#include "BombermanBreakableTile.h"
#include <Runtime\Engine\Classes\Kismet\GameplayStatics.h>

bool ABombermanBreakableTile::BombExplodedInRange()
{
	Destroy();


    if (DestructionEffect != NULL) {
        FVector spawnLocation = GetActorLocation();
        UGameplayStatics::SpawnEmitterAtLocation(this, DestructionEffect, spawnLocation, FRotator::ZeroRotator, true, EPSCPoolMethod::AutoRelease);
    }
    else {
        UE_LOG(LogTemp, Warning, TEXT("No destruction effect set on breakable tile"));
    }

	return true;
}
