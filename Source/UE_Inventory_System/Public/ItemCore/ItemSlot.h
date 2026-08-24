// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemCore/ItemDefinition.h"
#include "ItemSlot.generated.h"

/**
 * 
 */
USTRUCT()
struct FItemSlot
{
	GENERATED_BODY()

protected:

	TObjectPtr<UItemDefinition> Item = nullptr;
	int32 Amount = 0;

public:

	void AddAmount(int32 Value)
	{
		Amount += Value;
	}

	void RemoveAmount(int32 Value)
	{
		Amount -= Value;
	}

	bool IsSameItem(const FItemSlot &Other) const
	{
		return Item == Other.Item;
	}

	void EmptySlot()
	{
		Item = nullptr;
		Amount = 0;
	}

	bool IsSlotEmpty() const
	{
		return Item == nullptr || Amount == 0;
	}

	void ChangeSlotItem(TObjectPtr<UItemDefinition> NewItem)
	{
		Item = NewItem;
	}
};
