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

	void InitValue(FRDDraw* _Draw);

protected:

	FRDDraw* m_Draw = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDWidgetPersonLine)
		FString m_FirstPersonLibelle = "";
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDWidgetPersonLine)
		FString m_SecondPersonLibelle = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDWidgetPersonLine)
		FLinearColor m_FirstPersonColor = FLinearColor::Black;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDWidgetPersonLine)
		FLinearColor m_SecondPersonColor = FLinearColor::Black;
};
