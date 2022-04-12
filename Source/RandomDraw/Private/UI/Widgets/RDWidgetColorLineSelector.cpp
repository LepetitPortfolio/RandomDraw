// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/RDWidgetColorLineSelector.h"
#include "UI/Widgets/RDWidgetColorSelector.h"

void URDWidgetColorLineSelector::InitValues(FLinearColor _Color, class URDWidgetColorSelector* _ColorSelector)
{
	m_Color = _Color;
	m_ColorSelector = _ColorSelector;
}

void URDWidgetColorLineSelector::SelectColor()
{
	m_ColorSelector->ChangeColorSelected(m_Color);
}
