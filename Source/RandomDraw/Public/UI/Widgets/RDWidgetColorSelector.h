// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Widgets/RDWidgetBase.h"
#include "UI/Widgets/RDWidgetColorLineSelector.h"
#include "Components/ScrollBox.h"
#include "Components/VerticalBox.h"
#include "RDWidgetColorSelector.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDWidgetColorSelector : public URDWidgetBase
{
	GENERATED_BODY()

public:

	/**
	* return the current color selected
	* @return the current color selected
	*/
	inline FLinearColor GetColor() { return m_Color; }

	/**
	* Change the current color selected
	* @param _Color - New color selected
	*/
	void ChangeColorSelected(FLinearColor _Color);

protected:

	/* Color selector template */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = ColorSelector)
		TSubclassOf<URDWidgetColorLineSelector> m_ColorSelectorTemplate;

	/* Reference of scrollbox Widget */
	UPROPERTY(BlueprintReadOnly, Category = ColorSelector, meta = (BindWidget))
		UScrollBox* m_ScrollBox = nullptr;

	/* Reference of VerticalBox Widget where include the list of WidgetColorLineSelector */
	UPROPERTY(BlueprintReadOnly, Category = ColorSelector, meta = (BindWidget))
		UVerticalBox* m_WidgetList = nullptr;

	/* Color Selected */
	UPROPERTY(BlueprintReadOnly, Category = ColorSelector)
		FLinearColor m_Color = FLinearColor::Black;

	/* List of colors possible */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = ColorSelector)
		TArray<FLinearColor> m_DefaultColors;

	/**
	* UE4 Function : Called when the object is construct
	*/
	virtual void NativeOnInitialized() override;
	/**
	* UE4 Function : Called just before to display the UMG
	*/
	virtual void NativeConstruct() override;
	
};
