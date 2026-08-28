// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemCore/ItemDefinition.h"
#include "Components/SphereComponent.h"
#include "Item.generated.h"

UCLASS(BlueprintType)
class UE_INVENTORY_SYSTEM_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();
	TObjectPtr<UStaticMeshComponent> Mesh = nullptr;
	TObjectPtr<USphereComponent> CollisionSphere = nullptr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(BlueprintReadOnly, meta = (ExposeOnSpawn = "true"))
	TObjectPtr<UItemDefinition> ItemType = nullptr;
	UPROPERTY(BlueprintReadOnly, meta = (ExposeOnSpawn = "true"))
	int32 Amount = 1;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
