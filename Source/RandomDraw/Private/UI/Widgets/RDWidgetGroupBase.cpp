// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/RDWidgetGroupBase.h"

FSlateColor URDWidgetGroupBase::GetColorSelfGroup()
{
	if(!m_Group)
	{
		return FSlateColor(FLinearColor::Black);
	}

	return URDUIBase::GetColorGroup(m_Group->m_ID);
}
