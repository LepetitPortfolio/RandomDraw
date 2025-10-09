// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/RDWidgetRandomDrawLine.h"
#include "FunctionLibrary/RDFunctionLibrary.h"
#include "System/RDHUD.h"
#include "UI/Popups/RDPopupConfirmeAction.h"
#include "UI/Screens/RDUIViewerRandomDraws.h"
#include "UI/Widgets/RDDrawScreenWidget.h"
#include "Managers/RDRandomDrawManager.h"
#include "Managers/RDScreenshotManager.h"

void URDWidgetRandomDrawLine::InitValue(FRDRandomDraw* _RandomDraw, FString _RandomDrawID, URDUIViewerRandomDraws* _ViewerRandomDraws)
{
	m_RandomDraw = _RandomDraw;
	m_ViewerRandomDraws = _ViewerRandomDraws;
	m_Libelle = m_RandomDraw->m_Libelle;
	m_RandomDrawID = _RandomDrawID;
}

void URDWidgetRandomDrawLine::DeleteRandomDraw()
{
	URDFunctionLibrary::DisplayPopupUI(ERDPopupUI::ValidateActionPopup);

	URDPopupConfirmeAction* popupConfirme = Cast<URDPopupConfirmeAction>(URDFunctionLibrary::GetPopupUI());

	if (popupConfirme)
	{
		FValidateAction actionsToDo;
		actionsToDo.AddUObject(this, &URDWidgetRandomDrawLine::ApplyDeleteRandomDraw);
		popupConfirme->InitPopupValue("Do you want to deleted this Drawing", actionsToDo);
	}
	
}

void URDWidgetRandomDrawLine::ApplyDeleteRandomDraw()
{
	URDFunctionLibrary::GetRandomDrawManager()->DeleteRandomDraw(m_RandomDraw);
	m_ViewerRandomDraws->ResetScrollBox();
	URDFunctionLibrary::LaunchSaveData();

}

void URDWidgetRandomDrawLine::ShowRandomDraw()
{
	URDFunctionLibrary::GetRandomDrawManager()->SetRandomDrawView(m_RandomDraw);
	URDFunctionLibrary::ChangeMenuState(ERDMenuStat::RandomDrawViewer);
}


void URDWidgetRandomDrawLine::ShareRandomDraw()
{
	URDFunctionLibrary::GetScreenshotManager()->TakeScreenshotOfRandomDraw(m_RandomDraw);

}
