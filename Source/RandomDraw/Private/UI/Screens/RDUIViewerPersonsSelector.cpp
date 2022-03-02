// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Screens/RDUIViewerPersonsSelector.h"
#include "Kismet/GameplayStatics.h"
#include "FunctionLibrary/RDFunctionLibrary.h"
#include "System/RandomDrawGameMode.h"
#include "Components/ScrollBox.h"
#include "Structs/RDPerson.h"
#include "Managers/RDRandomDrawManager.h"
#include "UI/Widgets/RDWidgetPersonLineSelector.h"
#include "UI/Popups/RDPopupError.h"
#include "UI/Widgets/RDWidgetGroupLineSelector.h"



void URDUIViewerPersonsSelector::SelectPersonLineSelectorPair(FRDPerson* _Person, bool _Value)
{
	TMap<FString, FRDGroup>* Groups = &URDFunctionLibrary::GetAppData()->m_Groups;
	m_PersonLineSelectors[_Person].Key->SetSelected(_Value);
	m_PersonLineSelectors[_Person].Value->SetSelected(_Value);

	if (!_Value)
	{
		m_GroupLineSelectors[&Groups->operator[](_Person->m_FirstGroupID)]->SetSelected(false);

	}
	else if (CheckIfAllGroupMemberIsSelected(&Groups->operator[](_Person->m_FirstGroupID)))
	{
		m_GroupLineSelectors[&Groups->operator[](_Person->m_FirstGroupID)]->SetSelected(true);
	}

}

void URDUIViewerPersonsSelector::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void URDUIViewerPersonsSelector::NativeConstruct()
{
	InitScrollBox();
	Super::NativeConstruct();
}

void URDUIViewerPersonsSelector::InitScrollBox()
{

	m_PersonLineSelectors.Reset();
	m_GroupLineSelectors.Reset();

	InitSortByGroup();

	InitNoSort();
}

bool URDUIViewerPersonsSelector::LaunchRandomDrawing()
{
	bool lauchSucess = true;
	TMap<FString, FRDPerson>* persons = &URDFunctionLibrary::GetAppData()->m_Persons;
	TArray<FRDPerson*> personsList = TArray<FRDPerson*>();

	for (TMap<FString, FRDPerson>::TIterator it = persons->CreateIterator(); it; ++it)
	{
		FRDPerson* person = &persons->operator[](it.Key());
		TPair<class URDWidgetPersonLineSelector*, class URDWidgetPersonLineSelector*>* widgetPersonPair = &m_PersonLineSelectors[person];
		if ((widgetPersonPair->Key->GetIsCheck()) || (widgetPersonPair->Value->GetIsCheck()))
		{
			personsList.Add(person);
		}
	}

	if (!URDFunctionLibrary::GetRandomDrawManager()->LaunchDrawing(personsList, false))
	{
		URDFunctionLibrary::DisplayPopupUI(ERDPopupUI::ErrorPopup);

		URDPopupError* popupError = Cast<URDPopupError>(URDFunctionLibrary::GetPopupUI());

		if (popupError)
		{
			popupError->InitPopupValue("The draw had failed : Retry or this this draw is Impossible");
		}

		lauchSucess = false;
	}

	return lauchSucess;
}

bool URDUIViewerPersonsSelector::CheckIfAllGroupMemberIsSelected(FRDGroup* _Group)
{
	
	TMap<FString, FRDPerson>* persons = &URDFunctionLibrary::GetAppData()->m_Persons;
	bool check = true;
	int personIndex = 0;
	TMap<FString, FRDPerson>::TIterator it = persons->CreateIterator();
	while ((check) && (it))
	{
		FRDPerson* person = &persons->operator[](it.Key());
		if (person->m_FirstGroupID == _Group->m_ID)
		{
			TPair<class URDWidgetPersonLineSelector*, class URDWidgetPersonLineSelector*>* widgetPersonPair = &m_PersonLineSelectors[person];
			if ((!widgetPersonPair->Key->GetIsCheck()) || (!widgetPersonPair->Value->GetIsCheck()))
			{
				check = false;
			}
		}
		++it;
	}



	return check;
}

