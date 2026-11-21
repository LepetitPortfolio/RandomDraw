// Fill out your copyright notice in the Description page of Project Settings.


#include "Managers/RDGroupManager.h"
#include "FunctionLibrary/RDFunctionLibrary.h"
#include "System/RandomDrawGameMode.h"
#include "Managers/RDPersonManager.h"

void URDGroupManager::CreateGroup(FRDGroup* _NewGroup)
{
	ARandomDrawGameMode* gm = URDFunctionLibrary::GetRDGameMode();
	
	if (!gm)
	{
		return;
	}

	FRDAppData* appData = gm->GetAppData();

	TMap<FString, FRDGroup>* Groups = &appData->m_Groups;

	bool addNewGroup = false;
	int GroupIndex = 0;
	
	while (!addNewGroup)
	{
		FString id = FString::Chr(_NewGroup->m_Libelle[0]) + FString::FromInt(GroupIndex);
		if (!Groups->Contains(id))
		{
			_NewGroup->m_ID = id;
			Groups->Add(_NewGroup->m_ID, *_NewGroup);
			addNewGroup = true;
		}
		else
		{
			GroupIndex++;
		}
	}
}

void URDGroupManager::SetGroupModify(FRDGroup* _Group)
{
	m_GroupModify = _Group;
}

void URDGroupManager::DeleteGroup(FRDGroup* _Group)
{
	URDFunctionLibrary::GetPersonManager()->DeleteGroup(_Group);
	URDFunctionLibrary::GetAppData()->m_Groups.Remove(_Group->m_ID);
}

int URDGroupManager::GetGroupCount()
{
	return URDFunctionLibrary::GetAppData()->m_Groups.Num();
}

int URDGroupManager::GetGroupIndex(FRDGroup* _Group)
{
	return GetGroupIndex(_Group->m_ID);
}

int URDGroupManager::GetGroupIndex(FString _GroupID)
{
	int outIndex = -1;
	TMap<FString, FRDGroup>* groups = &URDFunctionLibrary::GetAppData()->m_Groups;
	int index = 0;

	for (TPair<FString, FRDGroup>& paire : *groups)
	{
		if (paire.Key == _GroupID)
		{
			outIndex = index;
			break;
		}
		else
		{
			index++;
		}
	}

	return outIndex;
}
