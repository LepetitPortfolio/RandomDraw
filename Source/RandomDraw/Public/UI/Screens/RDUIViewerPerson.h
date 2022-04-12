// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Screens/RDUIViewerBase.h"
#include "Structs/RDPerson.h"
#include "RDUIViewerPerson.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDUIViewerPerson : public URDUIViewerBase
{
	GENERATED_BODY()
	
public:

	/** 
	* Reset the Scroll Bow widget 
	*/
	UFUNCTION(BlueprintCallable, Category = RDUIViewerPerson)
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
	* Initialize the Scroll Bow widget 
	*/
	UFUNCTION(BlueprintCallable, Category = RDUIViewerPerson)
		virtual void InitScrollBox() override;
};
