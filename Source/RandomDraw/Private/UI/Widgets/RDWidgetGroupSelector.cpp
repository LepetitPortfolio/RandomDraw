// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/RDWidgetGroupSelector.h"
#include "Kismet/GameplayStatics.h"
#include "FunctionLibrary/RDFunctionLibrary.h"
#include "System/RandomDrawGameMode.h"

void URDWidgetGroupSelector::NativeOnInitialized()
{
}

void URDWidgetGroupSelector::NativeConstruct()
{
	m_WidgetList->ClearChildren();

	URDWidgetGroupSelection* defaultGroupSelection = CreateWidget<URDWidgetGroupSelection>(UGameplayStatics::GetPlayerController(this, 0), m_GroupSelectionTemplate);

	ChangeGroupSelected(new FRDGroup());

	if (defaultGroupSelection)
	{
		defaultGroupSelection->InitValues(m_Group, this);
		m_WidgetList->AddChild(defaultGroupSelection);
	}


	TMap<FString, FRDGroup>* Groups = &URDFunctionLibrary::GetAppData()->m_Groups;

	for (TMap<FString, FRDGroup>::TIterator it = Groups->CreateIterator(); it; ++it)
	{

		URDWidgetGroupSelection* GroupSelection = CreateWidget<URDWidgetGroupSelection>(UGameplayStatics::GetPlayerController(this, 0), m_GroupSelectionTemplate);

		if (GroupSelection)
		{
			GroupSelection->InitValues(&Groups->operator[](it->Key), this);
			m_WidgetList->AddChild(GroupSelection);
		}
	}


}

void URDWidgetGroupSelector::ChangeGroupSelected(FString _GroupID)
{
	if (URDFunctionLibrary::GetAppData()->m_Groups.Contains(_GroupID))
	{
		ChangeGroupSelected(&URDFunctionLibrary::GetAppData()->m_Groups.operator[](_GroupID));
	}
}


void URDWidgetGroupSelector::ChangeGroupSelected(FRDGroup* _Group)
{
	m_Group = _Group;
	if (m_Group->m_Libelle.IsEmpty())
	{
		m_Group->m_Libelle = "None";
	}

	m_GroupNameSelected = m_Group->m_Libelle;
	m_GroupColorSelected = m_Group->m_Color;

	m_ScrollBox->SetVisibility(ESlateVisibility::Collapsed);
}
