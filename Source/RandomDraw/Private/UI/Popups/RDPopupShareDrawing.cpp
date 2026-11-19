// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Popups/RDPopupShareDrawing.h"
#include "FunctionLibrary/RDFunctionLibrary.h"
#include "Managers/RDShareManager.h"
#include "Managers/RDScreenshotManager.h"
#include "HAL/FileManager.h"
#include "Misc/Paths.h"


void URDPopupShareDrawing::ShareDrawing()
{
    URDShareManager* ShareManager = URDFunctionLibrary::GetShareManager();
    URDScreenshotManager* ScreenshotManager = URDFunctionLibrary::GetScreenshotManager();
    if (!ShareManager || !ScreenshotManager)
    {
        UE_LOG(LogTemp, Error, TEXT("[RDShare] Manager manquant (Share=%d, Screenshot=%d)"),
            ShareManager != nullptr, ScreenshotManager != nullptr);
        return;
    }

    const FRDRandomDraw RandomDraw = ShareManager->GetRandomDrawInWait();
    FString ScreenshotPath = ScreenshotManager->TakeScreenshotOfRandomDraw(RandomDraw);

    if (ScreenshotPath.IsEmpty())
    {
        UE_LOG(LogTemp, Error, TEXT("[RDShare] Chemin de capture vide"));
        return;
    }

    // Chemin absolu obligatoire pour FileProvider
    ScreenshotPath = FPaths::ConvertRelativePathToFull(ScreenshotPath);
#if PLATFORM_ANDROID
    ScreenshotPath = IFileManager::Get().ConvertToAbsolutePathForExternalAppForWrite(*ScreenshotPath);
#endif

    UE_LOG(LogTemp, Log, TEXT("[RDShare] ShareDrawing -> %s (existe=%d)"),
        *ScreenshotPath, FPaths::FileExists(ScreenshotPath));

    ShareManager->ShareImage(ScreenshotPath, m_MessageAttached);
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