// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Styling/SlateColor.h"
#include "RDUIBase.generated.h"

/**
 * 
 */
UCLASS(abstract)
class RANDOMDRAW_API URDUIBase : public UUserWidget
{
	GENERATED_BODY()

protected:
	/**
	* return the reverse color base on the color in input
	* @param _Color - Color to reverte
	* @return Color reverted
	*/
	UFUNCTION(BlueprintCallable, Category = UIBase)
		FColor ReverseColorRGB(FColor _Color);

	UFUNCTION(BlueprintGetter, Category = UIBase)
		FText GetThemeName();

	UFUNCTION(BlueprintGetter, Category = UIBase)
	FLinearColor GetBackgroundColor();
	
	UFUNCTION(BlueprintGetter, Category = UIBase)
	FLinearColor GetSurfaceColor();

	UFUNCTION(BlueprintGetter, Category = UIBase)
	FLinearColor GetPrimaryColor();

	UFUNCTION(BlueprintGetter, Category = UIBase)
	FLinearColor GetTextPrimaryColor();

	UFUNCTION(BlueprintGetter, Category = UIBase)
	FLinearColor GetTextSecondaryColor();

	UFUNCTION(BlueprintGetter, Category = UIBase)
	FLinearColor GetDangerColor();

	UFUNCTION(BlueprintGetter, Category = UIBase)
	FLinearColor GetColorGroup(FString _GroupID);

private:
	/**
	* return the reverse color value base on the color value in input
	* @param _ColorValue - Value to reverte
	* @return Value reverted 
	*/
	UFUNCTION()
		int ReverseColor(int _ColorValue);
	
};
