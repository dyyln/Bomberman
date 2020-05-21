// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "BombermanBomb.generated.h"

UCLASS()
class BOMBERMAN_API ABombermanBomb : public AActor
{
	GENERATED_BODY()
        
public:

    class ABombermanPlayer* bomberman_player;
    
    UPROPERTY(EditAnywhere)
    USceneComponent* SceneComponent;
    
    UPROPERTY(EditAnywhere)
    UBoxComponent* BoxComponent;
    
	// Sets default values for this actor's properties
	ABombermanBomb();
    
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    
    void Explode();
    
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
