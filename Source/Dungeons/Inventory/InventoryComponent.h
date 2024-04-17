
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemBase.h"
#include "InventoryComponent.generated.h"

UCLASS()
class UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddItem(UItemBase* Item);

	UFUNCTION(BlueprintCallable)
	void RemoteItem(UItemBase* Item);

	UFUNCTION(BlueprintCallable)
	TArray<UItemBase*> GetItems() const;

private:
	
	UPROPERTY(VisibleAnywhere)
	TArray<UItemBase*> Items;
};