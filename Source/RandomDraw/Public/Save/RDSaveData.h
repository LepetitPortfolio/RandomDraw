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

	URDSaveData();

	void SetData(FRDAppData* _NewData);
	inline FRDAppData* GetData() { return &m_Data; }

protected:
	UPROPERTY()
	FRDAppData m_Data;
};
