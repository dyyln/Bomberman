// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "BombermanCharMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/BoxComponent.h"
#include "BombermanBomb.h"
#include "BombermanHUD.h"
#include "BombermanPlayer.generated.h"

UCLASS()
class BOMBERMAN_API ABombermanPlayer : public ACharacter
{
	GENERATED_BODY()
        
        public:
    
    UPROPERTY(EditAnywhere)
        USceneComponent* SceneComponent;
    
    UPROPERTY(EditAnywhere)
        UCameraComponent* OurCamera;
    
    UPROPERTY(EditAnywhere)
        USpringArmComponent* SpringArm;
    
    UPROPERTY(EditAnywhere)
        UBoxComponent* BoxComponent;
    
    UPROPERTY(EditAnywhere)
        TSubclassOf<ABombermanBomb> BombClass;

    UPROPERTY(EditAnywhere)
        UBombermanCharMovementComponent* MovementComponent;
    
	// Sets default values for this character's properties
	ABombermanPlayer();
    
protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    
public:

    ABombermanHUD* HUD_reference;
    
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    
    // Movement functions
    void Forward(float amount);
    void Backward(float amount);
    void Left(float amount);
    void Right(float amount);
    
    // When the player wants to spawn a bomb
    void SpawnBombAction();

    // Spawn a bomb
    UFUNCTION(Server, Reliable)
    void SpawnBomb();
};
