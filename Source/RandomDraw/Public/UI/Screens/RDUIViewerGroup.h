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
	/**
	* Reset the scroll box
	*/
	void ResetScrollBox();

protected:

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
	UFUNCTION(BlueprintCallable, Category = RDUIViewerGroup)
		virtual void InitScrollBox() override;
	
};
