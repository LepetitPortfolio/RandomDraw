// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Widgets/RDWidgetBase.h"
#include "Structs/RDGroup.h"
#include "RDWidgetGroupSelection.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDWidgetGroupSelection : public URDWidgetBase
{
	GENERATED_BODY()
	
public:

	/**
	* Initializes the values
	* @param _Group - reference of group to displayed
	* @param _GroupSelector - Reference of Widget parent
	*/
	void InitValues(FRDGroup* _Group, class URDWidgetGroupSelector* _GroupSelector);

protected:

	/* Reference of group to displayed */
	FRDGroup* m_Group = nullptr;
	
	/* Reference of Widget parent */
	UPROPERTY(BlueprintReadOnly, Category = GroupSelection)
		class URDWidgetGroupSelector* m_GroupSelector;

	/* Libelle of group */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDWidgetGroupSelection)
		FString m_Libelle = "";

	/* Color of group */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDWidgetGroupSelection)
		FLinearColor m_Color = FLinearColor::Black;

	/* Launch the process of select of group */
	UFUNCTION(BlueprintCallable, Category = RDWidgetGroupSelection)
		void Select();

};