void URDUIViewerPersonsSelector::InitSortByGroup()
{
	m_SecondWidgetList->ClearChildren();
	TMap<FString, FRDPerson>* persons = &URDFunctionLibrary::GetAppData()->m_Persons;
	TMap<FString, FRDGroup>* Groups = &URDFunctionLibrary::GetAppData()->m_Groups;

	for (TMap<FString, FRDGroup>::TIterator itF = Groups->CreateIterator(); itF; ++itF)
	{
		FRDGroup* Group = &Groups->operator[](itF.Key());
		URDWidgetGroupLineSelector* GroupLine = CreateWidget<URDWidgetGroupLineSelector>(UGameplayStatics::GetPlayerController(this, 0), m_SecondWidgetTemplate);
		if (GroupLine)
		{
			GroupLine->InitValue(this, Group);
			m_SecondWidgetList->AddChild(GroupLine);
			m_GroupLineSelectors.Add(Group, GroupLine);

			for (TMap<FString, FRDPerson>::TIterator itP = persons->CreateIterator(); itP; ++itP)
			{
				FRDPerson* person = &persons->operator[](itP.Key());
				if (person->m_FirstGroupID == Group->m_ID)
				{
					URDWidgetPersonLineSelector* personLine = CreateWidget<URDWidgetPersonLineSelector>(UGameplayStatics::GetPlayerController(this, 0), m_WidgetTemplate);

					if (personLine)
					{
						personLine->InitValue(this, person);
						m_SecondWidgetList->AddChild(personLine);

						if (!m_PersonLineSelectors.Contains(person))
						{
							TPair<class URDWidgetPersonLineSelector*, class URDWidgetPersonLineSelector*> personLineSelector;
							personLineSelector.Key = personLine;
							personLineSelector.Value = nullptr;
							m_PersonLineSelectors.Add(person, personLineSelector);
						}
						else
						{
							m_PersonLineSelectors[person].Key = personLine;
						}

					}
				}
			}
		}
	}
	

	if (!m_SecondChangeStateButtonLine)
	{
		m_SecondChangeStateButtonLine = CreateWidget<URDWidgetChangeStateButtonLine>(UGameplayStatics::GetPlayerController(this, 0), m_ChangeStateButtonLineTemplate);

		m_SecondChangeStateButtonLine->InitWidgetAttributs("Create a new Person", ERDMenuStat::CreatePerson, ERDUIPriority::Priority1);
	}

	m_SecondWidgetList->AddChild(m_SecondChangeStateButtonLine);
}

void URDUIViewerPersonsSelector::InitNoSort()
{
	m_WidgetList->ClearChildren();
	TMap<FString, FRDPerson>* persons = &URDFunctionLibrary::GetAppData()->m_Persons;

	for (TMap<FString, FRDPerson>::TIterator it = persons->CreateIterator(); it; ++it)
	{
		FRDPerson* person = &persons->operator[](it.Key());
		URDWidgetPersonLineSelector* personLine = CreateWidget<URDWidgetPersonLineSelector>(UGameplayStatics::GetPlayerController(this, 0), m_WidgetTemplate);

		if (personLine)
		{
			personLine->InitValue(this, person);
			m_WidgetList->AddChild(personLine);

			if (!m_PersonLineSelectors.Contains(person))
			{
				TPair<class URDWidgetPersonLineSelector*, class URDWidgetPersonLineSelector*> personLineSelector;
				personLineSelector.Key = nullptr;
				personLineSelector.Value = personLine;
				m_PersonLineSelectors.Add(person, personLineSelector);
			}
			else
			{
				m_PersonLineSelectors[person].Value = personLine;
			}
		}
	}

	if (!m_FirstChangeStateButtonLine)
	{
		m_FirstChangeStateButtonLine = CreateWidget<URDWidgetChangeStateButtonLine>(UGameplayStatics::GetPlayerController(this, 0), m_ChangeStateButtonLineTemplate);

		m_FirstChangeStateButtonLine->InitWidgetAttributs("Create a new Person", ERDMenuStat::CreatePerson, ERDUIPriority::Priority1);
	}

	m_WidgetList->AddChild(m_FirstChangeStateButtonLine);
}


void URDUIViewerPersonsSelector::SelectAllGroupMember(FRDGroup* _Group, bool _Selected)
{
	TMap<FString, FRDPerson>* persons = &URDFunctionLibrary::GetAppData()->m_Persons;

	for (TMap<FString, FRDPerson>::TIterator it = persons->CreateIterator(); it; ++it)
	{
		FRDPerson* person = &persons->operator[](it.Key());
		if (person->m_FirstGroupID == _Group->m_ID)
		{
			m_PersonLineSelectors[person].Key->SetSelected(_Selected);
			m_PersonLineSelectors[person].Value->SetSelected(_Selected);
		}
	}
}