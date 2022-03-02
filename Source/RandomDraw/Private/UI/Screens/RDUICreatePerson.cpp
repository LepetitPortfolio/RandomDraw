// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Screens/RDUICreatePerson.h"
#include "FunctionLibrary/RDFunctionLibrary.h"
#include "Managers/RDPersonManager.h"

void URDUICreatePerson::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void URDUICreatePerson::NativeConstruct()
{
	m_Person = FRDPerson();

	Super::NativeConstruct();
}

void URDUICreatePerson::CreatePerson()
{
	URDFunctionLibrary::GetPersonManager()->CreatePerson(&m_Person, m_FirstGroupSelector->GetGroup(), m_SecondGroupSelector->GetGroup());
	URDFunctionLibrary::LaunchSaveData();
}
