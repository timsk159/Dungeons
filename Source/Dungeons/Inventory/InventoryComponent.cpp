#include "InventoryComponent.h"

DEFINE_LOG_CATEGORY(LogInventory)

void UInventoryComponent::AddItem(UItemBase* Item)
{
	Items.Add(Item);
}

void UInventoryComponent::AddItemByType(TSubclassOf<UItemBase> Item)
{
	UItemBase* ItemInstance = NewObject<UItemBase>(this, Item);
	AddItem(ItemInstance);
}

void UInventoryComponent::RemoteItem(UItemBase* Item)
{
	Items.Remove(Item);
}

TArray<UItemBase*> UInventoryComponent::GetItems() const
{
	return Items;
}
