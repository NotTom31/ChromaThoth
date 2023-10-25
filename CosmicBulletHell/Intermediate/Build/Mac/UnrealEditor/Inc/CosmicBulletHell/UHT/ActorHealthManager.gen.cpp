// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CosmicBulletHell/Private/ActorHealthManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeActorHealthManager() {}
// Cross Module References
	COSMICBULLETHELL_API UClass* Z_Construct_UClass_AActorHealthManager();
	COSMICBULLETHELL_API UClass* Z_Construct_UClass_AActorHealthManager_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	UPackage* Z_Construct_UPackage__Script_CosmicBulletHell();
// End Cross Module References
	DEFINE_FUNCTION(AActorHealthManager::execHealActor)
	{
		P_GET_OBJECT(AActor,Z_Param_Actor);
		P_GET_PROPERTY(FFloatProperty,Z_Param_HealAmount);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HealActor(Z_Param_Actor,Z_Param_HealAmount);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AActorHealthManager::execApplyDamage)
	{
		P_GET_OBJECT(AActor,Z_Param_Actor);
		P_GET_PROPERTY(FFloatProperty,Z_Param_DamageAmount);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ApplyDamage(Z_Param_Actor,Z_Param_DamageAmount);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AActorHealthManager::execTestActorHealthInEditor)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->TestActorHealthInEditor();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AActorHealthManager::execGetHealth)
	{
		P_GET_OBJECT(AActor,Z_Param_Actor);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetHealth(Z_Param_Actor);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AActorHealthManager::execSetHealth)
	{
		P_GET_OBJECT(AActor,Z_Param_Actor);
		P_GET_PROPERTY(FFloatProperty,Z_Param_HealthValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetHealth(Z_Param_Actor,Z_Param_HealthValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AActorHealthManager::execUnregisterActor)
	{
		P_GET_OBJECT(AActor,Z_Param_Actor);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UnregisterActor(Z_Param_Actor);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AActorHealthManager::execRegisterActor)
	{
		P_GET_OBJECT(AActor,Z_Param_Actor);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RegisterActor(Z_Param_Actor);
		P_NATIVE_END;
	}
	void AActorHealthManager::StaticRegisterNativesAActorHealthManager()
	{
		UClass* Class = AActorHealthManager::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ApplyDamage", &AActorHealthManager::execApplyDamage },
			{ "GetHealth", &AActorHealthManager::execGetHealth },
			{ "HealActor", &AActorHealthManager::execHealActor },
			{ "RegisterActor", &AActorHealthManager::execRegisterActor },
			{ "SetHealth", &AActorHealthManager::execSetHealth },
			{ "TestActorHealthInEditor", &AActorHealthManager::execTestActorHealthInEditor },
			{ "UnregisterActor", &AActorHealthManager::execUnregisterActor },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AActorHealthManager_ApplyDamage_Statics
	{
		struct ActorHealthManager_eventApplyDamage_Parms
		{
			AActor* Actor;
			float DamageAmount;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Actor;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DamageAmount;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AActorHealthManager_ApplyDamage_Statics::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ActorHealthManager_eventApplyDamage_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AActorHealthManager_ApplyDamage_Statics::NewProp_DamageAmount = { "DamageAmount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ActorHealthManager_eventApplyDamage_Parms, DamageAmount), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AActorHealthManager_ApplyDamage_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AActorHealthManager_ApplyDamage_Statics::NewProp_Actor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AActorHealthManager_ApplyDamage_Statics::NewProp_DamageAmount,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AActorHealthManager_ApplyDamage_Statics::Function_MetaDataParams[] = {
		{ "Category", "Health" },
		{ "Comment", "// Applies damage to a specified actor, reducing its health by the specified damage amount, and ensuring it does not fall below zero\n" },
		{ "ModuleRelativePath", "Private/ActorHealthManager.h" },
		{ "ToolTip", "Applies damage to a specified actor, reducing its health by the specified damage amount, and ensuring it does not fall below zero" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AActorHealthManager_ApplyDamage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AActorHealthManager, nullptr, "ApplyDamage", nullptr, nullptr, sizeof(Z_Construct_UFunction_AActorHealthManager_ApplyDamage_Statics::ActorHealthManager_eventApplyDamage_Parms), Z_Construct_UFunction_AActorHealthManager_ApplyDamage_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AActorHealthManager_ApplyDamage_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AActorHealthManager_ApplyDamage_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AActorHealthManager_ApplyDamage_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AActorHealthManager_ApplyDamage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AActorHealthManager_ApplyDamage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AActorHealthManager_GetHealth_Statics
	{
		struct ActorHealthManager_eventGetHealth_Parms
		{
			AActor* Actor;
			float ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Actor;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AActorHealthManager_GetHealth_Statics::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ActorHealthManager_eventGetHealth_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AActorHealthManager_GetHealth_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ActorHealthManager_eventGetHealth_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AActorHealthManager_GetHealth_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AActorHealthManager_GetHealth_Statics::NewProp_Actor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AActorHealthManager_GetHealth_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AActorHealthManager_GetHealth_Statics::Function_MetaDataParams[] = {
		{ "Category", "Health" },
		{ "Comment", "// Gets the current health value of a specified actor\n" },
		{ "ModuleRelativePath", "Private/ActorHealthManager.h" },
		{ "ToolTip", "Gets the current health value of a specified actor" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AActorHealthManager_GetHealth_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AActorHealthManager, nullptr, "GetHealth", nullptr, nullptr, sizeof(Z_Construct_UFunction_AActorHealthManager_GetHealth_Statics::ActorHealthManager_eventGetHealth_Parms), Z_Construct_UFunction_AActorHealthManager_GetHealth_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AActorHealthManager_GetHealth_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AActorHealthManager_GetHealth_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AActorHealthManager_GetHealth_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AActorHealthManager_GetHealth()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AActorHealthManager_GetHealth_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AActorHealthManager_HealActor_Statics
	{
		struct ActorHealthManager_eventHealActor_Parms
		{
			AActor* Actor;
			float HealAmount;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Actor;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_HealAmount;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AActorHealthManager_HealActor_Statics::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ActorHealthManager_eventHealActor_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AActorHealthManager_HealActor_Statics::NewProp_HealAmount = { "HealAmount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ActorHealthManager_eventHealActor_Parms, HealAmount), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AActorHealthManager_HealActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AActorHealthManager_HealActor_Statics::NewProp_Actor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AActorHealthManager_HealActor_Statics::NewProp_HealAmount,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AActorHealthManager_HealActor_Statics::Function_MetaDataParams[] = {
		{ "Category", "Health" },
		{ "Comment", "// Restores health to a specified actor, increasing its health by the specified heal amount, and ensuring it does not exceed the MaxHealth value\n" },
		{ "ModuleRelativePath", "Private/ActorHealthManager.h" },
		{ "ToolTip", "Restores health to a specified actor, increasing its health by the specified heal amount, and ensuring it does not exceed the MaxHealth value" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AActorHealthManager_HealActor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AActorHealthManager, nullptr, "HealActor", nullptr, nullptr, sizeof(Z_Construct_UFunction_AActorHealthManager_HealActor_Statics::ActorHealthManager_eventHealActor_Parms), Z_Construct_UFunction_AActorHealthManager_HealActor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AActorHealthManager_HealActor_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AActorHealthManager_HealActor_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AActorHealthManager_HealActor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AActorHealthManager_HealActor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AActorHealthManager_HealActor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AActorHealthManager_RegisterActor_Statics
	{
		struct ActorHealthManager_eventRegisterActor_Parms
		{
			AActor* Actor;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Actor;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AActorHealthManager_RegisterActor_Statics::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ActorHealthManager_eventRegisterActor_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AActorHealthManager_RegisterActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AActorHealthManager_RegisterActor_Statics::NewProp_Actor,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AActorHealthManager_RegisterActor_Statics::Function_MetaDataParams[] = {
		{ "Category", "Health" },
		{ "Comment", "// Registers an actor with the health manager, setting its health to the default health value\n" },
		{ "ModuleRelativePath", "Private/ActorHealthManager.h" },
		{ "ToolTip", "Registers an actor with the health manager, setting its health to the default health value" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AActorHealthManager_RegisterActor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AActorHealthManager, nullptr, "RegisterActor", nullptr, nullptr, sizeof(Z_Construct_UFunction_AActorHealthManager_RegisterActor_Statics::ActorHealthManager_eventRegisterActor_Parms), Z_Construct_UFunction_AActorHealthManager_RegisterActor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AActorHealthManager_RegisterActor_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AActorHealthManager_RegisterActor_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AActorHealthManager_RegisterActor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AActorHealthManager_RegisterActor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AActorHealthManager_RegisterActor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AActorHealthManager_SetHealth_Statics
	{
		struct ActorHealthManager_eventSetHealth_Parms
		{
			AActor* Actor;
			float HealthValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Actor;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_HealthValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AActorHealthManager_SetHealth_Statics::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ActorHealthManager_eventSetHealth_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AActorHealthManager_SetHealth_Statics::NewProp_HealthValue = { "HealthValue", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ActorHealthManager_eventSetHealth_Parms, HealthValue), METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AActorHealthManager_SetHealth_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AActorHealthManager_SetHealth_Statics::NewProp_Actor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AActorHealthManager_SetHealth_Statics::NewProp_HealthValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AActorHealthManager_SetHealth_Statics::Function_MetaDataParams[] = {
		{ "Category", "Health" },
		{ "Comment", "// Sets the health value for a specified actor, ensuring it does not exceed the MaxHealth value\n" },
		{ "ModuleRelativePath", "Private/ActorHealthManager.h" },
		{ "ToolTip", "Sets the health value for a specified actor, ensuring it does not exceed the MaxHealth value" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AActorHealthManager_SetHealth_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AActorHealthManager, nullptr, "SetHealth", nullptr, nullptr, sizeof(Z_Construct_UFunction_AActorHealthManager_SetHealth_Statics::ActorHealthManager_eventSetHealth_Parms), Z_Construct_UFunction_AActorHealthManager_SetHealth_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AActorHealthManager_SetHealth_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AActorHealthManager_SetHealth_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AActorHealthManager_SetHealth_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AActorHealthManager_SetHealth()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AActorHealthManager_SetHealth_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AActorHealthManager_TestActorHealthInEditor_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AActorHealthManager_TestActorHealthInEditor_Statics::Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "Category", "Editor" },
		{ "Comment", "// Tests the current health of all registered actors in the editor, outputting the results to the log or other editor UI\n" },
		{ "ModuleRelativePath", "Private/ActorHealthManager.h" },
		{ "ToolTip", "Tests the current health of all registered actors in the editor, outputting the results to the log or other editor UI" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AActorHealthManager_TestActorHealthInEditor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AActorHealthManager, nullptr, "TestActorHealthInEditor", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AActorHealthManager_TestActorHealthInEditor_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AActorHealthManager_TestActorHealthInEditor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AActorHealthManager_TestActorHealthInEditor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AActorHealthManager_TestActorHealthInEditor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AActorHealthManager_UnregisterActor_Statics
	{
		struct ActorHealthManager_eventUnregisterActor_Parms
		{
			AActor* Actor;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Actor;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AActorHealthManager_UnregisterActor_Statics::NewProp_Actor = { "Actor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(ActorHealthManager_eventUnregisterActor_Parms, Actor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AActorHealthManager_UnregisterActor_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AActorHealthManager_UnregisterActor_Statics::NewProp_Actor,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AActorHealthManager_UnregisterActor_Statics::Function_MetaDataParams[] = {
		{ "Category", "Health" },
		{ "Comment", "// Unregisters an actor from the health manager, removing its health data\n" },
		{ "ModuleRelativePath", "Private/ActorHealthManager.h" },
		{ "ToolTip", "Unregisters an actor from the health manager, removing its health data" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AActorHealthManager_UnregisterActor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AActorHealthManager, nullptr, "UnregisterActor", nullptr, nullptr, sizeof(Z_Construct_UFunction_AActorHealthManager_UnregisterActor_Statics::ActorHealthManager_eventUnregisterActor_Parms), Z_Construct_UFunction_AActorHealthManager_UnregisterActor_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AActorHealthManager_UnregisterActor_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AActorHealthManager_UnregisterActor_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AActorHealthManager_UnregisterActor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AActorHealthManager_UnregisterActor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AActorHealthManager_UnregisterActor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AActorHealthManager);
	UClass* Z_Construct_UClass_AActorHealthManager_NoRegister()
	{
		return AActorHealthManager::StaticClass();
	}
	struct Z_Construct_UClass_AActorHealthManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultHealth_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_DefaultHealth;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxHealth_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxHealth;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bShowHealthInEditor_MetaData[];
#endif
		static void NewProp_bShowHealthInEditor_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bShowHealthInEditor;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_HealthData_ValueProp;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_HealthData_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HealthData_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_HealthData;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AActorHealthManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_CosmicBulletHell,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AActorHealthManager_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AActorHealthManager_ApplyDamage, "ApplyDamage" }, // 4057871541
		{ &Z_Construct_UFunction_AActorHealthManager_GetHealth, "GetHealth" }, // 724432327
		{ &Z_Construct_UFunction_AActorHealthManager_HealActor, "HealActor" }, // 3453924983
		{ &Z_Construct_UFunction_AActorHealthManager_RegisterActor, "RegisterActor" }, // 1373598526
		{ &Z_Construct_UFunction_AActorHealthManager_SetHealth, "SetHealth" }, // 3502136414
		{ &Z_Construct_UFunction_AActorHealthManager_TestActorHealthInEditor, "TestActorHealthInEditor" }, // 3686799869
		{ &Z_Construct_UFunction_AActorHealthManager_UnregisterActor, "UnregisterActor" }, // 2164125540
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AActorHealthManager_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * A class to manage health for actors in a game, with functionality for registering and unregistering actors,\n * setting and getting health values, applying damage, healing actors, and testing actor health in the editor.\n */" },
		{ "IncludePath", "ActorHealthManager.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Private/ActorHealthManager.h" },
		{ "ToolTip", "A class to manage health for actors in a game, with functionality for registering and unregistering actors,\nsetting and getting health values, applying damage, healing actors, and testing actor health in the editor." },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AActorHealthManager_Statics::NewProp_DefaultHealth_MetaData[] = {
		{ "Category", "Health" },
		{ "Comment", "// The default health value for actors when they are registered\n" },
		{ "ModuleRelativePath", "Private/ActorHealthManager.h" },
		{ "ToolTip", "The default health value for actors when they are registered" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AActorHealthManager_Statics::NewProp_DefaultHealth = { "DefaultHealth", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AActorHealthManager, DefaultHealth), METADATA_PARAMS(Z_Construct_UClass_AActorHealthManager_Statics::NewProp_DefaultHealth_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AActorHealthManager_Statics::NewProp_DefaultHealth_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AActorHealthManager_Statics::NewProp_MaxHealth_MetaData[] = {
		{ "Category", "Health" },
		{ "Comment", "// The maximum health value that actors can have\n" },
		{ "ModuleRelativePath", "Private/ActorHealthManager.h" },
		{ "ToolTip", "The maximum health value that actors can have" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AActorHealthManager_Statics::NewProp_MaxHealth = { "MaxHealth", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AActorHealthManager, MaxHealth), METADATA_PARAMS(Z_Construct_UClass_AActorHealthManager_Statics::NewProp_MaxHealth_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AActorHealthManager_Statics::NewProp_MaxHealth_MetaData)) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AActorHealthManager_Statics::NewProp_bShowHealthInEditor_MetaData[] = {
		{ "Category", "Editor" },
		{ "Comment", "// A flag to indicate whether to show actors' health in the editor\n" },
		{ "ModuleRelativePath", "Private/ActorHealthManager.h" },
		{ "ToolTip", "A flag to indicate whether to show actors' health in the editor" },
	};
#endif
	void Z_Construct_UClass_AActorHealthManager_Statics::NewProp_bShowHealthInEditor_SetBit(void* Obj)
	{
		((AActorHealthManager*)Obj)->bShowHealthInEditor = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AActorHealthManager_Statics::NewProp_bShowHealthInEditor = { "bShowHealthInEditor", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, sizeof(bool), sizeof(AActorHealthManager), &Z_Construct_UClass_AActorHealthManager_Statics::NewProp_bShowHealthInEditor_SetBit, METADATA_PARAMS(Z_Construct_UClass_AActorHealthManager_Statics::NewProp_bShowHealthInEditor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AActorHealthManager_Statics::NewProp_bShowHealthInEditor_MetaData)) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AActorHealthManager_Statics::NewProp_HealthData_ValueProp = { "HealthData", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 1, METADATA_PARAMS(nullptr, 0) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AActorHealthManager_Statics::NewProp_HealthData_Key_KeyProp = { "HealthData_Key", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, 0, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AActorHealthManager_Statics::NewProp_HealthData_MetaData[] = {
		{ "Comment", "// A map that stores a reference to actors and their current health values\n" },
		{ "ModuleRelativePath", "Private/ActorHealthManager.h" },
		{ "ToolTip", "A map that stores a reference to actors and their current health values" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_AActorHealthManager_Statics::NewProp_HealthData = { "HealthData", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, nullptr, nullptr, STRUCT_OFFSET(AActorHealthManager, HealthData), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AActorHealthManager_Statics::NewProp_HealthData_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AActorHealthManager_Statics::NewProp_HealthData_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AActorHealthManager_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActorHealthManager_Statics::NewProp_DefaultHealth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActorHealthManager_Statics::NewProp_MaxHealth,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActorHealthManager_Statics::NewProp_bShowHealthInEditor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActorHealthManager_Statics::NewProp_HealthData_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActorHealthManager_Statics::NewProp_HealthData_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActorHealthManager_Statics::NewProp_HealthData,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AActorHealthManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AActorHealthManager>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AActorHealthManager_Statics::ClassParams = {
		&AActorHealthManager::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AActorHealthManager_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AActorHealthManager_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AActorHealthManager_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AActorHealthManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AActorHealthManager()
	{
		if (!Z_Registration_Info_UClass_AActorHealthManager.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AActorHealthManager.OuterSingleton, Z_Construct_UClass_AActorHealthManager_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AActorHealthManager.OuterSingleton;
	}
	template<> COSMICBULLETHELL_API UClass* StaticClass<AActorHealthManager>()
	{
		return AActorHealthManager::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AActorHealthManager);
	AActorHealthManager::~AActorHealthManager() {}
	struct Z_CompiledInDeferFile_FID_anthony_Documents_GitHub_Cosmic_Horror_Jam_II_CosmicBulletHell_Source_CosmicBulletHell_Private_ActorHealthManager_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_anthony_Documents_GitHub_Cosmic_Horror_Jam_II_CosmicBulletHell_Source_CosmicBulletHell_Private_ActorHealthManager_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AActorHealthManager, AActorHealthManager::StaticClass, TEXT("AActorHealthManager"), &Z_Registration_Info_UClass_AActorHealthManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AActorHealthManager), 3129012338U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_anthony_Documents_GitHub_Cosmic_Horror_Jam_II_CosmicBulletHell_Source_CosmicBulletHell_Private_ActorHealthManager_h_2048361875(TEXT("/Script/CosmicBulletHell"),
		Z_CompiledInDeferFile_FID_anthony_Documents_GitHub_Cosmic_Horror_Jam_II_CosmicBulletHell_Source_CosmicBulletHell_Private_ActorHealthManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_anthony_Documents_GitHub_Cosmic_Horror_Jam_II_CosmicBulletHell_Source_CosmicBulletHell_Private_ActorHealthManager_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
