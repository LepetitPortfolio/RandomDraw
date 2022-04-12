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

	/* Reference of new random draw Data */
	FRDRandomDraw* m_RandomDraw = nullptr;

	/**
	* UE4 Function : Called when the object is construct
	*/
	virtual void NativeOnInitialized() override;
	/**
	* UE4 Function : Called just before to display the UMG
	*/
	virtual void NativeConstruct() override;

	/**
	* Initialize the scroll box
	*/
	UFUNCTION(BlueprintCallable, Category = RDUIPersonManager)
		virtual void InitScrollBox() override;
};
