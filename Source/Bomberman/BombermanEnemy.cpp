// Fill out your copyright notice in the Description page of Project Settings.


#include "BombermanEnemy.h"

// Sets default values
ABombermanEnemy::ABombermanEnemy()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    SetReplicateMovement(true);
    SetReplicates(true);

    // Create a dummy root component we can attach things to.
    BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("RootComponent"));
    RootComponent = BoxComponent;
    BoxComponent->SetCollisionProfileName(TEXT("Pawn"));
    BoxComponent->SetBoxExtent(FVector(50.f, 50.f, 50.f));

    // Create Visible object
    SceneComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SceneComponent"));
    SceneComponent->SetupAttachment(RootComponent);

    // Add our movement component
    MovementComponent = CreateDefaultSubobject<UBombermanPawnMovementComponent>(TEXT("CustomMovementComponent"));
    MovementComponent->UpdatedComponent = RootComponent;
    MovementComponent->SetIsReplicated(true);

    // Set pawn to be controller by player
    AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void ABombermanEnemy::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void ABombermanEnemy::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

bool ABombermanEnemy::BombExplodedInRange()
{
	return false;
}
