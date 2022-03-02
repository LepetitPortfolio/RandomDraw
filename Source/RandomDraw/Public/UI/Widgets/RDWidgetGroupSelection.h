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

	void InitValues(FRDGroup* _Group, class URDWidgetGroupSelector* _GroupSelector);

protected:

	FRDGroup* m_Group = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = GroupSelection)
		class URDWidgetGroupSelector* m_GroupSelector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDWidgetGroupSelection)
		FString m_Libelle = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDWidgetGroupSelection)
		FLinearColor m_Color = FLinearColor::Black;

	UFUNCTION(BlueprintCallable, Category = RDWidgetGroupSelection)
		void Select();

};
