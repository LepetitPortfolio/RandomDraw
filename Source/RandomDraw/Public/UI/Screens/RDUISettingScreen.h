// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Screens/RDUIBase.h"
#include "Structs/RDTheme.h"
#include "RDUISettingScreen.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDUISettingScreen : public URDUIBase
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDUISettingScreen)
	FRDTheme m_LastCurrentTheme;


	/**
	* UE4 Function : Called when the object is construct
	*/
	virtual void NativeOnInitialized() override;
	/**
	* UE4 Function : Called just before to display the UMG
	*/
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable, Category = RDUISettingScreen)
	void ApplySettingUp();

	UFUNCTION(BlueprintCallable, Category = RDUISettingScreen)
	void CanncelSettingUp();
	
};
