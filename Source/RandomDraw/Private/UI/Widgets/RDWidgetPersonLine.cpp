// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/RDWidgetPersonLine.h"
#include "FunctionLibrary/RDFunctionLibrary.h"
#include "UI/Screens/RDUIViewerPerson.h"
#include "UI/Popups/RDPopupConfirmeAction.h"
#include "Managers/RDPersonManager.h"

void URDWidgetPersonLine::InitValue(FRDPerson* _Person, URDUIViewerPerson* _ViewerPerson)
{
	m_Person = _Person;
	m_ViewerPerson = _ViewerPerson;

	m_PersonName = m_Person->m_Name;
	m_Color = GetColorGroup(m_Person->m_FirstGroupID);
}

void URDWidgetPersonLine::DeleteThePerson()
{
	URDFunctionLibrary::DisplayPopupUI(ERDPopupUI::ValidateActionPopup);

	URDPopupConfirmeAction* popupConfirme = Cast<URDPopupConfirmeAction>(URDFunctionLibrary::GetPopupUI());

	if (popupConfirme)
	{
		FValidateAction actionsToDo;
		actionsToDo.AddUObject(this, &URDWidgetPersonLine::ApplyDeleteGroup);
		popupConfirme->InitPopupValue("Do you want to deleted this Person", actionsToDo);
	}

	
}

void URDWidgetPersonLine::ApplyDeleteGroup()
{
	URDFunctionLibrary::GetPersonManager()->DeletePerson(m_Person);
	m_ViewerPerson->ResetScrollBox();
	URDFunctionLibrary::LaunchSaveData();
}

void URDWidgetPersonLine::ModifyThePerson()
{
	URDFunctionLibrary::GetPersonManager()->SetPersonModify(m_Person);
	URDFunctionLibrary::ChangeMenuState(ERDMenuStat::ModifyPerson);
}
