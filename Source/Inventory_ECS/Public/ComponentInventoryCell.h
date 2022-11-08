// Fill out your copyright notice in the Description page of Project Settings.

// #pragma once

#pragma once

#include "CoreMinimal.h"
#include "ComponentItem.h"
#include "ComponentInventoryCell.generated.h"

/**
 *  Contains data about specific inventory cell (component) \n
 *  ItemType - UComponentItem \n
 *  ItemState - float \n
 *  quantity - int8 \n
 */
UCLASS()
class UComponentInventoryCell : public UObject
{
	GENERATED_BODY()

public:
	// Item, containing in specific cell
	UPROPERTY(BlueprintReadWrite)
	UComponentItem *Item;

	// For instance only. should use custom type !!!
	// State of specific item
	UPROPERTY(BlueprintReadWrite)
	float ItemState;

	// Quantity of specific item
	UPROPERTY(BlueprintReadWrite)
	uint8 quantity;
};
