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
	* return the referenc of appdata
	* @return referenc of appdata
	*/
	inline FRDAppData* GetAppData() { return &m_AppData; }

	/**
	* set a new reference of appdata
	* @param _NewAppData - new appdata reference
	*/
	void SetAppData(FRDAppData* _NewAppData);

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

	UPROPERTY(BlueprintReadOnly, Category = RDGameMode)
		FRDAppData m_AppData = FRDAppData();

	UPROPERTY(BlueprintReadOnly, Category = RDGameMode)
		class URDSaveManager* m_SaveManager = nullptr;
	UPROPERTY(BlueprintReadOnly, Category = RDGameMode)
		class URDPersonManager* m_PersonManager = nullptr;
	UPROPERTY(BlueprintReadOnly, Category = RDGameMode)
		class URDGroupManager* m_GroupManager = nullptr;
	UPROPERTY(BlueprintReadOnly, Category = RDGameMode)
		class URDRandomDrawManager* m_RandomDrawManager = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = RDGameMode)
		TArray<FRDStateHistory> m_MenuStateHistory;

	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
};
