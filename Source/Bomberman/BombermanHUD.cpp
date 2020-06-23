// Fill out your copyright notice in the Description page of Project Settings.


#include "BombermanHUD.h"
#include "Engine/Canvas.h"
#include "BombermanPlayer.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/HUD.h"
#include <Bomberman\BombermanGameStateBase.h>
#include <Bomberman\BombermanPlayerState.h>

void ABombermanHUD::DrawHUD()
{
    Super::DrawHUD();

    ABombermanGameStateBase* GameState = (GetWorld()->GetGameState<ABombermanGameStateBase>());
    if (GameState != nullptr) {
        FString enemies_string = FString::Printf(TEXT("%d enemies remaining"), GameState->enemies_remaining);
        DrawText(enemies_string, { 1.0f, 1.f, 1.f, 1.f }, 0.f, 5.f, NULL, 2.0f, true);
    }

    ABombermanPlayer* PlayerPTR = (ABombermanPlayer*)GetOwningPawn();
    if (PlayerPTR != nullptr) {
        ABombermanPlayerState* player_state = (ABombermanPlayerState*)(PlayerPTR->GetPlayerState());
        if(player_state != nullptr){
            if (player_state->can_spawn_bomb()) {
                FString drop_string = "Press Space To Drop A Bomb";
                DrawText(drop_string, { 1.0f, 1.f, 1.f, 1.f }, 0.f, 25.f, NULL, 2.0f, true);
            }
        }
    }
}