// Fill out your copyright notice in the Description page of Project Settings.


#include "FunctionLibrary/RDFunctionLibrary.h"
#include "RandomDraw.h"
#include "Kismet/GameplayStatics.h"
#include "Managers/RDSaveManager.h"
#include "Managers/RDGroupManager.h"
#include "Managers/RDPersonManager.h"
#include "Managers/RDScreenshotManager.h"
#include "System/RandomDrawGameMode.h"



ARandomDrawGameMode* URDFunctionLibrary::m_GameMode = nullptr;

ARandomDrawGameMode* URDFunctionLibrary::GetRDGameMode()
{
	if (!m_GameMode)
	{
		ARandomDrawGameMode* gameMode = nullptr;

		const TIndirectArray<FWorldContext>& worldContexts = GEngine->GetWorldContexts();

		for (int i = 0; i < worldContexts.Num() && !gameMode; i++)
		{
			gameMode = static_cast<ARandomDrawGameMode*>(worldContexts[i].World()->GetAuthGameMode());
		}

		m_GameMode = gameMode;
	}

	return m_GameMode;
}

void URDFunctionLibrary::ResetGameMode()
{
	m_GameMode = nullptr;
}

ARDHUD* URDFunctionLibrary::GetRDHUD()
{
	ARandomDrawGameMode* gm = GetRDGameMode();

	if (gm)
	{
		return gm->GetRDHUD();
	}

	return nullptr;
}

URDPersonManager* URDFunctionLibrary::GetPersonManager()
{
	ARandomDrawGameMode* gm = GetRDGameMode();

	if (gm)
	{
		return gm->GetPersonManager();
	}

	return nullptr;
}

URDGroupManager* URDFunctionLibrary::GetGroupManager()
{
	ARandomDrawGameMode* gm = GetRDGameMode();

	if (gm)
	{
		return gm->GetGroupManager();
	}

	return nullptr;
}

URDRandomDrawManager* URDFunctionLibrary::GetRandomDrawManager()
{
	ARandomDrawGameMode* gm = GetRDGameMode();

	if (gm)
	{
		return gm->GetRandomDrawManager();
	}

	return nullptr;
}

URDScreenshotManager* URDFunctionLibrary::GetScreenshotManager()
{
	ARandomDrawGameMode* gm = GetRDGameMode();

	if (gm)
	{
		return gm->GetScreenshotManager();
	}

	return nullptr;
}

void URDFunctionLibrary::LaunchSaveData()
{
	ARandomDrawGameMode* gm = GetRDGameMode();

	if (gm)
	{
		URDSaveManager* SaveManager = gm->GetSaveManager();
		if (SaveManager)
		{
			SaveManager->SaveData();
		}
	}
}

void URDFunctionLibrary::LauchSaveLoad()
{
	ARandomDrawGameMode* gm = GetRDGameMode();

	if (gm)
	{
		URDSaveManager* SaveManager = gm->GetSaveManager();
		if (SaveManager)
		{
			SaveManager->LoadData();
		}
	}
}

void URDFunctionLibrary::ChangeMenuState(ERDMenuStat _MenuStat, ERDUIPriority _UIPriority)
{
	ARandomDrawGameMode* gm = GetRDGameMode();

	if (gm)
	{
		gm->ChangeMenuState(_MenuStat, _UIPriority);
	}
}

void URDFunctionLibrary::ReturnToLastManuState()
{
	ARandomDrawGameMode* gm = GetRDGameMode();

	if (gm)
	{
		gm->ReturnToLastManuState();
	}
}

void URDFunctionLibrary::DisplayPopupUI(ERDPopupUI _PopupUI, ERDUIPriority _UIPriority)
{
	ARandomDrawGameMode* gm = GetRDGameMode();

	if (gm)
	{
		gm->DisplayPopupUI(_PopupUI, _UIPriority);
	}
}

URDUIBase* URDFunctionLibrary::GetPopupUI()
{

	ARandomDrawGameMode* gm = GetRDGameMode();

	if (gm)
	{
		return gm->GetPopupUI();
	}

	return nullptr;
}

FRDAppData* URDFunctionLibrary::GetAppData()
{

	ARandomDrawGameMode* gm = GetRDGameMode();

	if (gm)
	{
		FRDAppData* appData = gm->GetAppData();
		return appData;
	}
	return nullptr;
}

void URDFunctionLibrary::SetAppData(FRDAppData* _AppData)
{
	ARandomDrawGameMode* gm = GetRDGameMode();

	if (gm)
	{
		gm->SetAppData(_AppData);
	}
}

FRDPerson* URDFunctionLibrary::GetPerson(FString _PersonID)
{
	FRDPerson* person = nullptr;
	TMap<FString, FRDPerson>* persons = &URDFunctionLibrary::GetAppData()->m_Persons;

	if (persons->Contains(_PersonID))
	{
		person = &persons->operator[](_PersonID);
	}

	return person;
}

FRDGroup* URDFunctionLibrary::GetGroup(FString _GroupID)
{
	FRDGroup* group = nullptr;
	TMap<FString, FRDGroup>* groups = &URDFunctionLibrary::GetAppData()->m_Groups;

	if (groups->Contains(_GroupID))
	{
		group = &groups->operator[](_GroupID);
	}

	return group;
}


