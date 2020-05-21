// Fill out your copyright notice in the Description page of Project Settings.


#include "BombermanBomb.h"

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
    GetWorld()->GetTimerManager().SetTimer(MemberTimerHandle, this, &ABombermanBomb::Explode, 3.0f, false, 3.0f);
}

// Called every frame
void ABombermanBomb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    
}

// Called by the timer set in BeginPlay
void ABombermanBomb::Explode(){
    Destroy();
    // TODO(DYYLN): check for nearby enemies and breakable walls
}