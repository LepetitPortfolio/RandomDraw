// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Screens/RDUIBase.h"
#include "UI/Widgets/RDWidgetBase.h"
#include "Components/ScrollBox.h"
#include "Components/VerticalBox.h"
#include "RDUIViewerBase.generated.h"

/**
 * 
 */
UCLASS(abstract)
class RANDOMDRAW_API URDUIViewerBase : public URDUIBase
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RDUIViewerBase")
	TSubclassOf<URDWidgetBase> m_WidgetTemplate;

	UPROPERTY(BlueprintReadOnly, Category = "RDUIViewerBase", meta = (BindWidget))
	UScrollBox* m_ScrollBox = nullptr;
	
	UPROPERTY(BlueprintReadOnly, Category = "RDUIViewerBase", meta = (BindWidget))
	UVerticalBox* m_WidgetList = nullptr;

	virtual void InitScrollBox() PURE_VIRTUAL(URDUIViewerBase::InitScrollBox, ;);
};
