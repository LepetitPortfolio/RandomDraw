// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UI/Screens/RDUIBase.h"
#include "RDWidgetBase.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDWidgetBase : public URDUIBase
{
	GENERATED_BODY()
	

public :

	/**
	* Initializes the UserWidget values
	*/
	void InitValue();

protected:

	/**
	* Return a black or white color based on the color in inpute
	* the color returned is the most visible in the color in input 
	* @param _ColorBase - Reference color to choose the output color
	* @return White or black color
	*/
	UFUNCTION(BlueprintCallable, Category = UIBase)
		FLinearColor WhiteOrBlackColor(FLinearColor _ColorBase);

private:

};
