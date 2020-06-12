// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"

#include "BombermanHUD.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_API ABombermanHUD : public AHUD
{
	GENERATED_BODY()

public:

    class ABombermanPlayer* PlayerPTR;

    // Primary draw call for the HUD.
    virtual void DrawHUD() override;
};
