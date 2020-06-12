// Fill out your copyright notice in the Description page of Project Settings.


#include "BombermanHUD.h"
#include "Engine/Canvas.h"
#include "BombermanPlayer.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/HUD.h"
#include <Bomberman\BombermanGameModeBase.h>

void ABombermanHUD::DrawHUD()
{
    Super::DrawHUD();
    if (PlayerPTR == NULL) {
        return;
    }


    ABombermanGameModeBase* GameMode = (ABombermanGameModeBase*)(GetWorld()->GetAuthGameMode());
    FString enemies_string = FString::Printf(TEXT("%d enemies remaining"), GameMode->enemies_remaining);
    DrawText(enemies_string, { 1.0f, 1.f, 1.f, 1.f }, 0.f, 5.f, NULL, 2.0f, true);

    if (PlayerPTR->current_bombs < PlayerPTR->MAX_BOMBS) {
        FString drop_string = "Press Space To Drop A Bomb";
        DrawText(drop_string, {1.0f, 1.f, 1.f, 1.f}, 0.f, 25.f, NULL, 2.0f, true);
    }
}