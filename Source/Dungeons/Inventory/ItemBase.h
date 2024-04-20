#pragma once

#include "CoreMinimal.h"
#include "ItemBase.generated.h"

UCLASS(Blueprintable)
class UItemBase : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	UTexture2D* GetIcon() const;

	UFUNCTION(BlueprintCallable)
	FString GetName() const;

private:
	UPROPERTY(EditDefaultsOnly)
	UTexture2D* Icon;

	UPROPERTY(EditDefaultsOnly)
	FString Name;
};