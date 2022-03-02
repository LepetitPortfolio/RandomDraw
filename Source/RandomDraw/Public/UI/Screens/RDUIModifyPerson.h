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

	UPROPERTY(BlueprintReadOnly, Category = RDUICreatePerson, meta = (BindWidget))
		URDWidgetGroupSelector* m_FirstGroupSelector;

	UPROPERTY(BlueprintReadOnly, Category = RDUICreatePerson, meta = (BindWidget))
		URDWidgetGroupSelector* m_SecondGroupSelector;

	FRDPerson* m_Person = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDUICreateGroup)
		FString m_PersonName = "";

	virtual void NativeOnInitialized() override;

	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable, Category = RDUICreateGroup)
		void ModifyPerson();

	UFUNCTION()
		void ApplyModifyPerson();

};
