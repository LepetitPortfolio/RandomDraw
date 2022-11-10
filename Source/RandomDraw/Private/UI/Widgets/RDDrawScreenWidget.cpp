// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/RDDrawScreenWidget.h"
#include "Kismet/GameplayStatics.h"
#include "UI/Widgets/RDWidgetDrawLine.h"

void URDDrawScreenWidget::GenerateRandomDrawList(FRDRandomDraw* _RandomDraw)
{
	ClearAllWidget();

	m_RandomDrawLibelle = _RandomDraw->m_Libelle;

	TArray<FRDDraw>* draws = &_RandomDraw->m_Draws;

	for (int drawIndex = 0; drawIndex < draws->Num(); drawIndex++)
	{
		URDWidgetDrawLine* drawLine = CreateWidget<URDWidgetDrawLine>(UGameplayStatics::GetPlayerController(this, 0), m_WidgetTemplate);

		if (drawLine)
		{
			drawLine->InitValue(&draws->operator[](drawIndex));
			AddWidgetInScreen(drawLine, true);
		}
	}


}
