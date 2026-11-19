// Fill out your copyright notice in the Description page of Project Settings.


#include "Managers/RDScreenshotManager.h"
#include "Engine/Texture2D.h"
#include "IImageWrapperModule.h"
#include "Modules/ModuleManager.h"
#include "Misc/FileHelper.h"
#include "HAL/PlatformFilemanager.h"
#include "Structs/RDRandomDraw.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Slate/WidgetRenderer.h"
#include "Engine/World.h"

#include "ImageUtils.h"
#include "HAL/FileManager.h"

#include "FunctionLibrary/RDFunctionLibrary.h"
#include "System/RDHUD.h"


FString  URDScreenshotManager::TakeScreenshotOfRandomDraw(FRDRandomDraw _RandomDraw)
{
	ARDHUD* hud =URDFunctionLibrary::GetRDHUD();

	if (!hud)
	{
		return FString();
	}

	URDDrawScreenWidget* drawScreen = hud->GetDrawScreen();

	if (!drawScreen)
	{
		return FString();
	}

	drawScreen->GenerateRandomDrawList(&_RandomDraw);

	FString filePath = FString(FPaths::ScreenShotDir() + _RandomDraw.m_Libelle + "_" + FDateTime::Now().ToString(TEXT("%Y%m%d%H%M%S")) + ".png");

	if (SaveWidgetAsPNG(drawScreen, filePath, drawScreen->GetDrawScreenSize()))
	{
		return filePath;
	}

	return FString();
}

bool URDScreenshotManager::SaveWidgetAsPNG(UUserWidget* _Widget, const FString& _FilePath, FVector2D _Size)
{
	if (!_Widget) return false;

	// Crée un renderTarget
	UTextureRenderTarget2D* renderTarget = NewObject<UTextureRenderTarget2D>();
	renderTarget->InitCustomFormat(_Size.X, _Size.Y, PF_B8G8R8A8, false);
	renderTarget->ClearColor = FLinearColor::Transparent;

	// Render du widget
	FWidgetRenderer renderer(true);
	renderer.DrawWidget(renderTarget, _Widget->TakeWidget(), _Size, 0.f);

	// Lire les pixels
	TArray<FColor> pixels;
	FRenderTarget* renderTargetResource = renderTarget->GameThread_GetRenderTargetResource();
	renderTargetResource->ReadPixels(pixels);

	// Sauvegarde en PNG (utilise la fonction précédente)
	return SaveCustomPixelsAsImage(pixels, _Size.X, _Size.Y, _FilePath);
}

// Génère une image à partir d'un tableau de pixels
bool URDScreenshotManager::SaveCustomPixelsAsImage(const TArray<FColor>& _Pixels, int32 _Width, int32 _Height, const FString& _FilePath, EImageFormat _Format)
{
	if (_Pixels.Num() != _Width * _Height) return false;

	IImageWrapperModule& imageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>("ImageWrapper");
	TSharedPtr<IImageWrapper> imageWrapper = imageWrapperModule.CreateImageWrapper(_Format);

	if ((imageWrapper.IsValid()) && (imageWrapper->SetRaw(_Pixels.GetData(), _Pixels.Num() * sizeof(FColor), _Width, _Height, ERGBFormat::BGRA, 8)))
	{
		const TArray64<uint8>& compressedData = imageWrapper->GetCompressed(100);
		return FFileHelper::SaveArrayToFile(compressedData, *_FilePath);
	}

	return false;
}
