// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "BombermanBaseTile.generated.h"

UCLASS()
class BOMBERMAN_API ABombermanBaseTile : public AActor
{
	GENERATED_BODY()
        
        public:
	// Sets default values for this actor's properties
	ABombermanBaseTile();

    UPROPERTY(EditAnywhere)
        UBoxComponent* BoxComponent;

    UPROPERTY(EditAnywhere)
        USceneComponent* SceneComponent;
    
    protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    
    public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    
};
