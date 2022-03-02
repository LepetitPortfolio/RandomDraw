// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Screens/RDUIViewerPerson.h"
#include "Kismet/GameplayStatics.h"
#include "FunctionLibrary/RDFunctionLibrary.h"
#include "System/RandomDrawGameMode.h"
#include "Components/ScrollBox.h"
#include "Structs/RDPerson.h"
#include "UI/Widgets/RDWidgetPersonLine.h"

void URDUIViewerPerson::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void URDUIViewerPerson::NativeConstruct()
{

	InitScrollBox();

	Super::NativeConstruct();
}

void URDUIViewerPerson::InitScrollBox()
{
	m_WidgetList->ClearChildren();
	TMap<FString, FRDPerson>* persons = &URDFunctionLibrary::GetAppData()->m_Persons;

	if ((persons == nullptr) || (persons == NULL) || (persons->Num() == 0))
	{
		return;
	}

	for (TMap<FString, FRDPerson>::TIterator it = persons->CreateIterator(); it; ++it)
	{
		URDWidgetPersonLine* PersonLine = CreateWidget<URDWidgetPersonLine>(UGameplayStatics::GetPlayerController(this, 0), m_WidgetTemplate);
		if (PersonLine)
		{
			PersonLine->InitValue(&persons->operator[](it->Key), this);
			m_WidgetList->AddChild(PersonLine);
		}
	}


}


void URDUIViewerPerson::ResetScrollBox()
{
	InitScrollBox();
}