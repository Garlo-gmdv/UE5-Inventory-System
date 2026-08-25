// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryCore/InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UInventoryComponent::InitializeInventory()
{
	Items.Init(FItemSlot(), SlotNumber);
}

int32 UInventoryComponent::AddItem(UItemDefinition* ItemType, int32 Amount)
{
	TArray<FItemSlot*> AvailableItemSlots = GetAllSlotsOfType(ItemType);
	if (!AvailableItemSlots.IsEmpty())
	{
		int32 i = 0;
		while (i < AvailableItemSlots.Num() && Amount > 0)
		{
			Amount = AvailableItemSlots[i]->AddAmount(Amount);
			++i;
		}
	}

	if (Amount > 0)
	{
		TArray<FItemSlot*> AvailableEmptySlots = GetAllSlotsOfType(nullptr);
		int32 i = 0;
		while (i < AvailableEmptySlots.Num() && Amount > 0)
		{
			AvailableEmptySlots[i]->ChangeSlotItem(ItemType);
			Amount = AvailableEmptySlots[i]->AddAmount(Amount);
			++i;
		}
	}

	return Amount;
}

void UInventoryComponent::DebugPrint() const
{
	UE_LOG(LogTemp, Display, TEXT("Debug start."))
	for (const FItemSlot& Item : Items)
	{
		UE_LOG(LogTemp, Display, TEXT("--- Slot: %s"), *Item.ToString())
	}
	UE_LOG(LogTemp, Display, TEXT("Debug end."))
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

TArray<FItemSlot*> UInventoryComponent::GetAllSlotsOfType(const UItemDefinition* ItemType)
{
	TArray<FItemSlot*> Slots;
	for (FItemSlot& Item : Items)
	{
		if (Item.HasItemType(ItemType))
		{
			Slots.Add(&Item);
		}
	}
	return Slots;
}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

