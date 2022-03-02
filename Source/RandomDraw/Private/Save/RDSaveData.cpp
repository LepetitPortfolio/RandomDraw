// Fill out your copyright notice in the Description page of Project Settings.


#include "Save/RDSaveData.h"

URDSaveData::URDSaveData()
{
    m_Data = FRDAppData();
}

void URDSaveData::SetData(FRDAppData* _NewData)
{
    m_Data = FRDAppData(_NewData);
}
