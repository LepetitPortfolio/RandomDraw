// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Screens/RDUIViewerBase.h"
#include "UI/Widgets/RDWidgetChangeStateButtonLine.h"
#include "Structs/RDPerson.h"
#include "RDUIViewerPersonsSelector.generated.h"

/**
 *
 */
UCLASS()
class RANDOMDRAW_API URDUIViewerPersonsSelector : public URDUIViewerBase
{
	GENERATED_BODY()

public:

	/** 
	* Selects or Unselectes all persons member of a group 
	* @param _Group - Group data 
	* @param _Value - salect value
	*/
	void SelectAllGroupMember(FRDGroup* _Group, bool _Value);

	/**
	* Selects or Unselectes a pair of person
	* @param _Person - Person data
	* @param _Value - salect value
	*/
	void SelectPersonLineSelectorPair(FRDPerson* _Person, bool _Value);


protected:
	
	/* Second widget template to instantiate */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RDUIViewerPersonsSelector")
		TSubclassOf<URDWidgetBase> m_SecondWidgetTemplate;

	/* ChangeStateButtonLine template to instantiate */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RDUIViewerPersonsSelector")
		TSubclassOf<URDWidgetChangeStateButtonLine> m_ChangeStateButtonLineTemplate;

	/* Second reference of the Scroll box widget */
	UPROPERTY(BlueprintReadOnly, Category = "RDUIViewerPersonsSelector", meta = (BindWidget))
		UScrollBox* m_SecondScrollBox = nullptr;

	/* Second reference of the vertical box widget */
	UPROPERTY(BlueprintReadOnly, Category = "RDUIViewerPersonsSelector", meta = (BindWidget))
		UVerticalBox* m_SecondWidgetList = nullptr;

	/* Reference of first WidgetChangeStateButtonLine object */
	URDWidgetChangeStateButtonLine* m_FirstChangeStateButtonLine = nullptr;
	
	/* Reference of second WidgetChangeStateButtonLine object */
	URDWidgetChangeStateButtonLine* m_SecondChangeStateButtonLine = nullptr;

	/* List of pair of WidgetPersonLineSelector by person */
	TMap<FRDPerson*, TPair<class URDWidgetPersonLineSelector*, class URDWidgetPersonLineSelector*>> m_PersonLineSelectors;

	/* binds all WidgetGroupLineSelector with a person */
	TMap<FRDGroup*, class URDWidgetGroupLineSelector*> m_GroupLineSelectors;

	/**
	* UE4 Function : Called when the object is construct
	*/
	virtual void NativeOnInitialized() override;
	/**
	* UE4 Function : Called just before to display the UMG
	*/
	virtual void NativeConstruct() override;

	/**
	* Initialize the Scroll Bow widget
	*/
	UFUNCTION(BlueprintCallable, Category = RDUIViewerPersonsSelector)
		virtual void InitScrollBox() override;

	/**
	* Lauch the Random Drawing process
	* @return Return True or False if the Random drawn sucessful
	*/
	UFUNCTION(BlueprintCallable, Category = RDUIViewerPersonsSelector)
		bool LaunchRandomDrawing();

	/**
	* Check if all member of group are selected 
	* @param _Group - group of members to checked 
	* @return the value of check
	*/
	bool CheckIfAllGroupMemberIsSelected(FRDGroup* _Group);

	/**
	* Inserts the persons in the list sorted by group
	*/
	UFUNCTION()
		void InitSortByGroup();

	/**
	* Inserts the persons in the list without sort
	*/
	UFUNCTION()
		void InitNoSort();

};
