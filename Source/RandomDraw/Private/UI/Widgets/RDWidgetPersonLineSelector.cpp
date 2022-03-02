// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/RDWidgetPersonLineSelector.h"
#include "FunctionLibrary/RDFunctionLibrary.h"
#include "UI/Screens/RDUIViewerPersonsSelector.h"

void URDWidgetPersonLineSelector::InitValue(class URDUIViewerPersonsSelector* _PersonsSelector, FRDPerson* _Person)
{
	m_Person = _Person;

	m_PersonName = m_Person->m_Name;
	m_Color = URDFunctionLibrary::GetAppData()->m_Groups.operator[](m_Person->m_FirstGroupID).m_Color;

	m_PersonsSelector = _PersonsSelector;
}

void URDWidgetPersonLineSelector::SetSelected(bool _Value)
{
	m_Check = _Value;
}


void URDWidgetPersonLineSelector::SelectPairWidgetLine(bool _Value)
{
	m_PersonsSelector->SelectPersonLineSelectorPair(m_Person, _Value);
}
