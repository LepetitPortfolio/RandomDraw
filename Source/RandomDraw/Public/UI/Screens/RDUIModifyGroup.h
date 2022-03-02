// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Screens/RDUIBase.h"
#include "UI/Widgets/RDWidgetColorSelector.h"
#include "Structs/RDGroup.h"
#include "RDUIModifyGroup.generated.h"

/**
 *
 */
UCLASS()
class RANDOMDRAW_API URDUIModifyGroup : public URDUIBase
{
	GENERATED_BODY()

protected:

	FRDGroup* m_Group = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDUIModifyGroup)
		FString m_GroupName = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDUIModifyGroup, meta = (BindWidget))
		URDWidgetColorSelector* m_ColorSelector = nullptr;

	virtual void NativeOnInitialized() override;

	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable, Category = RDUICreateGroup)
		void ModifyGroup();

	UFUNCTION()
		void ApplyModifyGroup();

};
