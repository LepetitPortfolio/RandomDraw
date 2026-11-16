// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/RDWidgetThemesSelector.h"
#include "UI/Widgets/RDWidgetThemeLine.h"
#include "FunctionLibrary/RDFunctionLibrary.h"
#include "System/RandomDrawGameMode.h"
#include "Managers/RDThemeManager.h"

void URDWidgetThemesSelector::InitValue()
{
	ARandomDrawGameMode* randomDrawGameMode = URDFunctionLibrary::GetRDGameMode();

	if (randomDrawGameMode)
	{
		randomDrawGameMode->GetThemeDataTable()->GetAllRows<FRDTheme>("", m_ThemeList);
	}

	if(m_ThemeList.Num() > 0)
	{
		for (FRDTheme* theme : m_ThemeList)
		{
			if (theme)
			{
				URDWidgetThemeLine* themeLine = CreateWidget<URDWidgetThemeLine>(this, m_ThemeLineTemplate);
				if (themeLine)
				{
					themeLine->InitValue(theme, this);
					m_WidgetList->AddChild(themeLine);
				}
			}
		}
	}

}


void URDWidgetThemesSelector::ChangeThemeSelected(FRDTheme* _Theme)
{
	m_ScrollBox->SetVisibility(ESlateVisibility::Collapsed);

	URDFunctionLibrary::GetThemeManager()->SetCurrentTheme(*_Theme);
}
