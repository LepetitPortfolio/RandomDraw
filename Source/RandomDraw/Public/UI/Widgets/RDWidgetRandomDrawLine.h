// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Widgets/RDWidgetBase.h"
#include "Structs/RDRandomDraw.h"
#include "RDWidgetRandomDrawLine.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDWidgetRandomDrawLine : public URDWidgetBase
{
	GENERATED_BODY()
	
public:
	/**
	* Initializes the values
	* @param _RandomDraw - reference of Randomdraw
	* @param _RandomDrawID - Randomdraw ID
	* @param _ViewerRandomDraws - Reference of Widget parent
	*/
	void InitValue(FRDRandomDraw* _RandomDraw, FString _RandomDrawID, class URDUIViewerRandomDraws* _ViewerRandomDraws);

protected:

	/* Reference of Randomdraw */
	FRDRandomDraw* m_RandomDraw = nullptr;

	/* RandomDraw libelle */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDWidgetPersonLine)
		FString m_Libelle = "";

	/* RandomDraw ID */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDWidgetPersonLine)
		FString m_RandomDrawID = "";

	/* Reference of Widget parent */
	class URDUIViewerRandomDraws* m_ViewerRandomDraws = nullptr;

	/**
	* Lauchs a process to delet a RandomDraw data
	*/
	UFUNCTION(BlueprintCallable, Category = RDUIViewerRandomDraws)
		void DeleteRandomDraw();

	/**
	* Applies the action of delete a RandomDraw data after the confirmation
	*/
	UFUNCTION(BlueprintCallable, Category = RDUIViewerRandomDraws)
		void ApplyDeleteRandomDraw();

	/**
	* Lauchs a process to display the RandomDraw
	*/
	UFUNCTION(BlueprintCallable, Category = RDUIViewerRandomDraws)
		void ShowRandomDraw();

};
