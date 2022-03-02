// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Screens/RDUIViewerBase.h"
#include "RDUIViewerGroup.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDUIViewerGroup : public URDUIViewerBase
{
	GENERATED_BODY()

public:
	void ResetScrollBox();

protected:

	virtual void NativeOnInitialized() override;

	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable, Category = RDUIViewerGroup)
		virtual void InitScrollBox() override;
	
};
