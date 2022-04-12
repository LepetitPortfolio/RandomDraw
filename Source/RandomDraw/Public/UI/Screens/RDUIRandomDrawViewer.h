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

	/* Reference of Random Draw selected */
	FRDRandomDraw* m_RandomDraw = nullptr;

	/* Random Draw Name */
	UPROPERTY(BlueprintReadOnly, Category = "RDUIViewerBase")
		FString m_RandomDrawLibelle = "";

	/**
	* UE4 Function : Called when the object is construct
	*/
	virtual void NativeOnInitialized() override;
	/**
	* UE4 Function : Called just before to display the UMG
	*/
	virtual void NativeConstruct() override;

	/**
	* Edites the Draw list of the random drawn in the scrol box
	*/
	UFUNCTION(BlueprintCallable, Category = RDUIPersonManager)
		virtual void InitScrollBox() override;
	
};
