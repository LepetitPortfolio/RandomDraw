// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Screens/RDUICreateGroup.h"
#include "FunctionLibrary/RDFunctionLibrary.h"
#include "Managers/RDGroupManager.h"

void URDUICreateGroup::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void URDUICreateGroup::NativeConstruct()
{
	Super::NativeConstruct();

	m_Group = FRDGroup();
}

void URDUICreateGroup::CreateGroup()
{
	m_Group.m_Color = m_ColorSelector->GetColor();
	URDFunctionLibrary::GetGroupManager()->CreateGroup(&m_Group);
	URDFunctionLibrary::LaunchSaveData();
}
