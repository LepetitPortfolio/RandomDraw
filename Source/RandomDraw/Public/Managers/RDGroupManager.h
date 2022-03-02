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


	void CreateGroup(FRDGroup* _NewGroup);

	void SetGroupModify(FRDGroup* _Group);

	inline FRDGroup* GetGroupModify() { return m_GroupModify; }

	void DeleteGroup(FRDGroup* _Group);

protected:

	FRDGroup* m_GroupModify = nullptr;
};
