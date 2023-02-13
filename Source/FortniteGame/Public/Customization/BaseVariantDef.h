// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "McpItemDefinitionBase.h"
#include "GameplayTags.h"
#include "FortniteGame/FortniteGame.h"
#include "Particles/ParticleSystem.h"
#include "NiagaraSystem.h"
#include "Customization/CustomCharacterPart.h"
#include "BaseVariantDef.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FBaseVariantDef
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		bool bStartUnlocked = false;

	UPROPERTY(EditAnywhere)
		bool bIsDefault = false;

	UPROPERTY(EditAnywhere)
		bool bHideIfNotOwned = false;

	UPROPERTY(EditAnywhere)
		FGameplayTag CustomizationVariantTag;

	UPROPERTY(EditAnywhere)
		FText VariantName;

	UPROPERTY(EditAnywhere)
		TSoftObjectPtr<UTexture2D> PreviewImage;

	UPROPERTY(EditAnywhere)
		FText UnlockRequirements;

	UPROPERTY(EditAnywhere)
		TSoftObjectPtr<UMcpItemDefinitionBase> UnlockingItemDef;
};

USTRUCT(BlueprintType)
struct FMaterialParamName
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		FName ParamName;
};

USTRUCT(BlueprintType)
struct FMaterialVariants
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		TSoftObjectPtr<UMaterialInterface> MaterialToSwap;

	UPROPERTY(EditAnywhere)
		FName ComponentToOverride;

	UPROPERTY(EditAnywhere)
		FName CascadeMaterialName;

	UPROPERTY(EditAnywhere)
		int MaterialOverrideIndex = 0;

	UPROPERTY(EditAnywhere)
		TSoftObjectPtr<UMaterialInterface> OverrideMaterial;
};

USTRUCT(BlueprintType)
struct FMaterialVariantDef : public FBaseVariantDef
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		TArray<FMaterialVariants> VariantMaterials;

};

USTRUCT(BlueprintType)
struct FMaterialTextureVariant : public FMaterialParamName
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		TSoftObjectPtr<UTexture> Value;
};

USTRUCT(BlueprintType)
struct FMaterialFloatVariant : public FMaterialParamName
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		float Value = 0.0f;
};

USTRUCT(BlueprintType)
struct FMaterialVectorVariant : public FMaterialParamName
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, meta = (IgnoreForMemberInitializationTest))
		FLinearColor Value;
};

USTRUCT(BlueprintType)
struct FMaterialParamterDef
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		TSoftObjectPtr<UMaterialInterface> MaterialToAlter;

	UPROPERTY(EditAnywhere)
		FName CascadeMaterialName;

	UPROPERTY(EditAnywhere)
		TArray<FMaterialVectorVariant> ColorParams;

	UPROPERTY(EditAnywhere)
		TArray<FMaterialTextureVariant> TextureParams;

	UPROPERTY(EditAnywhere)
		TArray<FMaterialFloatVariant> FloatParams;
};


USTRUCT(BlueprintType)
struct FParticleVariant
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
		TSoftObjectPtr<UFXSystemAsset> ParticleSystemToAlter;

	UPROPERTY(EditAnywhere)
		FName ComponentToOverride;

	UPROPERTY(EditAnywhere)
	   TSoftObjectPtr<UFXSystemAsset> OverrideParticleSystem; 
};

USTRUCT(BlueprintType)
struct FVectorParticleParameter
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, meta = (IgnoreForMemberInitializationTest))
		FVector Value;

	UPROPERTY(EditAnywhere)
		FName                       ParameterName;

};

USTRUCT(BlueprintType)
struct FVectorParamVariant : public FMaterialParamName
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, meta = (IgnoreForMemberInitializationTest))
		FVector Value;
};

USTRUCT(BlueprintType)
struct FParticleParamterVariant
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
		TArray<FMaterialVectorVariant> ColorParams;

	UPROPERTY(EditAnywhere)
		TArray<FVectorParamVariant>  VectorParams;

	UPROPERTY(EditAnywhere)
		TArray<FMaterialFloatVariant> FloatParams;
};

USTRUCT(BlueprintType)
struct FFortPortableSoftParticles 
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	EFXType FXType = EFXType::BackpackBling; 

	UPROPERTY(EditAnywhere)
	 TSoftObjectPtr<UNiagaraSystem> NiagaraVersion;

	UPROPERTY(EditAnywhere)
	 TSoftObjectPtr<UParticleSystem> CascadeVersion; 
};

USTRUCT(BlueprintType)
struct FManagedParticleSwapVariant
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere)
	FGameplayTag  ParamGroupTag;
	
	UPROPERTY(EditAnywhere)
		FFortPortableSoftParticles ParticleToOverride;
};

USTRUCT(BlueprintType)
struct FManagedParticleParamVariant
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere)
	FGameplayTag ParamGroupTag;

	UPROPERTY(EditAnywhere)
		TArray<FMaterialVectorVariant> ColorParams;

	UPROPERTY(EditAnywhere)
		TArray<FVectorParamVariant>  VectorParams;

	UPROPERTY(EditAnywhere)
		TArray<FMaterialFloatVariant> FloatParams;
};

USTRUCT(BlueprintType)
struct FFoleySoundVariant
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		TArray<UObject*> LibrariesToAdd;

	UPROPERTY(EditAnywhere)
		TArray<UObject*> LibrariesToRemove;

};

USTRUCT(BlueprintType)
struct FSocketTransformVariant
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		FName SourceSocketName;

	UPROPERTY(EditAnywhere)
		FName  OverridSocketName;
};

USTRUCT(BlueprintType)
struct FScriptedActionVariant
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		FGameplayTag ActionTag;
};

USTRUCT(BlueprintType)
struct FCosmeticMetaTagContainer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		FGameplayTagContainer MetaTagsToApply;

	UPROPERTY(EditAnywhere)
		FGameplayTagContainer MetaTagsToRemove;
};

USTRUCT(BlueprintType)
struct FScriptedActionVariantDef
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	TArray<FScriptedActionVariant> VariantActions;

	UPROPERTY(EditAnywhere)
	FCosmeticMetaTagContainer MetaTags;
};

USTRUCT(BlueprintType)
struct FPartVariantDef : public FBaseVariantDef
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		TArray<TSoftObjectPtr<UCustomCharacterPart>> VariantParts;

	UPROPERTY(EditAnywhere)
		TArray<FMaterialVariants> VariantMaterials;

	UPROPERTY(EditAnywhere)
		TArray<FMaterialParamterDef> VariantMaterialParams;
	/*
	UPROPERTY(EditAnywhere)
	TArray<FVariantParticleSystemInitializerData> InitalParticelSystemData;
	*/
	UPROPERTY(EditAnywhere)
		TArray<FParticleVariant> VariantParticles;

	UPROPERTY(EditAnywhere)
		TArray<FParticleParamterVariant> VariantParticleParams;

	UPROPERTY(EditAnywhere)
		TArray<FManagedParticleSwapVariant> VariantSwapInParticles;

	UPROPERTY(EditAnywhere)
		TArray<FManagedParticleParamVariant> VariantAlteredParticleParams;

	UPROPERTY(EditAnywhere)
		TArray<FFoleySoundVariant> VariantFoley;

	UPROPERTY(EditAnywhere)
		TArray<FSocketTransformVariant> SocketTransforms;

	UPROPERTY(EditAnywhere)
		TArray<FScriptedActionVariant> VariantActions;

	UPROPERTY(EditAnywhere)
		FCosmeticMetaTagContainer MetaTags;

};