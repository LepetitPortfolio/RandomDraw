// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Popups/RDPopupBase.h"
#include "RDPopupSaveDrawing.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDPopupSaveDrawing : public URDPopupBase
{
	GENERATED_BODY()

public:

	/**
	* Launch the drawing save process 
	*/
	UFUNCTION(BlueprintCallable, Category = PopupSaveDrawing)
		void SaveDrawing();

protected:
	
	/* Save name */
	UPROPERTY(BlueprintReadWrite, Category = PopupSaveDrawing)
		FString m_SaveName = "";

	/**
	* UE4 Function : Called when the object is construct
	*/
	virtual void NativeOnInitialized() override;
	/**
	* UE4 Function : Called just before to display the UMG
	*/
	virtual void NativeConstruct() override;
};
