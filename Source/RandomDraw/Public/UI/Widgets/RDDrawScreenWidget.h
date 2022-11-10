// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Widgets/RDWidgetBase.h"
#include "Structs/RDRandomDraw.h"
#include "RDDrawScreenWidget.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDDrawScreenWidget : public URDWidgetBase
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintImplementableEvent, Category = "Draw Screen Widget")
	void AddWidgetInScreen(URDWidgetBase* _Widget, bool _ResizeScreen = false);

	UFUNCTION(BlueprintImplementableEvent, Category = "Draw Screen Widget")
	void SetNewSizeOfScreen(FVector2D _NewSize);

	UFUNCTION(BlueprintImplementableEvent, Category = "Draw Screen Widget")
	void ClearAllWidget();

	void GenerateRandomDrawList(FRDRandomDraw* _RandomDraw);

protected:
	/* Widget template to instantiate */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Draw Screen Widget")
		TSubclassOf<URDWidgetBase> m_WidgetTemplate;

	/* Random Draw Name */
	UPROPERTY(BlueprintReadOnly, Category = "Draw Screen Widget")
		FString m_RandomDrawLibelle = "";
};
