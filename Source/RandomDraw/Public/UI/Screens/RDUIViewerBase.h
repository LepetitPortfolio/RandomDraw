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

	/* Widget template to instantiate */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RDUIViewerBase")
	TSubclassOf<URDWidgetBase> m_WidgetTemplate;

	/* Reference of the Scroll box widget */
	UPROPERTY(BlueprintReadOnly, Category = "RDUIViewerBase", meta = (BindWidget))
	UScrollBox* m_ScrollBox = nullptr;
	
	/* Reference of the vertical box widget */
	UPROPERTY(BlueprintReadOnly, Category = "RDUIViewerBase", meta = (BindWidget))
	UVerticalBox* m_WidgetList = nullptr;

	/**
	* Pure virtual function used for initialize the scroll box 
	*/
	virtual void InitScrollBox() PURE_VIRTUAL(URDUIViewerBase::InitScrollBox, ;);
};
