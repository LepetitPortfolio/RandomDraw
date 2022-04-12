// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Widgets/RDWidgetPersonLine.h"
#include "RDWidgetPersonLineSelector.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDWidgetPersonLineSelector : public URDWidgetPersonLine
{
	GENERATED_BODY()

public:

	/**
	* Initializes the values
	* @param _PersonsSelector - reference of Widget parent
	* @param _Person - reference of person to select
	*/
	void InitValue(class URDUIViewerPersonsSelector* _PersonsSelector, FRDPerson* _Person);

	/**
	* Changes the state of select
	* @return state of select
	*/
	inline bool GetIsCheck() { return m_Check; }

	/**
	* Indicates if the line is selected or not
	* @param _Value -  new state of select
	*/
	void SetSelected(bool _Value);

protected:

	/* Value of select */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDWidgetGroupLineSelector)
	bool m_Check = false;

	/* Reference of Widget parent  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDWidgetGroupLineSelector)
	class URDUIViewerPersonsSelector* m_PersonsSelector = nullptr;

	/**
	* Changes the state of select of the line
	* @param _Value - new state of select
	*/
	UFUNCTION(BlueprintCallable, Category = RDWidgetGroupLineSelector)
		void SelectPairWidgetLine(bool _Value);
};
