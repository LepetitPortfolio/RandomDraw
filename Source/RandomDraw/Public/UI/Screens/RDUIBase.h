// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RDUIBase.generated.h"

/**
 * 
 */
UCLASS(abstract)
class RANDOMDRAW_API URDUIBase : public UUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, Category = UIBase)
		FColor ReverseColorRGB(FColor _Color);

private:
	UFUNCTION()
		int ReverseColor(int _ColorValue);
	
};
