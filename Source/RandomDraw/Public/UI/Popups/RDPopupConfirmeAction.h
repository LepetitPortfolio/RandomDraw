// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Popups/RDPopupBase.h"
#include "RDPopupConfirmeAction.generated.h"

DECLARE_EVENT(URDPopupConfirmeAction, FValidateAction)

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDPopupConfirmeAction : public URDPopupBase
{
	GENERATED_BODY()

public:

	/**
	* Initialize the popup value
	* @param _Message - Message displayed
	* @param _ActionsToDo - action to do after validation
	*/
	void InitPopupValue(FString _Message, FValidateAction const& _ActionsToDo);

protected:

	/* Message displayed on the popup */
	UPROPERTY(BlueprintReadWrite, Category = PopupConfirmeAction)
	FString m_PopupMessage = "";

	/* Action to do after validation */
	FValidateAction m_ActionEvent;

	/**
	* Valids and executes the actions to do
	*/
	UFUNCTION(BlueprintCallable, Category = PopupConfirmeAction)
		void ValideAction();

	/**
	* Cancel the validation
	*/
	UFUNCTION(BlueprintCallable, Category = PopupConfirmeAction)
	void CancelAction();

};
