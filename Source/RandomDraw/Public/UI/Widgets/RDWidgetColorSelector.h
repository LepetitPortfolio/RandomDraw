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

	inline FLinearColor GetColor() { return m_Color; }

	void ChangeColorSelected(FLinearColor _Color);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = ColorSelector)
		TSubclassOf<URDWidgetColorLineSelector> m_ColorSelectorTemplate;

	UPROPERTY(BlueprintReadOnly, Category = ColorSelector, meta = (BindWidget))
		UScrollBox* m_ScrollBox = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = ColorSelector, meta = (BindWidget))
		UVerticalBox* m_WidgetList = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = ColorSelector)
		FLinearColor m_Color = FLinearColor::Black;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = ColorSelector)
		TArray<FLinearColor> m_DefaultColors;

	virtual void NativeOnInitialized() override;

	virtual void NativeConstruct() override;
	
};
