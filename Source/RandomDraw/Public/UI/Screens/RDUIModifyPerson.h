// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Screens/RDUIBase.h"
#include "Structs/RDGroup.h"
#include "Structs/RDPerson.h"
#include "UI/Widgets/RDWidgetGroupSelector.h"
#include "RDUIModifyPerson.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDUIModifyPerson : public URDUIBase
{
	GENERATED_BODY()
	
protected:

	/* First person Group modify */
	UPROPERTY(BlueprintReadOnly, Category = RDUICreatePerson, meta = (BindWidget))
		URDWidgetGroupSelector* m_FirstGroupSelector;

	/* Second person Group modify */
	UPROPERTY(BlueprintReadOnly, Category = RDUICreatePerson, meta = (BindWidget))
		URDWidgetGroupSelector* m_SecondGroupSelector;

	/* reference of person to modify */
	FRDPerson* m_Person = nullptr;

	/* Person name modify */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDUICreateGroup)
		FString m_PersonName = "";

	/**
	* UE4 Function : Called when the object is construct
	*/
	virtual void NativeOnInitialized() override;
	/**
	* UE4 Function : Called just before to display the UMG
	*/
	virtual void NativeConstruct() override;

	/**
	* Lauch the process for modify the person selected
	*/
	UFUNCTION(BlueprintCallable, Category = RDUICreateGroup)
		void ModifyPerson();

	/**
	* Applies the modifications on the Person selected
	*/
	UFUNCTION()
		void ApplyModifyPerson();

};
