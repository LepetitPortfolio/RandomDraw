// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Popups/RDPopupSaveDrawing.h"
#include "FunctionLibrary/RDFunctionLibrary.h"
#include "Managers/RDRandomDrawManager.h"

void URDPopupSaveDrawing::SaveDrawing()
{
	URDFunctionLibrary::GetRandomDrawManager()->SaveDrawing(m_SaveName);

	URDFunctionLibrary::LaunchSaveData();
}

void URDPopupSaveDrawing::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void URDPopupSaveDrawing::NativeConstruct()
{
	Super::NativeConstruct();
}
