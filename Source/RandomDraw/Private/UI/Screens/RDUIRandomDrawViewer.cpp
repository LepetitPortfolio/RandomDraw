// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Screens/RDUIRandomDrawViewer.h"
#include "Kismet/GameplayStatics.h"
#include "FunctionLibrary/RDFunctionLibrary.h"
#include "System/RandomDrawGameMode.h"
#include "System/RDHUD.h"
#include "Components/ScrollBox.h"
#include "Managers/RDRandomDrawManager.h"
#include "UI/Widgets/RDDrawScreenWidget.h"
#include "UI/Widgets/RDWidgetDrawLine.h"
#include "Managers/RDScreenshotManager.h"
#include "Managers/RDShareManager.h"


void URDUIRandomDrawViewer::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void URDUIRandomDrawViewer::NativeConstruct()
{
	m_RandomDraw = URDFunctionLibrary::GetRandomDrawManager()->GetRandomDrawView();

	m_RandomDrawLibelle = m_RandomDraw->m_Libelle;

	InitScrollBox();

	URDFunctionLibrary::GetRDHUD()->GetDrawScreen()->GenerateRandomDrawList(m_RandomDraw);

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

void URDUIRandomDrawViewer::ShareDraw()
{
	//URDFunctionLibrary::GetShareManager()->SetRandomDrawIDInWait(m_RandomDraw);

    URDShareManager* ShareManager = URDFunctionLibrary::GetShareManager();
    URDScreenshotManager* ScreenshotManager = URDFunctionLibrary::GetScreenshotManager();
    if (!ShareManager || !ScreenshotManager)
    {
        UE_LOG(LogTemp, Error, TEXT("[RDShare] Manager manquant (Share=%d, Screenshot=%d)"),
            ShareManager != nullptr, ScreenshotManager != nullptr);
        return;
    }

    FString ScreenshotPath = ScreenshotManager->TakeScreenshotOfRandomDraw(m_RandomDraw);

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

    ShareManager->ShareImage(ScreenshotPath, "");
}
