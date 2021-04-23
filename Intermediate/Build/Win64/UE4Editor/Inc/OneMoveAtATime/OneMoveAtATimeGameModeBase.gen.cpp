// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OneMoveAtATime/OneMoveAtATimeGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOneMoveAtATimeGameModeBase() {}
// Cross Module References
	ONEMOVEATATIME_API UClass* Z_Construct_UClass_AOneMoveAtATimeGameModeBase_NoRegister();
	ONEMOVEATATIME_API UClass* Z_Construct_UClass_AOneMoveAtATimeGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_OneMoveAtATime();
// End Cross Module References
	void AOneMoveAtATimeGameModeBase::StaticRegisterNativesAOneMoveAtATimeGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AOneMoveAtATimeGameModeBase_NoRegister()
	{
		return AOneMoveAtATimeGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AOneMoveAtATimeGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AOneMoveAtATimeGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_OneMoveAtATime,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOneMoveAtATimeGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "OneMoveAtATimeGameModeBase.h" },
		{ "ModuleRelativePath", "OneMoveAtATimeGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AOneMoveAtATimeGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AOneMoveAtATimeGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AOneMoveAtATimeGameModeBase_Statics::ClassParams = {
		&AOneMoveAtATimeGameModeBase::StaticClass,
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
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AOneMoveAtATimeGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AOneMoveAtATimeGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AOneMoveAtATimeGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AOneMoveAtATimeGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AOneMoveAtATimeGameModeBase, 1066299120);
	template<> ONEMOVEATATIME_API UClass* StaticClass<AOneMoveAtATimeGameModeBase>()
	{
		return AOneMoveAtATimeGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AOneMoveAtATimeGameModeBase(Z_Construct_UClass_AOneMoveAtATimeGameModeBase, &AOneMoveAtATimeGameModeBase::StaticClass, TEXT("/Script/OneMoveAtATime"), TEXT("AOneMoveAtATimeGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AOneMoveAtATimeGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
