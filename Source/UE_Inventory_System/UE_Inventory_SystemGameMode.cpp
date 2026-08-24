// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE_Inventory_SystemGameMode.h"
#include "UE_Inventory_SystemCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE_Inventory_SystemGameMode::AUE_Inventory_SystemGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
