// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Screens/RDUIBase.h"
#include "UI/Widgets/RDWidgetColorSelector.h"
#include "Structs/RDGroup.h"
#include "RDUICreateGroup.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDUICreateGroup : public URDUIBase
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDUICreateGroup)
	FRDGroup m_Group = FRDGroup();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDUICreateGroup, meta = (BindWidget))
		URDWidgetColorSelector* m_ColorSelector = nullptr;

	virtual void NativeOnInitialized() override;

	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable, Category = RDUICreateGroup)
	void CreateGroup();

};
