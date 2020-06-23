// Fill out your copyright notice in the Description page of Project Settings.

#include "BombermanGameModeBase.h"
#include "Math/UnrealMathUtility.h"

ABombermanGameModeBase::ABombermanGameModeBase(){

}


void ABombermanGameModeBase::BeginPlay() {
    // Check to make sure a blueprint has been set, if it has we spawn tiles in a grid
    if (BaseTileClass == nullptr) {
        UE_LOG(LogTemp, Warning, TEXT("No base tile set on gamemode"));
    }
    else if (BreakableTileClass == nullptr) {
        UE_LOG(LogTemp, Warning, TEXT("No breakable tile set on gamemode"));
    }
    else if (EnemyClass == nullptr) {
        UE_LOG(LogTemp, Warning, TEXT("No enemy set on gamemode"));
    }
    else if (GetWorld() == nullptr) {
        UE_LOG(LogTemp, Warning, TEXT("Couldn't GetWorld"));
    }
    else {
        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 10; x++) {
                // Spawn a tile
                ABombermanBaseTile* tile = GetWorld()->SpawnActor<ABombermanBaseTile>(BaseTileClass->GetAuthoritativeClass());
                tile->SetActorLocation(FVector(1700.f - x * 400.f, -1700.f + y * 400.f, 110.f));
            }
        }

        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 10; x++) {
                if (x == 5 && y == 4) {
                    // This is where the player starts so we dont want a tile here
                    continue;
                }
                if (FMath::RandRange(0, 4) == 0) {
                    // Spawn a tile
                    ABombermanBreakableTile* tile = GetWorld()->SpawnActor<ABombermanBreakableTile>(BreakableTileClass->GetAuthoritativeClass());
                    tile->SetActorLocation(FVector(1700.f - x * 400.f + 200.f, -1700.f + y * 400.f + 200.f, 110.f));
                }else if (FMath::RandRange(0, 4) == 0) {
                    // Spawn an enemy
                     //ABombermanEnemy* enemy = GetWorld()->SpawnActor<ABombermanEnemy>(EnemyClass->GetAuthoritativeClass());
                     //enemy->SetActorLocation(FVector(1700.f - x * 400.f + 200.f, -1700.f + y * 400.f + 200.f, 110.f));
                }
            }
        }
    }
}

void ABombermanGameModeBase::Tick(float delta_time){
    
}