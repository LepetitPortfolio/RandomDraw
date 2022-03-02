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

	UFUNCTION()
		void ChangeMenuState(ERDMenuStat _MenuStat, ERDUIPriority _UIPriority);

	UFUNCTION()
		void  ReturnToLastManuState();

	UFUNCTION()
		void DisplayPopupUI(ERDPopupUI _PopupUI, ERDUIPriority _UIPriority);

	UFUNCTION()
		URDUIBase* GetPopupUI();

	UFUNCTION()
		inline class URDSaveManager* GetSaveManager() { return m_SaveManager; }

	UFUNCTION()
		inline class URDPersonManager* GetPersonManager() { return m_PersonManager; }

	UFUNCTION()
		inline class URDGroupManager* GetGroupManager() { return m_GroupManager; }

	UFUNCTION()
		inline class URDRandomDrawManager* GetRandomDrawManager() { return m_RandomDrawManager; }

	//UFUNCTION()
		inline FRDAppData* GetAppData() { return &m_AppData; }

	//UFUNCTION()
		void SetAppData(FRDAppData* _NewAppData);

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = RDGameMode)
		ERDMenuStat m_CurrentMenuStat = ERDMenuStat::None;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = RDGameMode)
		ERDUIPriority m_CurrentUIPriority = ERDUIPriority::Priority0;

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
