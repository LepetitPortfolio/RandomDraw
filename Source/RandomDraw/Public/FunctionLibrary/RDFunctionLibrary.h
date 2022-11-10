// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Enums/RDMenuStat.h"
#include "Enums/RDPopupUI.h"
#include "Enums/RDUIPriority.h"
#include "Structs/RDAppData.h"
#include "RDFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	/** 
	* Getter of the project game mode
	* @return the reference of the game mode
	*/
	UFUNCTION(BlueprintPure, Category = RDFunctionLibrary)
	static class ARandomDrawGameMode* GetRDGameMode();

	/** 
	* Reset the static game mode value 
	*/
	UFUNCTION()
	static void ResetGameMode();

	UFUNCTION()
	static class ARDHUD* GetRDHUD();

	/** 
	* Getter of the Person Manager
	* @return the reference of Person Manager
	*/
	UFUNCTION(BlueprintPure, Category = RDFunctionLibrary)
	static class URDPersonManager* GetPersonManager();

	/** 
	* Getter of the Group Manager 
	* @return the reference of Group Manager
	*/
	UFUNCTION(BlueprintPure, Category = RDFunctionLibrary)
	static class URDGroupManager* GetGroupManager();

	/**
	* Getter of the Random draw Manager 
	* @return the reference of Random draw Manager
	*/
	UFUNCTION(BlueprintPure, Category = RDFunctionLibrary)
	static class URDRandomDrawManager* GetRandomDrawManager();

	/**
	* Getter of the Screenshot Manager
	* @return the reference of Screenshot Manager
	*/
	UFUNCTION(BlueprintPure, Category = RDFunctionLibrary)
	static class URDScreenshotManager* GetScreenshotManager();

	/** 
	* Launch the process for save the data 
	*/
	UFUNCTION(BlueprintCallable, Category = RDFunctionLibrary)
	static void LaunchSaveData();

	/**
	* Launch the process for Load the data 
	*/
	UFUNCTION(BlueprintCallable, Category = RDFunctionLibrary)
	static void LauchSaveLoad();

	/**
	* Change the game state of the game
	* @param _MenuStat - New state of the game
	* @param _UIPriority - Priority of the UI displayed
	*/
	UFUNCTION(BlueprintCallable, Category = RDFunctionLibrary)
	static void ChangeMenuState(ERDMenuStat _MenuStat, ERDUIPriority _UIPriority = ERDUIPriority::Priority1);

	/**
	* lauch the process to display the last Menu displayed
	*/
	UFUNCTION(BlueprintCallable, Category = RDFunctionLibrary)
	static void ReturnToLastManuState();

	/** 
	* Display an Popup
	* @param _PopupUI - Popup type
	* @param _UIPriority - Priority of the UI displayed
	*/
	UFUNCTION(BlueprintCallable, Category = RDFunctionLibrary)
	static void DisplayPopupUI(ERDPopupUI _PopupUI, ERDUIPriority _UIPriority = ERDUIPriority::Priority5);

	/**
	* Return the current poppup
	* @return the reference of current popup
	*/
	UFUNCTION(BlueprintCallable, Category = RDFunctionLibrary)
	static URDUIBase* GetPopupUI();

	/**
	* Getter of the App data
	* @return the reference of the App data
	*/
	static FRDAppData* GetAppData();

	/**
	* Set a new reference of appdata value
	* @param new appdata reference
	*/
	static void SetAppData(FRDAppData* _AppData);

	/**
	* Return a person reference based on pason ID
	* @param _PersonID - person ID of person searched
	* @return person reference of person searched
	*/
	static FRDPerson* GetPerson(FString _PersonID);

	/**
	* Return a group reference based on group ID
	* @param _GroupID - person ID of group searched
	* @return group reference of group searched
	*/
	static FRDGroup* GetGroup(FString _GroupID);

private:

	/* reference of the Game Mode */
	static class ARandomDrawGameMode* m_GameMode;
};
