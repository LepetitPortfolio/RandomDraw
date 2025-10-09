// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/RDDrawScreenWidget.h"
#include "Kismet/GameplayStatics.h"
#include "UI/Widgets/RDWidgetDrawLine.h"

void URDDrawScreenWidget::GenerateRandomDrawList(FRDRandomDraw* _RandomDraw)
{
	ClearDrawScreen();

	m_RandomDrawLibelle = _RandomDraw->m_Libelle;

	TArray<FRDDraw>* draws = &_RandomDraw->m_Draws;

	for (int drawIndex = 0; drawIndex < draws->Num(); drawIndex++)
	{
		URDWidgetDrawLine* drawLine = CreateWidget<URDWidgetDrawLine>(UGameplayStatics::GetPlayerController(this, 0), m_WidgetTemplate);

		if (drawLine)
		{
			drawLine->InitValue(&draws->operator[](drawIndex));
			m_WidgetList->AddChild(drawLine);
			FVector2D drawLineSize = drawLine->GetDrawLineSize();
			drawLineSize.X = 0;
			AddDrawScreenSize(drawLineSize);
			
		}
	}
}

FVector2D URDDrawScreenWidget::GetDrawScreenSize()
{
	FVector2D drawScreenSize = FVector2D();
	if (m_WidgetChildRoot)
	{
		drawScreenSize = FVector2D(m_WidgetChildRoot->WidthOverride, m_WidgetChildRoot->HeightOverride);
	}

	return drawScreenSize;
}

void URDDrawScreenWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (m_WidgetChildRoot)
	{
		m_DefaultWidgetRootSize = FVector2D(m_WidgetChildRoot->WidthOverride, m_WidgetChildRoot->HeightOverride);
	}
}

void URDDrawScreenWidget::NativeConstruct()
{
	Super::NativeConstruct();

}

void URDDrawScreenWidget::ClearDrawScreen()
{
	if (m_WidgetChildRoot)
	{
		m_WidgetChildRoot->WidthOverride = m_DefaultWidgetRootSize.X;
		m_WidgetChildRoot->HeightOverride = m_DefaultWidgetRootSize.Y;
	}

	if (m_WidgetList)
	{
		m_WidgetList->ClearChildren();
	}
}

void URDDrawScreenWidget::AddDrawScreenSize(FVector2D _AddSize)
{
	if (m_WidgetChildRoot)
	{
		m_WidgetChildRoot->WidthOverride += _AddSize.X;
		m_WidgetChildRoot->HeightOverride += _AddSize.Y;
	}
}
