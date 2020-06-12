// Fill out your copyright notice in the Description page of Project Settings.


#include "BombermanPlayer.h"
#include "BombermanPlayerController.h"
#include "Components/InputComponent.h"
#include <Runtime\Engine\Classes\Kismet\GameplayStatics.h>

// Sets default values
ABombermanPlayer::ABombermanPlayer()
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
    
    // Create spring arm
    // Use a spring arm to give the camera smooth, natural-feeling motion.
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraAttachmentArm"));
    SpringArm->SetupAttachment(RootComponent);
    SpringArm->SetRelativeRotation(FRotator(270.f, 0.f, 0.f));
    SpringArm->TargetArmLength = 2000.0f;
    SpringArm->bEnableCameraLag = true;
    SpringArm->CameraLagSpeed = 7.5f;
    SpringArm->bDoCollisionTest = false;
    
    // Attach our camera and visible object to our root component. Offset and rotate the camera.
    OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
    OurCamera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
    
    // Add our movement component
    MovementComponent = CreateDefaultSubobject<UBombermanPawnMovementComponent>(TEXT("CustomMovementComponent"));
    MovementComponent->UpdatedComponent = RootComponent;
    MovementComponent->SetIsReplicated(true);
    
    // Set pawn to be controller by player
    AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void ABombermanPlayer::BeginPlay()
{
	Super::BeginPlay();

    APlayerController* Controller = Cast<APlayerController>(GetController());
    if (Controller != NULL) {
        HUD_reference = (ABombermanHUD*)(Controller)->GetHUD();
        HUD_reference->PlayerPTR = this;
    }
}

// Called every frame
void ABombermanPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    
}

// Called to bind functionality to input
void ABombermanPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    
    check(PlayerInputComponent);
    
    // Bind movement controls
    PlayerInputComponent->BindAxis("Forward", this, &ABombermanPlayer::Forward);
    PlayerInputComponent->BindAxis("Backward", this, &ABombermanPlayer::Backward);
    PlayerInputComponent->BindAxis("Left", this, &ABombermanPlayer::Left);
    PlayerInputComponent->BindAxis("Right", this, &ABombermanPlayer::Right);
    
    // Bind action keys
    PlayerInputComponent->BindAction("Bomb", IE_Pressed, this, &ABombermanPlayer::SpawnBomb);
}

void ABombermanPlayer::Forward(float amount){
    MovementComponent->AddInputVector(GetActorForwardVector() * amount * 1.5f);
}

void ABombermanPlayer::Backward(float amount){
    MovementComponent->AddInputVector(-GetActorForwardVector() * amount * 1.5f);
}

void ABombermanPlayer::Left(float amount){
    MovementComponent->AddInputVector(-GetActorRightVector() * amount * 1.5f);
}

void ABombermanPlayer::Right(float amount){
    MovementComponent->AddInputVector(GetActorRightVector() * amount * 1.5f);
}

void ABombermanPlayer::SpawnBomb_Implementation(){
    if (GetLocalRole() == ROLE_Authority) {
        if (current_bombs >= MAX_BOMBS) {
            // Don't spawwn a bomb if we already have the max amount
            return;
        }

        // Check to make sure a blueprint has been set, if it has we spawn bomb
        if (BombClass == NULL) {
            UE_LOG(LogTemp, Warning, TEXT("No bomb class set on player"));
        }
        else {
            current_bombs++;

            // Spawn a bomb
            ABombermanBomb* bomb = GetWorld()->SpawnActor<ABombermanBomb>(BombClass->GetAuthoritativeClass());
            // Pass a reference to this player
            bomb->bomberman_player = this;
            // Set the transform to the same as the players
            FTransform transform = GetActorTransform();
            bomb->SetActorTransform(transform);
        }
    }
}