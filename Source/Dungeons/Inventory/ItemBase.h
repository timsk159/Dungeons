#pragma once

#include "CoreMinimal.h"
#include "ItemBase.generated.h"

UCLASS(Blueprintable)
class UItemBase : public UObject
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UTexture2D* Icon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	FString Name;

public:
	UTexture2D* GetIcon() const;

	FString GetName() const;
};