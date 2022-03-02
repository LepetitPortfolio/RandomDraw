// Fill out your copyright notice in the Description page of Project Settings.


#include "Managers/RDSaveManager.h"
#include "Kismet/GameplayStatics.h"
#include "FunctionLibrary/RDFunctionLibrary.h"
#include "System/RandomDrawGameMode.h"

bool URDSaveManager::SaveData()
{

	if (!m_SaveData)
	{
		m_SaveData = Cast<URDSaveData>(UGameplayStatics::CreateSaveGameObject(URDSaveData::StaticClass()));
	}


	FRDAppData* appData = URDFunctionLibrary::GetAppData();
	m_SaveData->SetData(appData);

	if (UGameplayStatics::SaveGameToSlot(m_SaveData, m_SaveDataName, 0))
	{
		return true;
	}

	
	return false;
}


bool URDSaveManager::LoadData()
{

	if (UGameplayStatics::DoesSaveGameExist(m_SaveDataName, 0))
	{
		m_SaveData = Cast<URDSaveData>(UGameplayStatics::LoadGameFromSlot(m_SaveDataName, 0));

		FRDAppData* localData = m_SaveData->GetData();

		if ((localData != nullptr))
		{
			URDFunctionLibrary::SetAppData(localData);

			return true;
		}

	}

	return false;
}
