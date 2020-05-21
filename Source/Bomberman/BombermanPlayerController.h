// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Camera/CameraActor.h"
#include "Camera/CameraComponent.h"
#include "Engine/World.h"
#include "BombermanPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_API ABombermanPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
};
