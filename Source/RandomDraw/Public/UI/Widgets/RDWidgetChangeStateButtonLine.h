// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Widgets/RDWidgetBase.h"
#include "Enums/RDMenuStat.h"
#include "Enums/RDUIPriority.h"
#include "RDWidgetChangeStateButtonLine.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDWidgetChangeStateButtonLine : public URDWidgetBase
{
	GENERATED_BODY()

public:
	/**
	* Initializes the widget Attributs
	* @param _ButtonMessage - Message displayed in the button
	* @param _StatSelected - State of menu selected
	* @param _UIPriority - UI priority
	*/
	void InitWidgetAttributs(FString _ButtonMessage, ERDMenuStat _StatSelected, ERDUIPriority _UIPriority);

protected:

	/* State of menu selected */
	UPROPERTY(BlueprintReadOnly, Category = ColorLineSelector)
		ERDMenuStat m_StatSelected = ERDMenuStat::None;

	/* UI priority */
	UPROPERTY(BlueprintReadOnly, Category = ColorLineSelector)
		ERDUIPriority m_UIPriority = ERDUIPriority::Priority1;

	/* Message displayed in the button */
	UPROPERTY(BlueprintReadOnly, Category = ColorLineSelector)
		FString m_ButtonMessage = "";

	/* Change the state of the menu */
	UFUNCTION(BlueprintCallable, Category = RDFunctionLibrary)
		void ChangeState();
	
};
