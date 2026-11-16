// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/RDWidgetThemeLine.h"
#include "UI/Widgets/RDWidgetThemesSelector.h"

void URDWidgetThemeLine::InitValue(FRDTheme* _Theme, URDWidgetThemesSelector* _ThemesSelector)
{
	if (!_Theme)
	{
		return;
	}
	m_Theme = _Theme;
	m_ThemesSelector = _ThemesSelector;
}

FSlateColor URDWidgetThemeLine::GetNewThemeBackgroundColor()
{
	return m_Theme->Background;
}

FSlateColor URDWidgetThemeLine::GetNewThemeTextPrimaryColor()
{
	return m_Theme->TextPrimary;
}

FText URDWidgetThemeLine::GetNewThemeName()
{
	return FText::FromName(m_Theme->ThemeName);
}

void URDWidgetThemeLine::Select()
{
	m_ThemesSelector->ChangeThemeSelected(m_Theme);
}
