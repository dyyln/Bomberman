// Fill out your copyright notice in the Description page of Project Settings.

#include "BombermanGameModeBase.h"

ABombermanGameModeBase::ABombermanGameModeBase(){
    DefaultPawnClass = ABombermanPlayer::StaticClass();
    HUDClass = ABombermanHUD::StaticClass();
    PlayerControllerClass = ABombermanPlayerController::StaticClass();
    PlayerStateClass = ABombermanPlayerState::StaticClass();
}


void ABombermanGameModeBase::BeginPlay(){
    
    // Check to make sure a blueprint has been set, if it has we spawn tiles in a grid
    if(BaseTileClass == NULL){
        UE_LOG(LogTemp, Warning, TEXT("No base tile set on gamemode") );
    }else{
        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 10; x++) {
                // Spawn a tile
                ABombermanBaseTile* tile = GetWorld()->SpawnActor<ABombermanBaseTile>(BaseTileClass->GetAuthoritativeClass());
                tile->SetActorLocation(FVector(1700.f - x * 400.f, -1700.f + y * 400.f, 110.f));
            }
        }
    }
}

void ABombermanGameModeBase::Tick(float delta_time){
    
}