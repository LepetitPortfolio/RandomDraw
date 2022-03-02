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

	void InitValue();

protected:
	UFUNCTION(BlueprintCallable, Category = UIBase)
		FColor ReverseColorRGB(FColor _Color);

	UFUNCTION(BlueprintCallable, Category = UIBase)
		FLinearColor WhiteOrBlackColor(FLinearColor _ColorBase);

private:
	UFUNCTION()
		int ReverseColor(int _ColorValue);

};
