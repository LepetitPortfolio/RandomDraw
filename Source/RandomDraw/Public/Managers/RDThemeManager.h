// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Structs/RDTheme.h"
#include "RDThemeManager.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDThemeManager : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "RandomDraw|Theme")
	void SetCurrentTheme(const FRDTheme _NewTheme);
	
	UFUNCTION(BlueprintCallable, Category = "RandomDraw|Theme")
	FRDTheme GetCurrentTheme() const;

	UFUNCTION(BlueprintCallable, Category = "RandomDraw|Theme")
	FName GetCurrentThemeName() const;

	UFUNCTION(BlueprintCallable, Category = "RandomDraw|Theme")
	FLinearColor GetCurrentBackgroundColor() const;

	UFUNCTION(BlueprintCallable, Category = "RandomDraw|Theme")
	FLinearColor GetCurrentSurfaceColor() const;

	UFUNCTION(BlueprintCallable, Category = "RandomDraw|Theme")
	FLinearColor GetCurrentPrimaryColor() const;

	UFUNCTION(BlueprintCallable, Category = "RandomDraw|Theme")
	FLinearColor GetCurrentSecondaryColor() const;

	UFUNCTION(BlueprintCallable, Category = "RandomDraw|Theme")
	FLinearColor GetCurrentTextPrimaryColor() const;

	UFUNCTION(BlueprintCallable, Category = "RandomDraw|Theme")
	FLinearColor GetCurrentTextSecondaryColor() const;

	UFUNCTION(BlueprintCallable, Category = "RandomDraw|Theme")
	FLinearColor GetCurrentDangerColor() const;

protected:	

};
