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
	RootComponent = PickupComponent;
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
	
	if (bShouldDestroyOnCollect)
	{
		Destroy();
	}
}

UTP_PickUpComponent* ACollectableItem::GetPickupComponent() const
{
	return PickupComponent;
}


