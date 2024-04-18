
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemBase.h"
#include "InventoryComponent.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogInventory, Log, All);

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
	void AddItemByType(TSubclassOf<UItemBase> Item);

	UFUNCTION(BlueprintCallable)
	TArray<UItemBase*> GetItems() const;

private:
	
	UPROPERTY(VisibleAnywhere)
	TArray<UItemBase*> Items;
};