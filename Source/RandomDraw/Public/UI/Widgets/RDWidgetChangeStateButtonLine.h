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
	void InitWidgetAttributs(FString _ButtonMessage, ERDMenuStat _StatSelected, ERDUIPriority _UIPriority);

protected:

	UPROPERTY(BlueprintReadOnly, Category = ColorLineSelector)
		ERDMenuStat m_StatSelected = ERDMenuStat::None;

	UPROPERTY(BlueprintReadOnly, Category = ColorLineSelector)
		ERDUIPriority m_UIPriority = ERDUIPriority::Priority1;

	UPROPERTY(BlueprintReadOnly, Category = ColorLineSelector)
		FString m_ButtonMessage = "";

	UFUNCTION(BlueprintCallable, Category = RDFunctionLibrary)
		void ChangeState();
	
};
