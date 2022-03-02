// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/RDWidgetDrawLine.h"
#include "FunctionLibrary/RDFunctionLibrary.h"

void URDWidgetDrawLine::InitValue(FRDDraw* _Draw)
{
	m_Draw = _Draw;

	if (m_Draw->m_FirstPersonName.IsEmpty())
	{
		FRDPerson* firstPerson = URDFunctionLibrary::GetPerson(m_Draw->m_FirstPersonID);
		m_FirstPersonLibelle = firstPerson->m_Name;
		m_FirstPersonColor = URDFunctionLibrary::GetGroup(firstPerson->m_FirstGroupID)->m_Color;
	}
	else
	{
		m_FirstPersonLibelle = m_Draw->m_FirstPersonName;
		m_FirstPersonColor = m_Draw->m_FirstPersonColor;
	}

	if (m_Draw->m_SecondPersonName.IsEmpty())
	{
		FRDPerson* secondPerson = URDFunctionLibrary::GetPerson(m_Draw->m_SecondPersonID);
		m_SecondPersonLibelle = secondPerson->m_Name;
		m_SecondPersonColor = URDFunctionLibrary::GetGroup(secondPerson->m_FirstGroupID)->m_Color;
	}
	else
	{
		m_SecondPersonLibelle = m_Draw->m_SecondPersonName;
		m_SecondPersonColor = m_Draw->m_SecondPersonColor;
	}


}
