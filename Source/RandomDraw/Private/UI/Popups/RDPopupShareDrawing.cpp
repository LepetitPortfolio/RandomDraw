// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Popups/RDPopupShareDrawing.h"
#include "FunctionLibrary/RDFunctionLibrary.h"
#include "Managers/RDShareManager.h"
#include "Managers/RDScreenshotManager.h"


void URDPopupShareDrawing::ShareDrawing()
{
	FRDRandomDraw m_RandomDraw = URDFunctionLibrary::GetShareManager()->GetRandomDrawInWait();
	FString screenshotPath = URDFunctionLibrary::GetScreenshotManager()->TakeScreenshotOfRandomDraw(m_RandomDraw);
	URDFunctionLibrary::GetShareManager()->ShareImage(screenshotPath, m_MessageAttached);
}

void URDPopupShareDrawing::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void URDPopupShareDrawing::NativeConstruct()
{
	Super::NativeConstruct();
}

void URDPopupShareDrawing::ClosePopup()
{
	URDFunctionLibrary::GetShareManager()->ClearRandomDrawIDInWait();

	Super::ClosePopup();
}