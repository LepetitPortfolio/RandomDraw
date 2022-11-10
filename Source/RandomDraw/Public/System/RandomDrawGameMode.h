// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Enums/RDMenuStat.h"
#include "Structs/RDAppData.h"
#include "Structs/RDStateHistory.h"
#include "RandomDrawGameMode.generated.h"

/**
 *
 */
UCLASS()
class RANDOMDRAW_API ARandomDrawGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	/**
	* Changes the menu state with that changes the ui displayed
	* @param _MenuStat - new stat menu
	* @param _UIPriority - Ui priority
	*/
	UFUNCTION()
		void ChangeMenuState(ERDMenuStat _MenuStat, ERDUIPriority _UIPriority);

	/**
	* return an dre-displays the last menu stat
	*/
	UFUNCTION()
		void  ReturnToLastManuState();

	/**
	* Displays a new UI poppup
	* @param _PopupUI - new popup type displayed
	* @param _UIPriority - popup priority diplay
	*/
	UFUNCTION()
		void DisplayPopupUI(ERDPopupUI _PopupUI, ERDUIPriority _UIPriority);

	/**
	* return a reference of popup displayed
	* @retrurn a reference of popup
	*/
	UFUNCTION()
		URDUIBase* GetPopupUI();

	/**
	* return a reference of save manager
	* @return the reference of save manager
	*/
	UFUNCTION()
		inline class URDSaveManager* GetSaveManager() { return m_SaveManager; }

	/**
	* return a reference of person manager
	* @return the reference of person manager
	*/
	UFUNCTION()
		inline class URDPersonManager* GetPersonManager() { return m_PersonManager; }

	/**
	* return a reference of group manager
	* @return the reference of group manager
	*/
	UFUNCTION()
		inline class URDGroupManager* GetGroupManager() { return m_GroupManager; }

	/**
	* return a reference of random draw manager
	* @return the reference of random draw manager
	*/
	UFUNCTION()
		inline class URDRandomDrawManager* GetRandomDrawManager() { return m_RandomDrawManager; }

	/**
	* return a reference of screenshot manager
	* @return the reference of screenshot manager
	*/
	UFUNCTION()
		inline class URDScreenshotManager* GetScreenshotManager() { return m_ScreenshotManager; }

	/**
	* return the referenc of appdata
	* @return referenc of appdata
	*/
	inline FRDAppData* GetAppData() { return &m_AppData; }

	/**
	* set a new reference of appdata
	* @param _NewAppData - new appdata reference
	*/
	void SetAppData(FRDAppData* _NewAppData);

	inline class ARDHUD* GetRDHUD() { return m_RDHUD; }

protected:

	/* Type of current Menu state displayed */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = RDGameMode)
		ERDMenuStat m_CurrentMenuStat = ERDMenuStat::None;

	/* informztion of diplay priority of mune state dis^played */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = RDGameMode)
		ERDUIPriority m_CurrentUIPriority = ERDUIPriority::Priority0;

	/* reference of HUD object */
	UPROPERTY(BlueprintReadOnly, Category = RDGameMode)
		class ARDHUD* m_RDHUD = nullptr;

	/* Application Data */
	UPROPERTY(BlueprintReadOnly, Category = RDGameMode)
		FRDAppData m_AppData = FRDAppData();

	/* Manager to managing all save data */
	UPROPERTY(BlueprintReadOnly, Category = RDGameMode)
		class URDSaveManager* m_SaveManager = nullptr;
	/* Manager to managing all person data */
	UPROPERTY(BlueprintReadOnly, Category = RDGameMode)
		class URDPersonManager* m_PersonManager = nullptr;
	/* Manager to managing all group data */
	UPROPERTY(BlueprintReadOnly, Category = RDGameMode)
		class URDGroupManager* m_GroupManager = nullptr;
	/* Manager to managing all Random draw data */
	UPROPERTY(BlueprintReadOnly, Category = RDGameMode)
		class URDRandomDrawManager* m_RandomDrawManager = nullptr;

	/* Manager to managing the Screenshots */
	UPROPERTY(BlueprintReadOnly, Category = RDGameMode)
		class URDScreenshotManager* m_ScreenshotManager = nullptr;

	/* History of menu stat displayed */
	UPROPERTY(BlueprintReadOnly, Category = RDGameMode)
		TArray<FRDStateHistory> m_MenuStateHistory;

	/** 
	* UE4 Function, launched when the object is instantiate 
	*/
	virtual void BeginPlay() override;

	/** 
	* UE4 Function, launched just before the destruction of the object 
	* @param EndPlayReason - Reason of end play
	*/
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
