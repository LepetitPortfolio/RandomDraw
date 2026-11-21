// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/RDWidgetDrawLine.h"
#include "FunctionLibrary/RDFunctionLibrary.h"

void URDWidgetDrawLine::InitValue(FRDDraw* _Draw)
{
	m_Draw = _Draw;

	FRDPerson* firstPerson = URDFunctionLibrary::GetPerson(m_Draw->m_FirstPersonID);
	m_FirstPersonLibelle = firstPerson->m_Name;
	m_FirstPersonColor = GetColorGroup(firstPerson->m_FirstGroupID);

	FRDPerson* secondPerson = URDFunctionLibrary::GetPerson(m_Draw->m_SecondPersonID);
	m_SecondPersonLibelle = secondPerson->m_Name;
	m_SecondPersonColor = GetColorGroup(secondPerson->m_FirstGroupID);

}

FVector2D URDWidgetDrawLine::GetDrawLineSize()
{
	FVector2D drawLineSize = FVector2D();
	if (m_WidgetChildRoot)
	{
		drawLineSize = FVector2D(m_WidgetChildRoot->WidthOverride, m_WidgetChildRoot->HeightOverride);
	}

	return drawLineSize;
}
