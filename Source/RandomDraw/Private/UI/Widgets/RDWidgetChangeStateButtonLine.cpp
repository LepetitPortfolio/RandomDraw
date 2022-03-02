// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/RDWidgetChangeStateButtonLine.h"
#include "FunctionLibrary/RDFunctionLibrary.h"


void URDWidgetChangeStateButtonLine::InitWidgetAttributs(FString _ButtonMessage, ERDMenuStat _StatSelected, ERDUIPriority _UIPriority)
{
	m_StatSelected = _StatSelected;
	m_UIPriority = _UIPriority;
	m_ButtonMessage = _ButtonMessage;
}


void URDWidgetChangeStateButtonLine::ChangeState()
{
	URDFunctionLibrary::ChangeMenuState(m_StatSelected, m_UIPriority);
}
