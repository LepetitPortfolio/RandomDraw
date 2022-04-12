// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Screens/RDUIBase.h"
#include "UI/Widgets/RDWidgetColorSelector.h"
#include "Structs/RDGroup.h"
#include "RDUIModifyGroup.generated.h"

/**
 *
 */
UCLASS()
class RANDOMDRAW_API URDUIModifyGroup : public URDUIBase
{
	GENERATED_BODY()

protected:

	/* reference of group to modify */
	FRDGroup* m_Group = nullptr;

	/* Group name modify */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDUIModifyGroup)
		FString m_GroupName = "";

	/* Group Color modify */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDUIModifyGroup, meta = (BindWidget))
		URDWidgetColorSelector* m_ColorSelector = nullptr;

	/**
	* UE4 Function : Called when the object is construct
	*/
	virtual void NativeOnInitialized() override;
	/**
	* UE4 Function : Called just before to display the UMG
	*/
	virtual void NativeConstruct() override;

	/**
	* Lauch the process for modify the group selected
	*/
	UFUNCTION(BlueprintCallable, Category = RDUICreateGroup)
		void ModifyGroup();

	/**
	* Applies the modifications on the group selected
	*/
	UFUNCTION()
		void ApplyModifyGroup();

};
