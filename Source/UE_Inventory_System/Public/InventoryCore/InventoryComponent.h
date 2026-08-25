// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemCore/ItemDefinition.h"
#include "ItemCore/ItemSlot.h"
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
