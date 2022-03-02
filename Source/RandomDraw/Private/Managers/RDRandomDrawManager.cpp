// Fill out your copyright notice in the Description page of Project Settings.


#include "Managers/RDRandomDrawManager.h"
#include "Math/UnrealMathUtility.h"
#include "FunctionLibrary/RDFunctionLibrary.h"
#include "Structs/RDAppData.h"

bool URDRandomDrawManager::LaunchDrawing(TArray<FRDPerson*> _Persons, bool _IgnoreGroup)
{
	m_RandomDraw = FRDRandomDraw();

	TMap<FString, FRDPerson>* personsMap = &URDFunctionLibrary::GetAppData()->m_Persons;

	TArray<FRDPerson*> jar = _Persons;

	int personIndex = 0;

	int drawingTry = 0;

	while ((personIndex < _Persons.Num()) && (drawingTry < m_MaxDrawingTry))
	{
		FRDDraw draw = FRDDraw();
		FRDPerson* person = _Persons[personIndex];
		draw.m_FirstPersonID = person->m_ID;
		TArray<FRDPerson*> hat = TArray<FRDPerson*>();



		for (int pIndex = 0; pIndex < jar.Num(); pIndex++)
		{
			FRDPerson* p = jar[pIndex];
			if (p->m_ID != person->m_ID)
			{
				if (!_IgnoreGroup)
				{
					
					if(!person->GetIsInSameGroup(p))
					{
						hat.Add(p);
					}
					
				}
				else
				{
					hat.Add(p);
				}
			}

		}

		if ((hat.Num() == 0) && (jar.Num() != 0))
		{
			jar = _Persons;
			personIndex = 0;
			drawingTry++;
			m_RandomDraw.m_Draws.Reset();
		}
		else
		{
			int indexRand = FMath::RandRange(0, hat.Num() - 1);

			FRDPerson* hatPerson = hat[indexRand];
			draw.m_SecondPersonID = hatPerson->m_ID;

			jar.Remove(hatPerson);

			m_RandomDraw.m_Draws.Add(draw);
			personIndex++;
		}
	}

	if (drawingTry < m_MaxDrawingTry)
	{
		return true;
	}

	return false;
}

void URDRandomDrawManager::SaveDrawing(FString _DrawingName)
{
	FRDAppData* appdata = URDFunctionLibrary::GetAppData();

	m_RandomDraw.m_Libelle = _DrawingName;

	bool newIDFounf = false;
	int index = 0;

	while (!newIDFounf)
	{
		FString newID = FString::Chr(m_RandomDraw.m_Libelle[0]) + FString::FromInt(index);
		if (!appdata->m_RandomDraws.Contains(newID))
		{
			newIDFounf = true;
			m_RandomDraw.m_ID = newID;
		}
		else
		{
			index++;
		}
	}

	FixRandomDrawValues(&m_RandomDraw);

	appdata->m_RandomDraws.Add(m_RandomDraw.m_ID, m_RandomDraw);
}

void URDRandomDrawManager::FixRandomDrawValues(FRDRandomDraw* _RandomDraw)
{
	TArray<FRDDraw>* draws = &_RandomDraw->m_Draws;
	for (int drawIndex = 0; drawIndex < draws->Num(); drawIndex++)
	{
		FRDDraw* draw = &draws->operator[](drawIndex);
		FRDPerson* firstPerson = URDFunctionLibrary::GetPerson(draw->m_FirstPersonID);
		FRDGroup* firstGroup = URDFunctionLibrary::GetGroup(firstPerson->m_FirstGroupID);

		FRDPerson* secondPerson = URDFunctionLibrary::GetPerson(draw->m_SecondPersonID);
		FRDGroup* secondGroup = URDFunctionLibrary::GetGroup(secondPerson->m_FirstGroupID);

		draw->m_FirstPersonName = firstPerson->m_Name;
		draw->m_FirstPersonColor = firstGroup->m_Color;

		draw->m_SecondPersonName = secondPerson->m_Name;
		draw->m_SecondPersonColor = secondGroup->m_Color;
	}
}

void URDRandomDrawManager::DeleteRandomDraw(FRDRandomDraw* _RandomDraw)
{
	URDFunctionLibrary::GetAppData()->m_RandomDraws.Remove(_RandomDraw->m_ID);
}
