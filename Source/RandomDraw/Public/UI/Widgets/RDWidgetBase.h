// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RDWidgetBase.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDWidgetBase : public UUserWidget
{
	GENERATED_BODY()
	

public :

	/**
	* Initializes the UserWidget values
	*/
	void InitValue();

protected:

	/**
	* Converts the color in input to her invert color
	* @param _Color - the color to convert
	* @return the invert color
	*/
	UFUNCTION(BlueprintCallable, Category = UIBase)
		FColor ReverseColorRGB(FColor _Color);

	/**
	* Return a black or white color based on the color in inpute
	* the color returned is the most visible in the color in input 
	* @param _ColorBase - Reference color to choose the output color
	* @return White or black color
	*/
	UFUNCTION(BlueprintCallable, Category = UIBase)
		FLinearColor WhiteOrBlackColor(FLinearColor _ColorBase);

private:
	/**
	* Returns the inverse value of an element of a color in input
	* @pram _ColorValue - Value of element of a color between 0 and 255
	* @return the inverse value between 0 and 255
	*/
	UFUNCTION()
		int ReverseColor(int _ColorValue);

};
