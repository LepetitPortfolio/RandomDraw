// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Structs/RDAppData.h"
#include "RDSaveData.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDSaveData : public USaveGame
{
	GENERATED_BODY()
	
public:
	/**
	* save data constructor
	*/
	URDSaveData();

	/**
	* set the application data to save
	* @param _NewData - application data to save
	*/
	void SetData(FRDAppData* _NewData);
	/**
	* Getter ofthe application data to save
	* @return the reference of application data to save
	*/
	inline FRDAppData* GetData() { return &m_Data; }

protected:
	/* the application data to save */
	UPROPERTY()
	FRDAppData m_Data;
};
