// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Widgets/RDWidgetBase.h"
#include "Structs/RDGroup.h"
#include "RDWidgetGroupBase.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDWidgetGroupBase : public URDWidgetBase
{
	GENERATED_BODY()

public:

	/**
	* Return the reference of group
	* @return reference of the group
	*/
	inline FRDGroup* GetGroup() { return m_Group; }

protected:

	FRDGroup* m_Group = nullptr;
	
	UFUNCTION(BlueprintGetter, Category = WidgetGroupBase)
	FSlateColor GetColorSelfGroup();

};
