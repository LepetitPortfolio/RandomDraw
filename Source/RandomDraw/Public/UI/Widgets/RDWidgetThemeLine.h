// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Widgets/RDWidgetBase.h"
#include "Structs/RDTheme.h"
#include "RDWidgetThemeLine.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDWidgetThemeLine : public URDWidgetBase
{
	GENERATED_BODY()

public:

	/**
	* Initializes the values
	* @param _Theme - reference of theme to displayed
	*/
	void InitValue(FRDTheme* _Theme, class URDWidgetThemesSelector* _ThemesSelector);

	inline FRDTheme* GetTheme() { return m_Theme; }

protected:

	/* Reference of theme to displayed */
	FRDTheme* m_Theme = nullptr;

	/* Reference of Widget parent */
	UPROPERTY(BlueprintReadOnly, Category = RDWidgetThemeLine)
	class URDWidgetThemesSelector* m_ThemesSelector;

	UFUNCTION(BlueprintGetter, Category = RDWidgetThemeLine)
	FSlateColor GetNewThemeBackgroundColor();

	UFUNCTION(BlueprintGetter, Category = RDWidgetThemeLine)
	FSlateColor GetNewThemeTextPrimaryColor();

	UFUNCTION(BlueprintGetter, Category = RDWidgetThemeLine)
	FText GetNewThemeName();

	/* Launch the process of select of Theme */
	UFUNCTION(BlueprintCallable, Category = RDWidgetThemeLine)
	void Select();
	
};
