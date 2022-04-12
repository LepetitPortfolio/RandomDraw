// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Widgets/RDWidgetBase.h"
#include "Structs/RDDraw.h"
#include "RDWidgetDrawLine.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDWidgetDrawLine : public URDWidgetBase
{
	GENERATED_BODY()
	
public:
	/**
	* Initializes the values
	* @param _Draw - reference of draw to displayed
	*/
	void InitValue(FRDDraw* _Draw);

protected:

	/* Reference of draw to displayed */
	FRDDraw* m_Draw = nullptr;

	/*Libelle of first persone*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDWidgetPersonLine)
		FString m_FirstPersonLibelle = "";

	/*Libelle of second persone*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDWidgetPersonLine)
		FString m_SecondPersonLibelle = "";

	/*Color of first persone*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDWidgetPersonLine)
		FLinearColor m_FirstPersonColor = FLinearColor::Black;

	/*Color of second persone*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDWidgetPersonLine)
		FLinearColor m_SecondPersonColor = FLinearColor::Black;
};
