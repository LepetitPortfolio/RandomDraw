// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "Save/RDSaveData.h"

#include "RDSaveManager.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDSaveManager : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
	bool SaveData();

	UFUNCTION()
	bool LoadData();

protected:
	
	UPROPERTY()
	FString m_SaveDataName = "SaveData";

	UPROPERTY()
	URDSaveData* m_SaveData = nullptr;

};
