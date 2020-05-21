// Fill out your copyright notice in the Description page of Project Settings.


#include "BombermanBomb.h"
#include "BombermanPlayer.h"
#include <Runtime\Engine\Classes\Kismet\GameplayStatics.h>

// Sets default values
ABombermanBomb::ABombermanBomb()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    // Create a dummy root component we can attach things to.
    BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("RootComponent"));
    RootComponent = BoxComponent;
    BoxComponent->SetCollisionProfileName(TEXT("Pawn"));
    BoxComponent->SetBoxExtent(FVector(0.f, 0.f, 0.f));
    
    // Create Visible object
    SceneComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SceneComponent"));
    SceneComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABombermanBomb::BeginPlay()
{
	Super::BeginPlay();
	//Create a timer to explode
    FTimerHandle MemberTimerHandle;
    GetWorld()->GetTimerManager().SetTimer(MemberTimerHandle, this, &ABombermanBomb::Explode, 2.0f, false, 2.0f);
}

// Called every frame
void ABombermanBomb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    
}

// Called by the timer set in BeginPlay
void ABombermanBomb::Explode(){
    Destroy();

    // Reduce number of active bombs on player so we can add a new bomb
    bomberman_player->current_bombs--;

    if (ExplosionEffect != NULL) {
        FVector spawnLocation = GetActorLocation();
        UGameplayStatics::SpawnEmitterAtLocation(this, ExplosionEffect, spawnLocation, FRotator::ZeroRotator, true, EPSCPoolMethod::AutoRelease);
    }
    else {
        UE_LOG(LogTemp, Warning, TEXT("No explosion effect set on bomb"));
    }

    // TODO(DYYLN): check for nearby enemies and breakable walls
}