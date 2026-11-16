// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Screens/RDUISettingScreen.h"
#include "FunctionLibrary/RDFunctionLibrary.h"
#include "System/RandomDrawGameMode.h"
#include "Managers/RDThemeManager.h"

void URDUISettingScreen::NativeOnInitialized()
{
	Super::NativeOnInitialized();	
}

void URDUISettingScreen::NativeConstruct()
{
	Super::NativeConstruct();

	m_LastCurrentTheme = URDFunctionLibrary::GetThemeManager()->GetCurrentTheme();

}

void URDUISettingScreen::ApplySettingUp()
{
	URDFunctionLibrary::LaunchSaveData();

	URDFunctionLibrary::ReturnToLastManuState();
}

void URDUISettingScreen::CanncelSettingUp()
{
	URDFunctionLibrary::GetThemeManager()->SetCurrentTheme(m_LastCurrentTheme);

	URDFunctionLibrary::ReturnToLastManuState();
}
