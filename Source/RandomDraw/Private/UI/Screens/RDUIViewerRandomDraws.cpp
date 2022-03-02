// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Screens/RDUIViewerRandomDraws.h"
#include "Kismet/GameplayStatics.h"
#include "FunctionLibrary/RDFunctionLibrary.h"
#include "System/RandomDrawGameMode.h"
#include "Components/ScrollBox.h"
#include "Structs/RDPerson.h"
#include "UI/Widgets/RDWidgetRandomDrawLine.h"

void URDUIViewerRandomDraws::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void URDUIViewerRandomDraws::NativeConstruct()
{

	InitScrollBox();

	Super::NativeConstruct();
}

void URDUIViewerRandomDraws::InitScrollBox()
{
	m_WidgetList->ClearChildren();
	TMap<FString, FRDRandomDraw>* randomDraws = &URDFunctionLibrary::GetAppData()->m_RandomDraws;

	if ((!randomDraws) || (randomDraws == NULL) || (randomDraws->Num() == 0))
	{
		return;
	}

	for (TMap<FString, FRDRandomDraw>::TIterator it = randomDraws->CreateIterator(); it; ++it)
	{
		URDWidgetRandomDrawLine* randomDrawLine = CreateWidget<URDWidgetRandomDrawLine>(UGameplayStatics::GetPlayerController(this, 0), m_WidgetTemplate);

		if (randomDrawLine)
		{
			randomDrawLine->InitValue(&randomDraws->operator[](it.Key()), it.Key(), this);
			m_WidgetList->AddChild(randomDrawLine);
		}
	}
}

void URDUIViewerRandomDraws::ResetScrollBox()
{
	InitScrollBox();
}