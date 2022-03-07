// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Structs/RDAppData.h"
#include "Structs/RDGroup.h"
#include "RDGroupManager.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDGroupManager : public UObject
{
	GENERATED_BODY()
	
public:


	/**
	* Creat a new group based on data in input
	* @param _NewGroup - New group data
	*/
	void CreateGroup(FRDGroup* _NewGroup);

	/**
	* Set a new reference of the group to modify
	* @parazm _Group - group reference
	*/
	void SetGroupModify(FRDGroup* _Group);

	/**
	* return reference of the group modify
	* @return reference of group modify
	*/
	inline FRDGroup* GetGroupModify() { return m_GroupModify; }

	/**
	* delete a group besed on data in input
	* @param _Group - group data to deleted
	*/
	void DeleteGroup(FRDGroup* _Group);

protected:

	/* reference of group currently modify */
	FRDGroup* m_GroupModify = nullptr;
};
