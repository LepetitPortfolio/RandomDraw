// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Structs/RDAppData.h"
#include "Structs/RDGroup.h"
#include "Structs/RDPerson.h"
#include "RDPersonManager.generated.h"

/**
 *
 */
UCLASS()
class RANDOMDRAW_API URDPersonManager : public UObject
{
	GENERATED_BODY()

public:

	/**
	* Create a new person based on data in input
	* @param _NewPerson - new person data
	* @param _FirstGroup - First group data
	* @param _SecondGroup - Second group data
	*/
	void CreatePerson(FRDPerson* _NewPerson, FRDGroup* _FirstGroup, FRDGroup* _SecondGroup);
	/**
	* Delete a person based on data in input
	* @param _NewPerson - person data to deleted
	*/
	void DeletePerson(FRDPerson* _Person);

	/**
	* Set a new reference of the person to modify
	* @parazm _Person - person reference
	*/
	void SetPersonModify(FRDPerson* _Person);
	/**
	* return reference of the person modify
	* @return reference of person modify
	*/
	inline FRDPerson* GetPersonModify() { return m_PersonModify; }

	/**
	* delete a group besed on data in input
	* @param _Group - group data to deleted
	*/
	void DeleteGroup(FRDGroup* _Group);

protected:

	/* reference of person currently modify */
	FRDPerson* m_PersonModify = nullptr;
};
