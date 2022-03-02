// Fill out your copyright notice in the Description page of Project Settings.


#include "System/RDHUD.h"
#include "Kismet/GameplayStatics.h"


bool ARDHUD::DisplayAnOtherUI(ERDMenuStat _MenuStat, ERDUIPriority _UIPriority)
{
	
	if (m_GameUI.Contains(_MenuStat))
	{
		if (m_UIInstance)
		{
			m_UIInstance->m_Instance->RemoveFromParent();
		}

		FRDUIInstance* UIInstance = &m_GameUI[_MenuStat];

		if (!UIInstance->m_Instance)
		{
			UIInstance->m_Instance = CreateWidget<URDUIBase>(UGameplayStatics::GetPlayerController(this, 0), UIInstance->m_UITemplate);
		}

		UIInstance->m_Instance->AddToViewport((int32)_UIPriority);

		m_UIInstance = UIInstance;

		return true;
	}

	return false;
}

void ARDHUD::DisplayPopupUI(ERDPopupUI _PopupUI, ERDUIPriority _UIPriority)
{
	if (m_PopupUI.Contains(_PopupUI))
	{
		FRDUIInstance* popupInstance = &m_PopupUI[_PopupUI];

		if (!popupInstance->m_Instance)
		{
			popupInstance->m_Instance = CreateWidget<URDUIBase>(UGameplayStatics::GetPlayerController(this, 0), popupInstance->m_UITemplate);
		}

		popupInstance->m_Instance->AddToViewport((int32)_UIPriority);

		m_PopupInstance = popupInstance;
	}
}
