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

	void SelectAllGroupMember(FRDGroup* _Group, bool _Value);

	void SelectPersonLineSelectorPair(FRDPerson* _Person, bool _Value);


protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RDUIViewerPersonsSelector")
	TSubclassOf<URDWidgetBase> m_SecondWidgetTemplate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RDUIViewerPersonsSelector")
	TSubclassOf<URDWidgetChangeStateButtonLine> m_ChangeStateButtonLineTemplate;

	UPROPERTY(BlueprintReadOnly, Category = "RDUIViewerPersonsSelector", meta = (BindWidget))
	UScrollBox* m_SecondScrollBox = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = "RDUIViewerPersonsSelector", meta = (BindWidget))
	UVerticalBox* m_SecondWidgetList = nullptr;

	URDWidgetChangeStateButtonLine* m_FirstChangeStateButtonLine = nullptr;
	URDWidgetChangeStateButtonLine* m_SecondChangeStateButtonLine = nullptr;

	//UPROPERTY(BlueprintReadOnly, Category = "RDUIViewerBase")
		TMap<FRDPerson*, TPair<class URDWidgetPersonLineSelector*, class URDWidgetPersonLineSelector*>> m_PersonLineSelectors;

	//UPROPERTY(BlueprintReadOnly, Category = "RDUIViewerBase")
		TMap<FRDGroup* , class URDWidgetGroupLineSelector*> m_GroupLineSelectors;

	virtual void NativeOnInitialized() override;

	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable, Category = RDUIViewerPersonsSelector)
		virtual void InitScrollBox() override;

	UFUNCTION(BlueprintCallable, Category = RDUIViewerPersonsSelector)
		bool LaunchRandomDrawing();

	bool CheckIfAllGroupMemberIsSelected(FRDGroup* _Group);


	UFUNCTION()
	void InitSortByGroup();

	UFUNCTION()
	void InitNoSort();

};
