// Fill out your copyright notice in the Description page of Project Settings.


#include "BombermanPawnMovementComponent.h"

void UBombermanPawnMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    
    // Make sure we have an owner and a component to update
    if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime))
    {
        return;
    }
    
    // Apply movement
    FVector movementVector = ConsumeInputVector().GetClampedToMaxSize(1.0f) * DeltaTime * 1000.0f;
    if (!movementVector.IsNearlyZero())
    {
        FHitResult hitResult;
        SafeMoveUpdatedComponent(movementVector, UpdatedComponent->GetComponentRotation(), true, hitResult);
        
        // Handle hit result
        if (hitResult.IsValidBlockingHit())
        {
            SlideAlongSurface(movementVector, 1.f - hitResult.Time, hitResult.Normal, hitResult);
        }
    }
};