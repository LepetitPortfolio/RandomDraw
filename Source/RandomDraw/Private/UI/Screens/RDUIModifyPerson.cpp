// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Screens/RDUIModifyPerson.h"
#include "FunctionLibrary/RDFunctionLibrary.h"
#include "UI/Popups/RDPopupConfirmeAction.h"
#include "Managers/RDPersonManager.h"

void URDUIModifyPerson::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void URDUIModifyPerson::NativeConstruct()
{
	m_Person = URDFunctionLibrary::GetPersonManager()->GetPersonModify();

	m_PersonName = m_Person->m_Name;

	m_FirstGroupSelector->ChangeGroupSelected(m_Person->m_FirstGroupID);
	m_SecondGroupSelector->ChangeGroupSelected(m_Person->m_SecondGroupID);

	Super::NativeConstruct();
}

void URDUIModifyPerson::ModifyPerson()
{
	bool modifyCheck = false;

	if ((!m_PersonName.IsEmpty()) && (m_PersonName != m_Person->m_Name))
	{
		modifyCheck = true;
	}

	if (m_FirstGroupSelector->GetGroup()->m_ID != m_Person->m_FirstGroupID)
	{
		modifyCheck = true;
	}

	if (m_SecondGroupSelector->GetGroup()->m_ID != m_Person->m_SecondGroupID)
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
			actionsToDo.AddUObject(this, &URDUIModifyPerson::ApplyModifyPerson);
			popupConfirme->InitPopupValue("Do you want to apply this changes", actionsToDo);
		}
	}
	else
	{
		URDFunctionLibrary::ReturnToLastManuState();
	}

}

void URDUIModifyPerson::ApplyModifyPerson()
{
	m_Person->m_Name = m_PersonName;
	m_Person->m_FirstGroupID = m_FirstGroupSelector->GetGroup()->m_ID;
	m_Person->m_SecondGroupID = m_SecondGroupSelector->GetGroup()->m_ID;

	URDFunctionLibrary::LaunchSaveData();
	URDFunctionLibrary::GetPersonManager()->SetPersonModify(nullptr);
	URDFunctionLibrary::ReturnToLastManuState();
}
