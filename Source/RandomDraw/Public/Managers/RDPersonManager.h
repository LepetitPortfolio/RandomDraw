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

	void CreatePerson(FRDPerson* _NewPerson, FRDGroup* _FirstGroup, FRDGroup* _SecondGroup);
	void DeletePerson(FRDPerson* _Person);

	void SetPersonModify(FRDPerson* _Person);
	inline FRDPerson* GetPersonModify() { return m_PersonModify; }

	void DeleteGroup(FRDGroup* _Group);

protected:

	FRDPerson* m_PersonModify = nullptr;
};
