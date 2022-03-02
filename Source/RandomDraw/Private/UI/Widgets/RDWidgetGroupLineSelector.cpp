// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/RDWidgetGroupLineSelector.h"
#include "UI/Screens/RDUIViewerPersonsSelector.h"


void URDWidgetGroupLineSelector::InitValue(class URDUIViewerPersonsSelector* _PersonsSelectorView, FRDGroup* _Group)
{

	if (!_Group)
	{
		return;
	}

	m_Group = _Group;
	m_Libelle = m_Group->m_Libelle;
	m_Color = m_Group->m_Color;

	m_PersonsSelectorView = _PersonsSelectorView;
}

void URDWidgetGroupLineSelector::SetSelected(bool _Value)
{
	m_Check = _Value;
}

void URDWidgetGroupLineSelector::SelectAllGroupMember(bool _Value)
{
	SetSelected(_Value);
	m_PersonsSelectorView->SelectAllGroupMember(m_Group, _Value);
}
