// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Screens/RDUIViewerBase.h"
#include "Structs/RDRandomDraw.h"
#include "RDUIViewerNewRandomDraw.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDUIViewerNewRandomDraw : public URDUIViewerBase
{
	GENERATED_BODY()

protected:

	FRDRandomDraw* m_RandomDraw = nullptr;

	virtual void NativeOnInitialized() override;

	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable, Category = RDUIPersonManager)
		virtual void InitScrollBox() override;
};
