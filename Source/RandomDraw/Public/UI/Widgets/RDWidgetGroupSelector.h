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

	/**
	* Return the reference of group
	* @return reference of the group
	*/
	inline FRDGroup* GetGroup() { return m_Group; }

	/**
	* Changes the current group selected based on reference of group
	* @param _Group - Reference of group
	*/
	void ChangeGroupSelected(FRDGroup* _Group);

	/**
	* Changes the current group selected based on group ID
	* @param _GroupID - group ID
	*/
	void ChangeGroupSelected(FString _GroupID);

protected:
	/* Widget group selection template */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = RDUICreatePerson)
		TSubclassOf<URDWidgetGroupSelection> m_GroupSelectionTemplate;

	/* Reference of scrollbox Widget */
	UPROPERTY(BlueprintReadOnly, Category = RDUICreatePerson, meta = (BindWidget))
		UScrollBox* m_ScrollBox = nullptr;

	/* Reference of VerticalBox Widget */
	UPROPERTY(BlueprintReadOnly, Category = RDUICreatePerson, meta = (BindWidget))
		UVerticalBox* m_WidgetList = nullptr;

	/* reference of current group selected */
	FRDGroup* m_Group = nullptr;

	/* Name of current group selected */
	UPROPERTY(BlueprintReadOnly, Category = RDUICreatePerson)
		FString m_GroupNameSelected = "None";

	/* Color of current group selected */
	UPROPERTY(BlueprintReadOnly, Category = RDUICreatePerson)
		FLinearColor m_GroupColorSelected = FLinearColor::Black;

	/**
	* UE4 Function : Called when the object is construct
	*/
	virtual void NativeOnInitialized() override;
	/**
	* UE4 Function : Called just before to display the UMG
	*/
	virtual void NativeConstruct() override;
};
