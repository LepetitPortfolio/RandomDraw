// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/RDWidgetColorSelector.h"
#include "Kismet/GameplayStatics.h"
#include "FunctionLibrary/RDFunctionLibrary.h"

void URDWidgetColorSelector::ChangeColorSelected(FLinearColor _Color)
{
	m_Color = _Color;

	m_ScrollBox->SetVisibility(ESlateVisibility::Collapsed);
}

void URDWidgetColorSelector::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void URDWidgetColorSelector::NativeConstruct()
{
	m_WidgetList->ClearChildren();
	for (int colorIndex = 0; colorIndex < m_DefaultColors.Num(); colorIndex++)
	{
		URDWidgetColorLineSelector* colorSelector = CreateWidget<URDWidgetColorLineSelector>(UGameplayStatics::GetPlayerController(this, 0), m_ColorSelectorTemplate);

		if (colorSelector)
		{
			colorSelector->InitValues(m_DefaultColors[colorIndex], this);
			m_WidgetList->AddChild(colorSelector);
		}
	}

	Super::NativeConstruct();
}
