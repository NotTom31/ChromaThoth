// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CosmicBulletHell/Private/PlayerControllerInputManager.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlayerControllerInputManager() {}
// Cross Module References
	COSMICBULLETHELL_API UClass* Z_Construct_UClass_APlayerControllerInputManager();
	COSMICBULLETHELL_API UClass* Z_Construct_UClass_APlayerControllerInputManager_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	UPackage* Z_Construct_UPackage__Script_CosmicBulletHell();
// End Cross Module References
	void APlayerControllerInputManager::StaticRegisterNativesAPlayerControllerInputManager()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(APlayerControllerInputManager);
	UClass* Z_Construct_UClass_APlayerControllerInputManager_NoRegister()
	{
		return APlayerControllerInputManager::StaticClass();
	}
	struct Z_Construct_UClass_APlayerControllerInputManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APlayerControllerInputManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_CosmicBulletHell,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APlayerControllerInputManager_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "PlayerControllerInputManager.h" },
		{ "ModuleRelativePath", "Private/PlayerControllerInputManager.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_APlayerControllerInputManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APlayerControllerInputManager>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_APlayerControllerInputManager_Statics::ClassParams = {
		&APlayerControllerInputManager::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008002A4u,
		METADATA_PARAMS(Z_Construct_UClass_APlayerControllerInputManager_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APlayerControllerInputManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APlayerControllerInputManager()
	{
		if (!Z_Registration_Info_UClass_APlayerControllerInputManager.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_APlayerControllerInputManager.OuterSingleton, Z_Construct_UClass_APlayerControllerInputManager_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_APlayerControllerInputManager.OuterSingleton;
	}
	template<> COSMICBULLETHELL_API UClass* StaticClass<APlayerControllerInputManager>()
	{
		return APlayerControllerInputManager::StaticClass();
	}
	APlayerControllerInputManager::APlayerControllerInputManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(APlayerControllerInputManager);
	APlayerControllerInputManager::~APlayerControllerInputManager() {}
	struct Z_CompiledInDeferFile_FID_anthony_Documents_GitHub_Cosmic_Horror_Jam_II_CosmicBulletHell_Source_CosmicBulletHell_Private_PlayerControllerInputManager_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_anthony_Documents_GitHub_Cosmic_Horror_Jam_II_CosmicBulletHell_Source_CosmicBulletHell_Private_PlayerControllerInputManager_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_APlayerControllerInputManager, APlayerControllerInputManager::StaticClass, TEXT("APlayerControllerInputManager"), &Z_Registration_Info_UClass_APlayerControllerInputManager, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(APlayerControllerInputManager), 2356737894U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_anthony_Documents_GitHub_Cosmic_Horror_Jam_II_CosmicBulletHell_Source_CosmicBulletHell_Private_PlayerControllerInputManager_h_3421100109(TEXT("/Script/CosmicBulletHell"),
		Z_CompiledInDeferFile_FID_anthony_Documents_GitHub_Cosmic_Horror_Jam_II_CosmicBulletHell_Source_CosmicBulletHell_Private_PlayerControllerInputManager_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_anthony_Documents_GitHub_Cosmic_Horror_Jam_II_CosmicBulletHell_Source_CosmicBulletHell_Private_PlayerControllerInputManager_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
