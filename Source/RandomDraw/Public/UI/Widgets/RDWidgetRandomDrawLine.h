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
	void InitValue(FRDRandomDraw* _RandomDraw, FString _RandomDrawID, class URDUIViewerRandomDraws* _ViewerRandomDraws);

protected:

	FRDRandomDraw* m_RandomDraw = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDWidgetPersonLine)
		FString m_Libelle = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDWidgetPersonLine)
		FString m_RandomDrawID = "";

	class URDUIViewerRandomDraws* m_ViewerRandomDraws = nullptr;

	UFUNCTION(BlueprintCallable, Category = RDUIViewerRandomDraws)
		void DeleteRandomDraw();

	UFUNCTION(BlueprintCallable, Category = RDUIViewerRandomDraws)
		void ApplyDeleteRandomDraw();

	UFUNCTION(BlueprintCallable, Category = RDUIViewerRandomDraws)
		void ShowRandomDraw();

};
