// Copyright Epic Games, Inc. All Rights Reserved.


#include "System/RandomDrawGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "FunctionLibrary/RDFunctionLibrary.h"
#include "Managers/RDGroupManager.h"
#include "Managers/RDPersonManager.h"
#include "Managers/RDSaveManager.h"
#include "Managers/RDScreenshotManager.h"
#include "Managers/RDRandomDrawManager.h"
#include "System/RDHUD.h"

void ARandomDrawGameMode::ChangeMenuState(ERDMenuStat _MenuStat, ERDUIPriority _UIPriority)
{
	if (m_CurrentMenuStat != _MenuStat)
	{

		if ((m_RDHUD) && (m_RDHUD->DisplayAnOtherUI(_MenuStat, _UIPriority)))
		{
			FRDStateHistory stateHistory;
			stateHistory.m_MenuStat = m_CurrentMenuStat;
			stateHistory.m_UIPriority = m_CurrentUIPriority;


			if (_MenuStat == ERDMenuStat::MainMenu)
			{
				m_MenuStateHistory.Reset();
			}
			else
			{
				m_MenuStateHistory.Add(stateHistory);
			}

			m_CurrentMenuStat = _MenuStat;
			m_CurrentUIPriority = _UIPriority;
		}

		
	}
}

void ARandomDrawGameMode::ReturnToLastManuState()
{

	FRDStateHistory stateHistory = m_MenuStateHistory[m_MenuStateHistory.Num() - 1];

	if ((m_RDHUD) && (m_RDHUD->DisplayAnOtherUI(stateHistory.m_MenuStat, stateHistory.m_UIPriority)))
	{
		if (stateHistory.m_MenuStat == ERDMenuStat::MainMenu)
		{
			m_MenuStateHistory.Reset();
		}
		else
		{
			m_MenuStateHistory.RemoveAt(m_MenuStateHistory.Num() - 1);
		}

		m_CurrentMenuStat = stateHistory.m_MenuStat;
		m_CurrentUIPriority = stateHistory.m_UIPriority;
	}

}

void ARandomDrawGameMode::DisplayPopupUI(ERDPopupUI _PopupUI, ERDUIPriority _UIPriority)
{
	if (m_RDHUD)
	{
		m_RDHUD->DisplayPopupUI(_PopupUI, _UIPriority);
	}
}

URDUIBase* ARandomDrawGameMode::GetPopupUI()
{
	if (m_RDHUD)
	{
		return m_RDHUD->GetPopupInstance();
	}
	return nullptr;
}

void ARandomDrawGameMode::SetAppData(FRDAppData* _NewAppData)
{
	m_AppData = FRDAppData(_NewAppData);
}

void ARandomDrawGameMode::BeginPlay()
{
	m_GroupManager = NewObject<URDGroupManager>();
	m_PersonManager = NewObject<URDPersonManager>();
	m_SaveManager = NewObject<URDSaveManager>();
	m_RandomDrawManager = NewObject<URDRandomDrawManager>();
	m_ScreenshotManager = NewObject<URDScreenshotManager>();
	m_AppData = FRDAppData();

	if (!m_SaveManager->LoadData())
	{
		UE_LOG(LogRD, Error, TEXT("Error : Load Data"))
	}


	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	m_RDHUD = PlayerController->GetHUD<ARDHUD>();

	if (m_RDHUD)
	{
		m_RDHUD->DisplayAnOtherUI(m_CurrentMenuStat, ERDUIPriority::Priority1);
	}
}

void ARandomDrawGameMode::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	URDFunctionLibrary::ResetGameMode();
}
