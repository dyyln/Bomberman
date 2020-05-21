// Fill out your copyright notice in the Description page of Project Settings.


#include "BombermanPlayerController.h"

void ABombermanPlayerController::BeginPlay() {
	Super::BeginPlay();
    
	/*UWorld* poWorld = GetWorld();
	ACameraActor* poCameraActor = poWorld->SpawnActor<ACameraActor>();
	poCameraActor->GetCameraComponent()->ProjectionMode = ECameraProjectionMode::Perspective;
	poCameraActor->GetCameraComponent()->FieldOfView = 90.f;
    
	FTransform transform(FVector(-800.f, -30.0f, 1200.0f));
	transform.SetRotation(FQuat::MakeFromEuler(FVector(0.0f, 300.0f, 0.0f)));
	poCameraActor->SetActorTransform(transform);
	poCameraActor->GetCameraComponent()->Activate();
    
	SetViewTarget(poCameraActor);*/
}