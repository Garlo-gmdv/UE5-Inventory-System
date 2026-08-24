// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE_Inventory_System : ModuleRules
{
	public UE_Inventory_System(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
