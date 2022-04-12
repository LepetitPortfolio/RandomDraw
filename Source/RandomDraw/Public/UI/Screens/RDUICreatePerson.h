// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Screens/RDUIBase.h"
#include "Structs/RDGroup.h"
#include "Structs/RDPerson.h"
#include "UI/Widgets/RDWidgetGroupSelector.h"
#include "RDUICreatePerson.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDUICreatePerson : public URDUIBase
{
	GENERATED_BODY()
	
protected:
	/* First group selector Widget */
	UPROPERTY(BlueprintReadOnly, Category = RDUICreatePerson, meta = (BindWidget))
		URDWidgetGroupSelector* m_FirstGroupSelector;

	/* Second group selector Widget */
	UPROPERTY(BlueprintReadOnly, Category = RDUICreatePerson, meta = (BindWidget))
		URDWidgetGroupSelector* m_SecondGroupSelector;

	/* New personhaa it's a goo data to create */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDUICreateGroup)
	FRDPerson m_Person = FRDPerson();

	/**
	* UE4 Function : Called when the object is construct
	*/
	virtual void NativeOnInitialized() override;
	/**
	* UE4 Function : Called just before to display the UMG
	*/
	virtual void NativeConstruct() override;

	/**
	* Launch a new person creation process
	*/
	UFUNCTION(BlueprintCallable, Category = RDUICreateGroup)
	void CreatePerson();
};
