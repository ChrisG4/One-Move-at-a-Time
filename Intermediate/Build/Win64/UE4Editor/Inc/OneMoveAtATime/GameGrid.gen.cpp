// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OneMoveAtATime/Game Grid/GameGrid.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameGrid() {}
// Cross Module References
	ONEMOVEATATIME_API UClass* Z_Construct_UClass_AGameGrid_NoRegister();
	ONEMOVEATATIME_API UClass* Z_Construct_UClass_AGameGrid();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_OneMoveAtATime();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ONEMOVEATATIME_API UClass* Z_Construct_UClass_AGridBox_NoRegister();
// End Cross Module References
	void AGameGrid::StaticRegisterNativesAGameGrid()
	{
	}
	UClass* Z_Construct_UClass_AGameGrid_NoRegister()
	{
		return AGameGrid::StaticClass();
	}
	struct Z_Construct_UClass_AGameGrid_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GridBoxType_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_GridBoxType;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGameGrid_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_OneMoveAtATime,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameGrid_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Game Grid/GameGrid.h" },
		{ "ModuleRelativePath", "Game Grid/GameGrid.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameGrid_Statics::NewProp_GridBoxType_MetaData[] = {
		{ "Category", "GameGrid" },
		{ "ModuleRelativePath", "Game Grid/GameGrid.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AGameGrid_Statics::NewProp_GridBoxType = { "GridBoxType", nullptr, (EPropertyFlags)0x0024080000010001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGameGrid, GridBoxType), Z_Construct_UClass_AGridBox_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AGameGrid_Statics::NewProp_GridBoxType_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGameGrid_Statics::NewProp_GridBoxType_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGameGrid_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameGrid_Statics::NewProp_GridBoxType,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGameGrid_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGameGrid>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGameGrid_Statics::ClassParams = {
		&AGameGrid::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AGameGrid_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AGameGrid_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AGameGrid_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AGameGrid_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGameGrid()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGameGrid_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGameGrid, 179124672);
	template<> ONEMOVEATATIME_API UClass* StaticClass<AGameGrid>()
	{
		return AGameGrid::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGameGrid(Z_Construct_UClass_AGameGrid, &AGameGrid::StaticClass, TEXT("/Script/OneMoveAtATime"), TEXT("AGameGrid"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGameGrid);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
