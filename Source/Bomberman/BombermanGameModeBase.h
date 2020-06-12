// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BombermanPlayer.h"
#include "BombermanPlayerController.h"
#include "BombermanPlayerState.h"
#include "BombermanHUD.h"
#include "BombermanBaseTile.h"
#include "BombermanEnemy.h"
#include "BombermanBreakableTile.h"
#include "BombermanGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_API ABombermanGameModeBase : public AGameModeBase
{
    GENERATED_BODY()
        
        ABombermanGameModeBase();

    // Tiles to be put in grid
    UPROPERTY(EditAnywhere)
        TSubclassOf<ABombermanBaseTile> BaseTileClass;

    // Breakable tiles to get put in between
    UPROPERTY(EditAnywhere)
        TSubclassOf<ABombermanBreakableTile> BreakableTileClass;


    // Enemy class to spawn
    UPROPERTY(EditAnywhere)
        TSubclassOf<ABombermanEnemy> EnemyClass;
    
    protected:
    virtual void BeginPlay() override;
    
    public:
    virtual void Tick(float delta_time) override;

    int enemies_remaining = 0;
};
