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

	void InitValue(class URDUIViewerPersonsSelector* _PersonsSelector, FRDPerson* _Person);

	inline bool GetIsCheck() { return m_Check; }

	void SetSelected(bool _Value);

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDWidgetGroupLineSelector)
	bool m_Check = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDWidgetGroupLineSelector)
	class URDUIViewerPersonsSelector* m_PersonsSelector = nullptr;

	UFUNCTION(BlueprintCallable, Category = RDWidgetGroupLineSelector)
		void SelectPairWidgetLine(bool _Value);
};
