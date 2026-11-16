// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Widgets/RDWidgetBase.h"
#include "Structs/RDTheme.h"
#include "Components/ScrollBox.h"
#include "Components/VerticalBox.h"
#include "RDWidgetThemesSelector.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDWidgetThemesSelector : public URDWidgetBase
{
	GENERATED_BODY()

public:

	/**
	* Initializes the UserWidget values
	*/
	UFUNCTION(BlueprintCallable, Category = UIThemesSelector)
	void InitValue();

	/**
	* Changes the current group selected based on reference of group
	* @param _Group - Reference of group
	*/
	void ChangeThemeSelected(FRDTheme* _Theme);

protected:

	/* Widget template to instantiate */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UIThemesSelector)
	TSubclassOf<class URDWidgetThemeLine> m_ThemeLineTemplate;

	TArray<FRDTheme*> m_ThemeList;

	/* Reference of scrollbox Widget */
	UPROPERTY(BlueprintReadOnly, Category = UIThemesSelector, meta = (BindWidget))
	UScrollBox* m_ScrollBox = nullptr;

	/* Reference of VerticalBox Widget */
	UPROPERTY(BlueprintReadOnly, Category = UIThemesSelector, meta = (BindWidget))
	UVerticalBox* m_WidgetList = nullptr;
	
};
