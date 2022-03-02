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

	void InitValues(FLinearColor _Color , class URDWidgetColorSelector* _ColorSelector);

protected:

	UPROPERTY(BlueprintReadOnly, Category = ColorLineSelector)
		class URDWidgetColorSelector* m_ColorSelector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ColorLineSelector)
		FLinearColor m_Color = FLinearColor::Black;

	UFUNCTION(BlueprintCallable, Category = ColorLineSelector)
		void Select();

};
