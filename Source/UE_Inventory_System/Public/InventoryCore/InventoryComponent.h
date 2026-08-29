// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemCore/ItemDefinition.h"
#include "ItemCore/ItemSlot.h"
#include "ItemCore/Item.h"
#include "InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UE_INVENTORY_SYSTEM_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	int32 SlotNumber = 10;

	UFUNCTION(BlueprintCallable)
	void InitializeInventory();

	/*
		Adds the item to available slots, returns the overflow.
	*/
	UFUNCTION(BlueprintCallable)
	int32 AddItem(UItemDefinition* ItemType, int32 Amount);

	/*
		Adds the item to available slots, returns if the remove is successful. true if the inventory has enough items false if not.
	*/
	UFUNCTION(BlueprintCallable)
	bool RemoveItem(UItemDefinition* ItemType, int32 Amount);

	/*
		Returns true if the inventory has the specified amount of the ItemType. Do not use with RemoveItem, use the return value of RemoveItem instead.
	*/
	UFUNCTION(BlueprintCallable)
	bool HasEnoughItem(UItemDefinition* ItemType, int32 Amount);

	UFUNCTION(BlueprintCallable)
	void DropItem(int32 ItemIndex);

	/*
		Returns a copy of the current slots. Use only as a way of reading the data.
	*/
	UFUNCTION(BlueprintCallable)
	TArray<FItemSlot> GetSlots() const;

	UFUNCTION(BlueprintCallable)
	void DebugPrint() const;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	TArray<FItemSlot> Items;

	TArray<FItemSlot*> GetAllSlotsOfType(const UItemDefinition* ItemType);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
