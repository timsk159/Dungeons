// Fill out your copyright notice in the Description page of Project Settings.


#include "CollectableItem.h"
#include "../TP_PickUpComponent.h"
#include "../DungeonsCharacter.h"
#include "InventoryComponent.h"

// Sets default values
ACollectableItem::ACollectableItem()
{
	PrimaryActorTick.bCanEverTick = false;

	PickupComponent = CreateDefaultSubobject<UTP_PickUpComponent>(TEXT("PickupComponent"));
	PickupComponent->AttachToComponent(RootComponent, FAttachmentTransformRules(EAttachmentRule::KeepRelative, false));
}

// Called when the game starts or when spawned
void ACollectableItem::BeginPlay()
{
	Super::BeginPlay();
	
	PickupComponent->OnPickUp.AddDynamic(this, &ACollectableItem::PickedUp);
}

void ACollectableItem::PickedUp(ADungeonsCharacter* PickUpCharacter)
{
	if (ItemType == nullptr)
	{
		UE_LOG(LogInventory, Error, TEXT("No ItemType set for Item that was just picked up"));
		return;
	}

	PickUpCharacter->GetInventoryComponent()->AddItemByType(ItemType);

	//Let BP know we been picked up
	OnPickedUpEvent(PickUpCharacter);
}

// Called every frame
void ACollectableItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

