// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Structs/RDRandomDraw.h"
#include "UObject/NoExportTypes.h"
#include "RDShareManager.generated.h"

/**
 * Manager dedicated to native Android sharing (text & image)
 */
UCLASS()
class RANDOMDRAW_API URDShareManager : public UObject
{
    GENERATED_BODY()

public:

    /**
    * Open the native share sheet with a text message
    * @param _Text - Text to share
    * @param _ChooserTitle - Title of the share chooser
    */
    UFUNCTION(BlueprintCallable, Category = "RDShareManager")
    void ShareText(const FString& _Text, const FString& _ChooserTitle = TEXT("Partager le tirage"));

    /**
    * Open the native share sheet with an image file
    * @param _ImagePath - Absolute path of the PNG file to share
    * @param _Text - Optional caption
    */
    UFUNCTION(BlueprintCallable, Category = "RDShareManager")
    void ShareImage(const FString& _ImagePath, const FString& _Text = TEXT(""));

    /**
    * Make a file visible in the device gallery (MediaScanner)
    * @param _ImagePath - Absolute path of the PNG file
    */
    UFUNCTION(BlueprintCallable, Category = "RDShareManager")
    bool ScanFileInGallery(const FString& _ImagePath);

    UFUNCTION(BlueprintCallable, Category = "RDShareManager")
    void ClearRandomDrawIDInWait() { m_RandomDrawInWait = FRDRandomDraw(); }

    UFUNCTION(BlueprintCallable, Category = "RDShareManager")
    void SetRandomDrawIDInWait(FRDRandomDraw _RandomDraw) { m_RandomDrawInWait = _RandomDraw; }

    UFUNCTION(BlueprintCallable, Category = "RDShareManager")
    FRDRandomDraw GetRandomDrawInWait() { return m_RandomDrawInWait; }

protected :

    FRDRandomDraw m_RandomDrawInWait = FRDRandomDraw();

#if PLATFORM_ANDROID

    /**
    * Open the native Android share sheet with a text message
    * @param _Text - Text to share
    * @param _ChooserTitle - Title of the share chooser
    */
    static void AndroidShareText(const FString& _Text, const FString& _ChooserTitle = TEXT("Partager le tirage"));

    /**
    * Open the native Android share sheet with an image file
    * @param _ImagePath - Absolute path of the PNG file to share
    * @param _Text - Optional caption
    */
    static void AndroidShareImage(const FString& _ImagePath, const FString& _Text = TEXT(""));

    /**
    * Make a file visible in the device gallery (MediaScanner)
    * @param _ImagePath - Absolute path of the PNG file
    */
    static bool AndroidScanFileInGallery(const FString& _ImagePath);

#endif

};