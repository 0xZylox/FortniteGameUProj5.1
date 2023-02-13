// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItemDefinition.h"
#include "GameplayTags.h"
#include "Customization/FortCosmeticVariant.h"
#include "Particles/ParticleSystem.h"
#include "AthenaCosmeticItemDefinition.generated.h"

class UAthenaCharacterItemDefinition;
class UFortMontageItemDefinitionBase;

USTRUCT(BlueprintType)
struct FFortStatManagerTag : public FGameplayTag
{
	GENERATED_BODY()

public:

};

UCLASS(DefaultToInstanced, EditInlineNew)
class UFortCosmeticItemAdditionalData : public UObject
{
	GENERATED_BODY()

public:

};

UCLASS(DefaultToInstanced, EditInlineNew)
class UFortVariantPreviewGenerator : public UObject
{
	GENERATED_BODY()

public:

};

USTRUCT(BlueprintType)
struct FAthenaCosmeticMaterialOverride
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FName ComponentName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		int MaterialOverrideIndex = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftObjectPtr<UMaterialInterface> OverrideMaterial;
};

USTRUCT(BlueprintType)
struct FCosmeticVariantInfo
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FGameplayTag VariantChannelTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FGameplayTag ActiveVariantTag;
};


USTRUCT(BlueprintType)
struct FFortCosmeticAdaptiveStatPair 
{

	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	FFortStatManagerTag StatTag;

	UPROPERTY(EditAnywhere)
	int StatValue = 0; 
};

USTRUCT(BlueprintType)
struct FFortCosmeticAdaptiveStatPreview
{

	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	FText UnlockCondition;

	UPROPERTY(EditAnywhere)
	TArray<FFortCosmeticAdaptiveStatPair> StatValues; 
};


UCLASS(BlueprintType)
class FORTNITEGAME_API UAthenaCosmeticItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
		bool bIsShuffleTile;

	UPROPERTY(EditAnywhere)
		bool bIsOwnedByCampaignHero;

	UPROPERTY(EditAnywhere)
		bool bHasMoreThanOneCharacterPartVariant;

	UPROPERTY(EditAnywhere)
		bool bHideIfNotOwned;

	UPROPERTY(EditAnywhere)
		bool bInitializedConfiguredDynamicInstallBundles;

	UPROPERTY(EditAnywhere)
		bool bDynamicInstallBundlesError;

	UPROPERTY(EditAnywhere)
		bool bDynamicInstallBundlesCancelled;

	UPROPERTY(EditAnywhere)
		bool bDynamicInstallBundlesComplete;

	UPROPERTY(EditAnywhere)
		double DynamicInstallBundlesUpdateStartTime;

	UPROPERTY(EditAnywhere)		
		double DynamicInstallBundlesUpdateTotalTime;

	UPROPERTY(EditAnywhere)
	 int DynamicInstallBundleRequestRefCount;

	UPROPERTY(EditAnywhere)
	 int DynamicInstallBundleRequestRetryCount;

	UPROPERTY(EditAnywhere)
	    EVariantUnlockType VariantUnlockType;

	UPROPERTY(EditAnywhere)
		FRotator PreviewPawnRotationOffset;

	UPROPERTY(EditAnywhere)
		TArray<UObject*> FoleyLibraries;

	UPROPERTY(EditAnywhere)
		FGameplayTagContainer DisallowedCosmeticTags;

	UPROPERTY(EditAnywhere)
		FGameplayTagContainer MetaTags;

	UPROPERTY(EditAnywhere)
		TArray<FGameplayTag> VariantChannelsToNeverSendToMCP;

	UPROPERTY(EditAnywhere)
		TArray<FAthenaCosmeticMaterialOverride> MaterialOverrides;

	UPROPERTY(EditAnywhere)
		FGameplayTagContainer ObservedPlayerStats;

	UPROPERTY(EditAnywhere)
		TArray<UFortMontageItemDefinitionBase*> BuiltInEmotes;

	UPROPERTY(EditAnywhere, Instanced)
		TArray<UFortCosmeticVariant*> ItemVariants;

	UPROPERTY(EditAnywhere, Instanced)
	TArray<UFortCosmeticItemAdditionalData*> AdditionalDataFields;

	UPROPERTY(EditAnywhere)
		FGameplayTag VariantChannelToUseForThumbnails;

	UPROPERTY(EditAnywhere)
	bool bOverrideDefaultVariantPreviewTime;

	UPROPERTY(EditAnywhere)
	float  DefaultVariantPreviewOverrideTime;

	UPROPERTY(EditAnywhere)
		TArray<FortCosmeticVariantPreview> ItemVariantPreviews;

	UPROPERTY(EditAnywhere, Instanced)
	UFortVariantPreviewGenerator* ItemVariantPreviewGenerator;

	UPROPERTY(EditAnywhere)
		FText DirectAquisitionStyleDisclaimerOverride;

	UPROPERTY(EditAnywhere)
	TArray<FFortCosmeticAdaptiveStatPreview> ItemObservedStatPreviews;

	UPROPERTY(EditAnywhere)
		FText UnlockRequirements;

	UPROPERTY(EditAnywhere)
		FText ItemVariantUnlockRequirements;

	UPROPERTY(EditAnywhere)
		TSoftObjectPtr<UFortAccountItemDefinition> UnlockingItemDef;

	UPROPERTY(EditAnywhere)
		FSoftClassPath ItemPreviewActorClass;

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UFXSystemAsset> ItemPreviewParticleSystem;

	UPROPERTY(EditAnywhere)
		TSoftObjectPtr<UAnimMontage> ItemPreviewMontage_Male;

	UPROPERTY(EditAnywhere)
		TSoftObjectPtr<UAnimMontage> ItemPreviewMontage_Female;

	UPROPERTY(EditAnywhere)
		TSoftObjectPtr<UAthenaCharacterItemDefinition> ItemPreviewHero;

	UPROPERTY(EditAnywhere)
		TArray<FName> ConfiguredDynamicInstallBundles;

	UPROPERTY(EditAnywhere)
		TArray<FName> PendingDynamicInstallBundles;

	UPROPERTY(EditAnywhere)
		FGameplayTagContainer ExclusiveRequiresOutfitTags;

	UPROPERTY(EditAnywhere)
		FText CustomExclusiveCallout;

	UPROPERTY(EditAnywhere)
		FText ExclusiveDescription;

	UPROPERTY(EditAnywhere)
		TSoftObjectPtr<UTexture2D> ExclusiveIcon;

	UPROPERTY(EditAnywhere)
	int BaseShotGridId;

	UPROPERTY(EditAnywhere)
	TArray<int> VariantShotGridIds;   

	UPROPERTY(EditAnywhere)
	TArray<int> ShotGridIds;   

	UPROPERTY(EditAnywhere)
	TArray<FText> ItemSearchTags;
};
