// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Popups/RDPopupBase.h"
#include "RDPopupShareDrawing.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDPopupShareDrawing : public URDPopupBase
{
	GENERATED_BODY()

public:

	/**
	* Launch the drawing share process
	*/
	UFUNCTION(BlueprintCallable, Category = PopupShareDrawing)
	void ShareDrawing();

protected:

	/* Message */
	UPROPERTY(BlueprintReadWrite, Category = PopupShareDrawing)
	FString m_MessageAttached = "";

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
	virtual void ClosePopup() override;	
};
