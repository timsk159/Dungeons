#include "InventoryComponent.h"

void UInventoryComponent::AddItem(UItemBase* Item)
{
	Items.Add(Item);
}

void UInventoryComponent::RemoteItem(UItemBase* Item)
{
	Items.Add(Item);
}

TArray<UItemBase*> UInventoryComponent::GetItems() const
{
	return Items;
}
