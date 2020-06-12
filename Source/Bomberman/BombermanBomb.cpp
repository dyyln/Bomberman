// Fill out your copyright notice in the Description page of Project Settings.


#include "BombermanBomb.h"
#include "BombermanPlayer.h"
#include "BombermanDamagable.h"
#include <Runtime\Engine\Classes\Kismet\GameplayStatics.h>

// Sets default values
ABombermanBomb::ABombermanBomb()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    SetReplicates(true);
    
    // Create Visible object
    SceneComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SceneComponent"));

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
    if (bomberman_player != NULL) {
        bomberman_player->current_bombs--;
    }
    else {
        UE_LOG(LogTemp, Warning, TEXT("No pointer to player set on bomb"));
    }

    if (ExplosionEffect != NULL) {
        FVector spawnLocation = GetActorLocation();
        UGameplayStatics::SpawnEmitterAtLocation(this, ExplosionEffect, spawnLocation, FRotator::ZeroRotator, true, EPSCPoolMethod::AutoRelease);
    }
    else {
        UE_LOG(LogTemp, Warning, TEXT("No explosion effect set on bomb"));
    }

    // Get all the actors in the scene that are damagable
    TArray<AActor*> FoundActors;
    UGameplayStatics::GetAllActorsWithInterface(GetWorld(), UBombermanDamagable::StaticClass(), FoundActors);

    // Check distance between actor and bomb
    for (auto actor : FoundActors) {
        if ((this->GetActorLocation() - actor->GetActorLocation()).Size() < BOMB_RADIUS) {
            IBombermanDamagable* damaged_actor = Cast<IBombermanDamagable>(actor);
            damaged_actor->BombExplodedInRange();
            UE_LOG(LogTemp, Warning, TEXT("Damagable actor found"));
        }
    }
}