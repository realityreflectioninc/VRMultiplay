// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MotionControllerComponent.h"
#include "SyncMotionControllerComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = MotionController, meta = (BlueprintSpawnableComponent))
class VRMOTIONCONTROLLER_API USyncMotionControllerComponent : public UMotionControllerComponent
{
	GENERATED_BODY()
	
public:
	USyncMotionControllerComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(Replicated)
	FVector SynchronizedPosition;


	UPROPERTY(Replicated)
	FRotator SynchronizedOrientation;

	UFUNCTION(Server, Reliable, WithValidation)
	void Synchronize(const FVector& Position, const FRotator& Orientation);
};
