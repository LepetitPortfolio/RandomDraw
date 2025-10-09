// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Blueprint/UserWidget.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Structs/RDRandomDraw.h"
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
	* Cook a picture based on ramdom draw data in inpute
	* @param _RandomDraw - Random Draw data to make a picture
	* @return Return a value true or false if the process was sucess or not
	*/
	bool TakeScreenshotOfRandomDraw(FRDRandomDraw _RandomDraw);

private:
	/**
	* Convert a user widget in png picture file
	* @param _Widget - widget to convert in picture
	* @param _FilePath - file path to save the picture
	* @param _Size - Size of pictire
	* @return Return a value true or false if the save was sucess or not
	*/
	bool SaveWidgetAsPNG(UUserWidget* _Widget, const FString& _FilePath, FVector2D _Size);

	/**
	* Save a pixels tab in picture  
	* @param _Pixels - Pixels tab
	* @param _Width - Width Size
	* @param _Height - Height Size
	* @param _FilePath - file path to save the picture
	* @param _AsPNG - Idicate if the pictire in out is a png file or not
	* @return Return a value true or false if the save was sucess or not
	*/
	bool SaveCustomPixelsAsImage(const TArray<FColor>& _Pixels, int32 _Width, int32 _Height, const FString& _FilePath, bool _AsPNG = true);

};
