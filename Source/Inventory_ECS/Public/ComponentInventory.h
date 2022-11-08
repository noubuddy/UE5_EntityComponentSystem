// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ComponentInventoryCell.h"
#include "UObject/NoExportTypes.h"
#include "ComponentInventory.generated.h"

/**
 * Contains an array of cells
 */
UCLASS()
class UComponentInventory : public UObject
{
	GENERATED_BODY()
	
public:
	// Array of cells
	UPROPERTY(BlueprintReadWrite)
	TArray<UComponentInventoryCell*> Cells;
};
