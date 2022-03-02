// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Screens/RDUIViewerBase.h"
#include "Structs/RDRandomDraw.h"
#include "RDUIRandomDrawViewer.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDUIRandomDrawViewer : public URDUIViewerBase
{
	GENERATED_BODY()

protected:

	FRDRandomDraw* m_RandomDraw = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "RDUIViewerBase")
		FString m_RandomDrawLibelle = "";

	virtual void NativeOnInitialized() override;

	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable, Category = RDUIPersonManager)
		virtual void InitScrollBox() override;
	
};
