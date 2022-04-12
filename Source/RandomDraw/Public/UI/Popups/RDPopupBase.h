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

	/**
	* UE4 Function : Called when the object is construct
	*/
	virtual void NativeOnInitialized() override;
	/**
	* UE4 Function : Called just before to display the UMG
	*/
	virtual void NativeConstruct() override;

	/**
	* Remove the popup
	*/
	UFUNCTION(BlueprintCallable, Category = PopupBase)
		void ClosePopup();
};
