// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CollectableItem.generated.h"

class UTP_PickUpComponent;
class ADungeonsCharacter;
class UItemBase;

UCLASS()
class DUNGEONS_API ACollectableItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACollectableItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void PickedUp(ADungeonsCharacter* PickUpCharacter);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPickedUpEvent(ADungeonsCharacter* PickUpCharacter);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<UItemBase> ItemType;

	UFUNCTION(BlueprintCallable)
	UTP_PickUpComponent* GetPickupComponent() const;

	UPROPERTY(BlueprintReadWrite)
	bool bShouldDestroyOnCollect = true;

private:

	UPROPERTY(EditAnywhere)
	UTP_PickUpComponent* PickupComponent;

};
