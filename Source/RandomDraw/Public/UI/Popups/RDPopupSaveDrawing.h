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

	UFUNCTION(BlueprintCallable, Category = PopupSaveDrawing)
		void SaveDrawing();

protected:
	
	UPROPERTY(BlueprintReadWrite, Category = PopupSaveDrawing)
		FString m_SaveName = "";


	virtual void NativeOnInitialized() override;

	virtual void NativeConstruct() override;
};
