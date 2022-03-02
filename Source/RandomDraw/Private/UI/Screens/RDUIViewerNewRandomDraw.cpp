// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Screens/RDUIViewerNewRandomDraw.h"
#include "Kismet/GameplayStatics.h"
#include "FunctionLibrary/RDFunctionLibrary.h"
#include "System/RandomDrawGameMode.h"
#include "Components/ScrollBox.h"
#include "Structs/RDDraw.h"
#include "UI/Widgets/RDWidgetDrawLine.h"
#include "Managers/RDRandomDrawManager.h"

void URDUIViewerNewRandomDraw::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void URDUIViewerNewRandomDraw::NativeConstruct()
{

	InitScrollBox();

	Super::NativeConstruct();
}

void URDUIViewerNewRandomDraw::InitScrollBox()
{
	m_RandomDraw = URDFunctionLibrary::GetRandomDrawManager()->GetRandomDraw();
	TArray<FRDDraw>* draws = &m_RandomDraw->m_Draws;

	if ((draws == nullptr) || (draws == NULL) || (draws->Num() == 0))
	{
		return;
	}

	m_WidgetList->ClearChildren();
	
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
