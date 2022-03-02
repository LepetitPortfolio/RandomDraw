// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/RDWidgetGroupLine.h"
#include "FunctionLibrary/RDFunctionLibrary.h"
#include "Managers/RDGroupManager.h"
#include "UI/Popups/RDPopupConfirmeAction.h"
#include "UI/Screens/RDUIViewerGroup.h"

void URDWidgetGroupLine::InitValue(FRDGroup* _Group, URDUIViewerGroup* _ViewerGroup)
{
	if (!_Group)
	{
		return;
	}

	m_Group = _Group;
	m_ViewerGroup = _ViewerGroup;
	m_Libelle = m_Group->m_Libelle;
	m_Color = m_Group->m_Color;
}

void URDWidgetGroupLine::DeleteGroup()
{
	URDFunctionLibrary::DisplayPopupUI(ERDPopupUI::ValidateActionPopup);

	URDPopupConfirmeAction* popupConfirme = Cast<URDPopupConfirmeAction>(URDFunctionLibrary::GetPopupUI());

	if (popupConfirme)
	{
		FValidateAction actionsToDo;
		actionsToDo.AddUObject(this, &URDWidgetGroupLine::ApplyDeleteGroup);
		popupConfirme->InitPopupValue("Do you want to deleted this Group", actionsToDo);
	}
	
}

void URDWidgetGroupLine::ApplyDeleteGroup()
{
	URDFunctionLibrary::GetGroupManager()->DeleteGroup(m_Group);
	m_ViewerGroup->ResetScrollBox();
	URDFunctionLibrary::LaunchSaveData();
}

void URDWidgetGroupLine::ModifyGroup()
{
	URDFunctionLibrary::GetGroupManager()->SetGroupModify(m_Group);
	URDFunctionLibrary::ChangeMenuState(ERDMenuStat::ModifyGroup);
}
