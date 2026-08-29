// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemDefinition.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class UE_INVENTORY_SYSTEM_API UItemDefinition : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "UI")
	FText DisplayName;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "UI")
	FText Description;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "UI")
	TObjectPtr<UTexture2D> Icon = nullptr;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Core")
	int32 MaxStack = 1;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Render")
	TObjectPtr<UStaticMesh> Mesh = nullptr;
};
