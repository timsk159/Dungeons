#include "ItemBase.h"

UTexture2D* UItemBase::GetIcon() const
{
	return Icon;
}

FString UItemBase::GetName() const
{
	return Name;
}
