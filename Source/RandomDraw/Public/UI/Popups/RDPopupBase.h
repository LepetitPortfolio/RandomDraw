// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Widgets/RDWidgetBase.h"
#include "RDPopupBase.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDPopupBase : public URDUIBase
{
	GENERATED_BODY()
	
protected:


	virtual void NativeOnInitialized() override;

	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable, Category = PopupBase)
		void ClosePopup();
};
