// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OneMoveAtATime/OMAATGameInstance.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOMAATGameInstance() {}
// Cross Module References
	ONEMOVEATATIME_API UClass* Z_Construct_UClass_UOMAATGameInstance_NoRegister();
	ONEMOVEATATIME_API UClass* Z_Construct_UClass_UOMAATGameInstance();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
	UPackage* Z_Construct_UPackage__Script_OneMoveAtATime();
// End Cross Module References
	void UOMAATGameInstance::StaticRegisterNativesUOMAATGameInstance()
	{
	}
	UClass* Z_Construct_UClass_UOMAATGameInstance_NoRegister()
	{
		return UOMAATGameInstance::StaticClass();
	}
	struct Z_Construct_UClass_UOMAATGameInstance_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UOMAATGameInstance_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_OneMoveAtATime,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UOMAATGameInstance_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "OMAATGameInstance.h" },
		{ "ModuleRelativePath", "OMAATGameInstance.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UOMAATGameInstance_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UOMAATGameInstance>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UOMAATGameInstance_Statics::ClassParams = {
		&UOMAATGameInstance::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A8u,
		METADATA_PARAMS(Z_Construct_UClass_UOMAATGameInstance_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UOMAATGameInstance_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UOMAATGameInstance()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UOMAATGameInstance_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UOMAATGameInstance, 1877181983);
	template<> ONEMOVEATATIME_API UClass* StaticClass<UOMAATGameInstance>()
	{
		return UOMAATGameInstance::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UOMAATGameInstance(Z_Construct_UClass_UOMAATGameInstance, &UOMAATGameInstance::StaticClass, TEXT("/Script/OneMoveAtATime"), TEXT("UOMAATGameInstance"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UOMAATGameInstance);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
