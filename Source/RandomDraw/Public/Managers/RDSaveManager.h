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
	/**
	* Lauches the save data process
	* @return if the save is a sucess or not 
	*/
	UFUNCTION()
	bool SaveData();

	/**
	* Lauches the load data process
	* @return if the load is a sucess or not
	*/
	UFUNCTION()
	bool LoadData();

protected:
	
	/* Name of the save */
	UPROPERTY()
	FString m_SaveDataName = "SaveData";

	/* Data to save */
	UPROPERTY()
	URDSaveData* m_SaveData = nullptr;

};
