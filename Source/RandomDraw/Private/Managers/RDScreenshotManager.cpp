// Fill out your copyright notice in the Description page of Project Settings.


#include "Managers/RDScreenshotManager.h"
#include "HighResScreenshot.h"
#include "ImageWriteTask.h"
#include "ImagePixelData.h"
#include "ImageWriteQueue.h"
#include "Slate/WidgetRenderer.h"

UTextureRenderTarget2D* URDScreenshotManager::RenderWidgetToTexture(bool _UseGamma, TextureFilter _Filter, UUserWidget* _WidgetToRender, FVector2D _DrawSize, float _DeltaTime)
{
	if (!_WidgetToRender)
	{
		return nullptr;
	}

	if (_DrawSize.IsZero())
	{
		return nullptr;
	}

	FWidgetRenderer widgetRenderer = FWidgetRenderer(_UseGamma);
	UTextureRenderTarget2D* textureRender = widgetRenderer.CreateTargetFor(_DrawSize, _Filter, _UseGamma);
	TSharedRef<SWidget> ref = _WidgetToRender->TakeWidget();

	widgetRenderer.DrawWidget(textureRender, ref, _DrawSize, _DeltaTime);

	return textureRender;
}

void URDScreenshotManager::SaveRenderTargetToDisk(UTextureRenderTarget2D* _InRenderTarget, FString _Filename)
{
	FTextureRenderTargetResource* textureRenderResource = _InRenderTarget->GameThread_GetRenderTargetResource();

	FReadSurfaceDataFlags readPixelFlags(RCM_UNorm);
	readPixelFlags.SetLinearToGamma(true);

	TArray<FLinearColor> outBMP;
	textureRenderResource->ReadLinearColorPixels(outBMP, readPixelFlags);

	FIntRect sourceRect;
	FIntPoint destSize(_InRenderTarget->GetSurfaceWidth(), _InRenderTarget->GetSurfaceHeight());

	FString resultPath;
	FHighResScreenshotConfig& highResScreenshotConfig = GetHighResScreenshotConfig();

	TUniquePtr<FImageWriteTask> imageTask = MakeUnique<FImageWriteTask>();

	imageTask->PixelData = MakeUnique<TImagePixelData<FLinearColor>>(destSize, (TArray<FLinearColor, FDefaultAllocator64>) MoveTemp(outBMP));

	highResScreenshotConfig.PopulateImageTaskParams(*imageTask);
	imageTask->Filename = _Filename;

	imageTask->Format = EImageFormat::JPEG;

	TFuture<bool> completionFuture = highResScreenshotConfig.ImageWriteQueue->Enqueue(MoveTemp(imageTask));

	if (completionFuture.IsValid())
	{
		completionFuture.Wait();
	}
}
