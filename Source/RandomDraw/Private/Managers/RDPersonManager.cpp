// Fill out your copyright notice in the Description page of Project Settings.


#include "Managers/RDPersonManager.h"
#include "FunctionLibrary/RDFunctionLibrary.h"
#include "System/RandomDrawGameMode.h"

void URDPersonManager::CreatePerson(FRDPerson* _NewPerson, FRDGroup* _FirstGroup , FRDGroup* _SecondGroup)
{

	FRDAppData* appdata = URDFunctionLibrary::GetAppData();

	_NewPerson->m_FirstGroupID = _FirstGroup->m_ID;
	_NewPerson->m_SecondGroupID = _SecondGroup->m_ID;

	bool newIDFounf = false;
	int index = 0;

	while (!newIDFounf)
	{
		FString newID = FString::Chr(_NewPerson->m_Name[0]) + FString::FromInt(index);
		if (!appdata->m_Persons.Contains(newID))
		{
			newIDFounf = true;
			_NewPerson->m_ID = newID;
		}
		else
		{
			index++;
		}
	}

	appdata->m_Persons.Add(_NewPerson->m_ID, *_NewPerson);
}

void URDPersonManager::DeletePerson(FRDPerson* _Person)
{
	FRDAppData* appdata = URDFunctionLibrary::GetAppData();

	appdata->m_Persons.Remove(_Person->m_ID);
}

void URDPersonManager::SetPersonModify(FRDPerson* _Person)
{
	m_PersonModify = _Person;
}

void URDPersonManager::DeleteGroup(FRDGroup* _Group)
{
	TMap<FString, FRDPerson>* persons = &URDFunctionLibrary::GetAppData()->m_Persons;

	for (TMap<FString, FRDPerson>::TIterator it = persons->CreateIterator(); it; ++it)
	{
		if (it.Value().m_FirstGroupID == _Group->m_ID)
		{
			it.Value().m_FirstGroupID = "";
		}
	}
}
