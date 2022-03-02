// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Screens/RDUIRandomDrawViewer.h"
#include "Kismet/GameplayStatics.h"
#include "FunctionLibrary/RDFunctionLibrary.h"
#include "System/RandomDrawGameMode.h"
#include "Components/ScrollBox.h"
#include "Managers/RDRandomDrawManager.h"
#include "UI/Widgets/RDWidgetDrawLine.h"


void URDUIRandomDrawViewer::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void URDUIRandomDrawViewer::NativeConstruct()
{
	m_RandomDraw = URDFunctionLibrary::GetRandomDrawManager()->GetRandomDrawView();

	m_RandomDrawLibelle = m_RandomDraw->m_Libelle;

	InitScrollBox();


	Super::NativeConstruct();
}

void URDUIRandomDrawViewer::InitScrollBox()
{


	m_WidgetList->ClearChildren();

	TArray<FRDDraw>* draws = &m_RandomDraw->m_Draws;

	for (int drawIndex = 0; drawIndex < draws->Num(); drawIndex++)
	{
		URDWidgetDrawLine* drawLine = CreateWidget<URDWidgetDrawLine>(UGameplayStatics::GetPlayerController(this, 0), m_WidgetTemplate);

		if (drawLine)
		{
			drawLine->InitValue(&draws->operator[](drawIndex));
			m_WidgetList->AddChild(drawLine);

		}
	}
}