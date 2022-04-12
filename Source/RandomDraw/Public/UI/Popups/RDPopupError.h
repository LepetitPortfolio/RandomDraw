// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Popups/RDPopupBase.h"
#include "RDPopupError.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDPopupError : public URDPopupBase
{
	GENERATED_BODY()
	
public:

	/**
	* Initialize the popup value
	* @param _Message - Message displayed
	*/
	UFUNCTION()
	void InitPopupValue(FString _Message);

protected:

	/* Message displayed on the popup */
	UPROPERTY(BlueprintReadWrite, Category = PopupError)
	FString m_PopupMessage = "";


};
