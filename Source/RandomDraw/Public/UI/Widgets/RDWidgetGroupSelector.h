// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Widgets/RDWidgetBase.h"
#include "UI/Widgets/RDWidgetGroupSelection.h"
#include "Components/ScrollBox.h"
#include "Components/VerticalBox.h"
#include "RDWidgetGroupSelector.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDWidgetGroupSelector : public URDWidgetBase
{
	GENERATED_BODY()

public:

	inline FRDGroup* GetGroup() { return m_Group; }

	void ChangeGroupSelected(FRDGroup* _Group);
	void ChangeGroupSelected(FString _GroupID);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = RDUICreatePerson)
		TSubclassOf<URDWidgetGroupSelection> m_GroupSelectionTemplate;

	UPROPERTY(BlueprintReadOnly, Category = RDUICreatePerson, meta = (BindWidget))
		UScrollBox* m_ScrollBox = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = RDUICreatePerson, meta = (BindWidget))
		UVerticalBox* m_WidgetList = nullptr;

	FRDGroup* m_Group = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = RDUICreatePerson)
		FString m_GroupNameSelected = "None";

	UPROPERTY(BlueprintReadOnly, Category = RDUICreatePerson)
		FLinearColor m_GroupColorSelected = FLinearColor::Black;

	virtual void NativeOnInitialized() override;

	virtual void NativeConstruct() override;
};
