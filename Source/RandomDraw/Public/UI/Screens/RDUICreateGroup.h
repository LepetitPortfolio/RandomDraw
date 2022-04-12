// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Screens/RDUIBase.h"
#include "UI/Widgets/RDWidgetColorSelector.h"
#include "Structs/RDGroup.h"
#include "RDUICreateGroup.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDUICreateGroup : public URDUIBase
{
	GENERATED_BODY()
	
protected:

	/* New Group data to create */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDUICreateGroup)
	FRDGroup m_Group = FRDGroup();

	/* Color selector Widget */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDUICreateGroup, meta = (BindWidget))
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
	* Launch the creation of group precess
	*/
	UFUNCTION(BlueprintCallable, Category = RDUICreateGroup)
	void CreateGroup();

};
