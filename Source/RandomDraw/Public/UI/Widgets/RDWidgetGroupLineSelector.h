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

	void InitValue(class URDUIViewerPersonsSelector* _PersonsSelectorView, FRDGroup* _Group);

	inline bool GetIsCheck() { return m_Check; }

	void SetSelected(bool _Value);

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDWidgetPersonLineSelector)
		bool m_Check = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDWidgetPersonLineSelector)
		class URDUIViewerPersonsSelector* m_PersonsSelectorView = nullptr;

	UFUNCTION(BlueprintCallable, Category = RDWidgetPersonLineSelector)
	void SelectAllGroupMember(bool _Value);
};
