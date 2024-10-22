// Fill out your copyright notice in the Description page of Project Settings.


#include "HittableComponent.h"

// Sets default values for this component's properties
UHittableComponent::UHittableComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHittableComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHittableComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHittableComponent::Hit(AActor* OtherActor)
{
	if (OtherActor != nullptr)
	{
		// Notify that the actor is being picked up
		OnHit.Broadcast(OtherActor);
	}
}