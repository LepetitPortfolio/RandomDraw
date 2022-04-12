// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Widgets/RDWidgetGroupLine.h"
#include "RDWidgetGroupLineSelector.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDWidgetGroupLineSelector : public URDWidgetGroupLine
{
	GENERATED_BODY()
	
public:
	/**
	* Initializes the values
	* @param _PersonsSelectorView - Reference of Widget parent
	* @param _Group - reference of group
	*/
	void InitValue(class URDUIViewerPersonsSelector* _PersonsSelectorView, FRDGroup* _Group);

	/**
	* Indicates if the line is selected or not
	* @param _Value -  new state of select
	*/
	inline bool GetIsCheck() { return m_Check; }

	/**
	* Changes the state of select
	* @return state of select
	*/
	void SetSelected(bool _Value);

protected:

	/* Value of select */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDWidgetPersonLineSelector)
		bool m_Check = false;

	/* Reference of Widget parent  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDWidgetPersonLineSelector)
		class URDUIViewerPersonsSelector* m_PersonsSelectorView = nullptr;

	/**
	* Changes the state of select of all members of group
	* @param _Value - new state of select
	*/
	UFUNCTION(BlueprintCallable, Category = RDWidgetPersonLineSelector)
	void SelectAllGroupMember(bool _Value);
};
