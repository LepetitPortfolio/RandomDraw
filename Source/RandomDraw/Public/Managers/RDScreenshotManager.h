// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Blueprint/UserWidget.h"
#include "Engine/TextureRenderTarget2D.h"
#include "RDScreenshotManager.generated.h"

/**
 *
 */
UCLASS()
class RANDOMDRAW_API URDScreenshotManager : public UObject
{
	GENERATED_BODY()


public:

	/**
	*
	*/
	UTextureRenderTarget2D* RenderWidgetToTexture(bool _UseGamma, TextureFilter _Filter, UUserWidget* _WidgetToRender, FVector2D _DrawSize, float _DeltaTime);

	/**
	*
	*/
	void SaveRenderTargetToDisk(UTextureRenderTarget2D* _InRenderTarget, FString _Filename);

private:

};
