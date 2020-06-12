// Fill out your copyright notice in the Description page of Project Settings.


#include "BombermanBaseTile.h"

// Sets default values
ABombermanBaseTile::ABombermanBaseTile()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
    SetReplicates(true);
    
    // Create a box component that we set as the root
    BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("RootComponent"));
    RootComponent = BoxComponent;
    BoxComponent->SetCollisionProfileName(TEXT("Pawn"));
    BoxComponent->SetBoxExtent(FVector(50.f, 50.f, 50.f));
    
    // Create Visible object
    SceneComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SceneComponent"));
    SceneComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABombermanBaseTile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABombermanBaseTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    
}

