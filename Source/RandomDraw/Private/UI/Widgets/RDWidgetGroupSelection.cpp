// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/RDWidgetGroupSelection.h"
#include "UI/Widgets/RDWidgetGroupSelector.h"


void URDWidgetGroupSelection::InitValues(FRDGroup* _Group, class URDWidgetGroupSelector* _GroupSelector)
{
	if (!_Group)
	{
		return;
	}
	m_Group = _Group;
	m_Libelle = m_Group->m_Libelle;
	m_Color = m_Group->m_Color;

	m_GroupSelector = _GroupSelector;
}

void URDWidgetGroupSelection::Select()
{
	m_GroupSelector->ChangeGroupSelected(m_Group);
}
