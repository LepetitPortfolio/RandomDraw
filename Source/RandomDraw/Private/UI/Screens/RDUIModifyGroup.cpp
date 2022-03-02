// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Screens/RDUIModifyGroup.h"
#include "FunctionLibrary/RDFunctionLibrary.h"
#include "UI/Popups/RDPopupConfirmeAction.h"
#include "Managers/RDGroupManager.h"

void URDUIModifyGroup::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void URDUIModifyGroup::NativeConstruct()
{
	m_Group =  URDFunctionLibrary::GetGroupManager()->GetGroupModify();

	m_GroupName = m_Group->m_Libelle;

	m_ColorSelector->ChangeColorSelected(m_Group->m_Color);

	Super::NativeConstruct();
}

void URDUIModifyGroup::ModifyGroup()
{
	bool modifyCheck = false;
	if ((!m_GroupName.IsEmpty()) && (m_Group->m_Libelle != m_GroupName))
	{
		modifyCheck = true;
	}

	if (m_Group->m_Color != m_ColorSelector->GetColor())
	{
		modifyCheck = true;
	}

	if (modifyCheck)
	{
		URDFunctionLibrary::DisplayPopupUI(ERDPopupUI::ValidateActionPopup);

		URDPopupConfirmeAction* popupConfirme = Cast<URDPopupConfirmeAction>(URDFunctionLibrary::GetPopupUI());

		if (popupConfirme)
		{
			FValidateAction actionsToDo;
			actionsToDo.AddUObject(this, &URDUIModifyGroup::ApplyModifyGroup);
			popupConfirme->InitPopupValue("Do you want to apply this changes", actionsToDo);
		}
	}
	else
	{
		URDFunctionLibrary::ReturnToLastManuState();
	}

}

void URDUIModifyGroup::ApplyModifyGroup()
{
	m_Group->m_Libelle = m_GroupName;
	m_Group->m_Color = m_ColorSelector->GetColor();

	URDFunctionLibrary::LaunchSaveData();
	URDFunctionLibrary::GetGroupManager()->SetGroupModify(nullptr);
	URDFunctionLibrary::ReturnToLastManuState();
}

