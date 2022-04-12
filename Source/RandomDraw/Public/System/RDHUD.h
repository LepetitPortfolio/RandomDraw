// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Enums/RDMenuStat.h"
#include "Enums/RDPopupUI.h"
#include "Enums/RDUIPriority.h"
#include "Structs/RDUIInstance.h"
#include "RDHUD.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API ARDHUD : public AHUD
{
	GENERATED_BODY()
	
public:

	/** 
	* Display an oter UI on the screen 
	* @param _PopupUI - Menu UI Type
	* @param _UIPriority - UI Priority
	* @return a boolean value if the instantiation was successful or not
	*/
	UFUNCTION()
	bool DisplayAnOtherUI(ERDMenuStat _MenuStat, ERDUIPriority _UIPriority);
	
	/**
	* Display an Popup on the screen 
	* @param _PopupUI - Popup UI Type
	* @param _UIPriority - UI Priority
	*/
	UFUNCTION()
	void DisplayPopupUI(ERDPopupUI _PopupUI, ERDUIPriority _UIPriority);

	/**
	* getter for the reference of the current popup display
	* @return the reference of the current popup display
	*/
	inline URDUIBase* GetPopupInstance() { return m_PopupInstance->m_Instance; }

protected:

	/* List of UI for the application */
	UPROPERTY(EditDefaultsOnly, Category = RDHUD)
	TMap<ERDMenuStat, FRDUIInstance> m_GameUI;

	/* List of Popup for the application */
	UPROPERTY(EditDefaultsOnly, Category = RDHUD)
	TMap<ERDPopupUI, FRDUIInstance> m_PopupUI;

	/* Reference of the current UI displayed */
	FRDUIInstance* m_UIInstance = nullptr;

	/* Reference of the current Popup displayed */
	FRDUIInstance* m_PopupInstance = nullptr;

};
