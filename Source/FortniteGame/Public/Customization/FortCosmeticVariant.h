// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTags.h"
#include "Items/FortItemDefinition.h"
#include "Items/FortAccountItemDefinition.h"
#include "Customization/BaseVariantDef.h"
#include "FortCosmeticVariant.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FMcpVariantChannelInfo
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FGameplayTagContainer OwnedVariantTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (IgnoreForMemberInitializationTest))
		UFortItemDefinition* ItemVariantIsUsedFor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FString CustomData;
};

USTRUCT(BlueprintType)
struct FFortCosmeticVariantPreviewElement
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<FMcpVariantChannelInfo> VariantOptions;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		UFortAccountItemDefinition* Item = nullptr;
};

USTRUCT(BlueprintType)
struct FFortCosmeticVariantPreview
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FText UnlockCondition;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float PreviewTime = 0;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<FMcpVariantChannelInfo> VariantOptions;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<FFortCosmeticVariantPreviewElement> AdditionalItems;
};

UCLASS(DefaultToInstanced, EditInlineNew)
class FORTNITEGAME_API UFortCosmeticVariant : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
		TSoftObjectPtr<UMaterialInterface> CustomPreviewTileMaterial;

	UPROPERTY(EditAnywhere)
		FGameplayTag VariantChannelTag;

	UPROPERTY(EditAnywhere)
		FText VariantChannelName;

	UPROPERTY(EditAnywhere)
		FGameplayTag ActiveVariantTag;
};

UCLASS(DefaultToInstanced, EditInlineNew)
class FORTNITEGAME_API UFortCosmeticVariantBackedByArray : public UFortCosmeticVariant
{
	GENERATED_BODY()
};

UCLASS(BlueprintType)
class UFortCosmeticMaterialVariant : public UFortCosmeticVariantBackedByArray
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		TArray<FMaterialVariantDef> MaterialOptions;
};

UCLASS(BlueprintType)
class UFortCosmeticCharacterPartVariant : public UFortCosmeticVariantBackedByArray
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		TArray<FPartVariantDef> PartOptions;
};
