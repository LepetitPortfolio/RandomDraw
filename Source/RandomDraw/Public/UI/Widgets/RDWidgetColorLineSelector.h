// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Widgets/RDWidgetBase.h"
#include "RDWidgetColorLineSelector.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDWidgetColorLineSelector : public URDWidgetBase
{
	GENERATED_BODY()
	
public :
	/**
	* Initializes the values
	* @param _Color - Color proposed
	* @param _ColorSelector - Widget parent
	*/
	void InitValues(FLinearColor _Color , class URDWidgetColorSelector* _ColorSelector);

protected:

	/* Widget parent */
	UPROPERTY(BlueprintReadOnly, Category = ColorLineSelector)
		class URDWidgetColorSelector* m_ColorSelector;

	/* Color proposed */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ColorLineSelector)
		FLinearColor m_Color = FLinearColor::Black;

	/**
	* Select the color of widget
	*/
	UFUNCTION(BlueprintCallable, Category = ColorLineSelector)
		void SelectColor();

};
