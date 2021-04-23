// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OneMoveAtATime/Game Grid/GridBox.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGridBox() {}
// Cross Module References
	ONEMOVEATATIME_API UClass* Z_Construct_UClass_AGridBox_NoRegister();
	ONEMOVEATATIME_API UClass* Z_Construct_UClass_AGridBox();
	ENGINE_API UClass* Z_Construct_UClass_ATriggerBox();
	UPackage* Z_Construct_UPackage__Script_OneMoveAtATime();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
// End Cross Module References
	void AGridBox::StaticRegisterNativesAGridBox()
	{
	}
	UClass* Z_Construct_UClass_AGridBox_NoRegister()
	{
		return AGridBox::StaticClass();
	}
	struct Z_Construct_UClass_AGridBox_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GridCoord_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_GridCoord;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGridBox_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ATriggerBox,
		(UObject* (*)())Z_Construct_UPackage__Script_OneMoveAtATime,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGridBox_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Game Grid/GridBox.h" },
		{ "ModuleRelativePath", "Game Grid/GridBox.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGridBox_Statics::NewProp_GridCoord_MetaData[] = {
		{ "Category", "GridBox" },
		{ "ModuleRelativePath", "Game Grid/GridBox.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AGridBox_Statics::NewProp_GridCoord = { "GridCoord", nullptr, (EPropertyFlags)0x0020080000020001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGridBox, GridCoord), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UClass_AGridBox_Statics::NewProp_GridCoord_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGridBox_Statics::NewProp_GridCoord_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGridBox_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGridBox_Statics::NewProp_GridCoord,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGridBox_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGridBox>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGridBox_Statics::ClassParams = {
		&AGridBox::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AGridBox_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AGridBox_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AGridBox_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AGridBox_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGridBox()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGridBox_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGridBox, 2212855596);
	template<> ONEMOVEATATIME_API UClass* StaticClass<AGridBox>()
	{
		return AGridBox::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGridBox(Z_Construct_UClass_AGridBox, &AGridBox::StaticClass, TEXT("/Script/OneMoveAtATime"), TEXT("AGridBox"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGridBox);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
