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

	/*
		Adds the amount to the slot. Returns the overflow based on Item->MaxStack.
	*/
	int32 AddAmount(int32 Value)
	{
		if (Amount + Value > Item->MaxStack)
		{
			int32 Overflow = Value - (Item->MaxStack - Amount);
			Amount = Item->MaxStack;
			return Overflow;
		}
		else
		{
			Amount += Value;
			return 0;
		}
	}

	void RemoveAmount(int32 Value)
	{
		Amount -= Value;
	}

	bool IsSameItem(const FItemSlot &Other) const
	{
		return Item == Other.Item;
	}

	bool HasItemType(const UItemDefinition* ItemType) const
	{
		return Item == ItemType;
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

	void ChangeSlotItem(UItemDefinition* NewItem)
	{
		Item = NewItem;
	}

	FString ToString() const
	{
		if (IsSlotEmpty())
		{
			return TEXT("Empty");
		}
		else
		{
			return FString::Printf(
				TEXT("%s x%d"),
				*Item->DisplayName.ToString(),
				Amount);
		}
	}
};
