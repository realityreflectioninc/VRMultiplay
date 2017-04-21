// Fill out your copyright notice in the Description page of Project Settings.

#include "VRMotionController.h"
#include "SyncMotionControllerComponent.h"
#include "UnrealNetwork.h"

USyncMotionControllerComponent::USyncMotionControllerComponent()
{
	bReplicates = true;
}

void USyncMotionControllerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!IsTracked())
	{
		SetRelativeLocationAndRotation(SynchronizedPosition, SynchronizedOrientation);
	}
	else
	{
		auto transform = GetRelativeTransform();
		Synchronize(transform.GetLocation(), transform.GetRotation().Rotator());
	}
}

void USyncMotionControllerComponent::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(USyncMotionControllerComponent, SynchronizedPosition);
	DOREPLIFETIME(USyncMotionControllerComponent, SynchronizedOrientation);
}

void USyncMotionControllerComponent::Synchronize_Implementation(const FVector& Position, const FRotator& Orientation)
{
	SynchronizedPosition = Position;
	SynchronizedOrientation = Orientation;
}

bool USyncMotionControllerComponent::Synchronize_Validate(const FVector& Position, const FRotator& Orientation)
{
	return true;
}

