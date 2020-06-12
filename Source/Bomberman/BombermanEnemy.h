// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BombermanBasePawn.h"
#include "BombermanDamagable.h"
#include "Components/BoxComponent.h"
#include "BombermanPawnMovementComponent.h"
#include "BombermanEnemy.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_API ABombermanEnemy : public ABombermanBasePawn, public IBombermanDamagable
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere)
        USceneComponent* SceneComponent;

    UPROPERTY(EditAnywhere)
        UBoxComponent* BoxComponent;

    UPROPERTY(EditAnywhere)
        UBombermanPawnMovementComponent* MovementComponent;

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    virtual bool BombExplodedInRange() override;

public:

    ABombermanEnemy();

    // Called every frame
    virtual void Tick(float DeltaTime) override;
};
