// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Screens/RDUIViewerBase.h"
#include "RDUIViewerRandomDraws.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDUIViewerRandomDraws : public URDUIViewerBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = RDUIViewerRandomDraws)
		void ResetScrollBox();

protected:

	virtual void NativeOnInitialized() override;

	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable, Category = RDUIViewerRandomDraws)
		virtual void InitScrollBox() override;
	
};
