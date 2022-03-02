// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Screens/RDUIViewerGroup.h"
#include "Kismet/GameplayStatics.h"
#include "FunctionLibrary/RDFunctionLibrary.h"
#include "System/RandomDrawGameMode.h"
#include "Components/ScrollBox.h"
#include "Structs/RDGroup.h"
#include "UI/Widgets/RDWidgetGroupLine.h"

void URDUIViewerGroup::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void URDUIViewerGroup::NativeConstruct()
{

	InitScrollBox();

	Super::NativeConstruct();
}

void URDUIViewerGroup::InitScrollBox()
{
	m_WidgetList->ClearChildren();
	TMap<FString, FRDGroup>* Groups = &URDFunctionLibrary::GetAppData()->m_Groups;

	if ((Groups == nullptr) || (Groups == NULL) || (Groups->Num() == 0))
	{
		return;
	}

	for (TMap<FString, FRDGroup>::TIterator it = Groups->CreateIterator(); it; ++it)
	{
		URDWidgetGroupLine* GroupLine = CreateWidget<URDWidgetGroupLine>(UGameplayStatics::GetPlayerController(this, 0), m_WidgetTemplate);

		if (GroupLine)
		{
			GroupLine->InitValue(&Groups->operator[](it->Key), this);
			m_WidgetList->AddChild(GroupLine);

		}
	}
}

void URDUIViewerGroup::ResetScrollBox()
{
	InitScrollBox();
}
