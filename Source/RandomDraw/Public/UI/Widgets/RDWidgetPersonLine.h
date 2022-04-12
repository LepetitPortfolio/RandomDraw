// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Widgets/RDWidgetBase.h"
#include "Structs/RDPerson.h"
#include "RDWidgetPersonLine.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDWidgetPersonLine : public URDWidgetBase
{
	GENERATED_BODY()
	
public: 

	/**
	* Initializes the values
	* @param _Person - reference of person to displayed
	* @param _ViewerPerson - reference of Widget parent
	*/
	void InitValue(FRDPerson* _Person, class URDUIViewerPerson* _ViewerPerson);

	/**
	* Return the reference of person to displayed
	* @return reference of person to displayed
	*/
	inline FRDPerson* GetPerson() { return m_Person; }

protected:

	/* The reference of person to displayed */
	FRDPerson* m_Person = nullptr;

	/* The reference of Widget parent */
	UPROPERTY()
	class URDUIViewerPerson* m_ViewerPerson = nullptr;

	/* The name of person */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDWidgetPersonLine)
	FString m_PersonName = "";

	/* The Color of person */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDWidgetPersonLine)
	FLinearColor m_Color = FLinearColor::Black;

	/**
	* Lauchs a process to delet a person data
	*/
	UFUNCTION(BlueprintCallable, Category = RDWidgetPersonLine)
	void DeleteThePerson();

	/**
	* Applies the action of delete a person data after the confirmation
	*/
	UFUNCTION()
	void ApplyDeleteGroup();

	/**
	* Lauchs a process to modify a Person data
	*/
	UFUNCTION(BlueprintCallable, Category = RDWidgetPersonLine)
		void ModifyThePerson();

};
