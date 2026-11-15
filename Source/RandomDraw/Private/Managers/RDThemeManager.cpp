// Fill out your copyright notice in the Description page of Project Settings.


#include "Managers/RDThemeManager.h"
#include "FunctionLibrary/RDFunctionLibrary.h"
#include "System/RandomDrawGameMode.h"
#include "Structs/RDAppData.h"

void URDThemeManager::SetCurrentTheme(const FRDTheme _NewTheme)
{
	FRDAppData* appdata = URDFunctionLibrary::GetAppData();
	appdata->m_CurrentTheme = _NewTheme;
}

FRDTheme URDThemeManager::GetCurrentTheme() const
{
	FRDAppData* appdata = URDFunctionLibrary::GetAppData();
	return appdata->m_CurrentTheme;
}

FName URDThemeManager::GetCurrentThemeName() const
{
	return GetCurrentTheme().ThemeName;
}

FLinearColor URDThemeManager::GetCurrentBackgroundColor() const
{
	return GetCurrentTheme().Background;
}

FLinearColor URDThemeManager::GetCurrentSurfaceColor() const
{
	return GetCurrentTheme().Surface;
}

FLinearColor URDThemeManager::GetCurrentPrimaryColor() const
{
	return GetCurrentTheme().Primary;
}

FLinearColor URDThemeManager::GetCurrentSecondaryColor() const
{
	return GetCurrentTheme().Secondary;
}

FLinearColor URDThemeManager::GetCurrentTextPrimaryColor() const
{
	return GetCurrentTheme().TextPrimary;
}

FLinearColor URDThemeManager::GetCurrentTextSecondaryColor() const
{
	return GetCurrentTheme().TextSecondary;
}

FLinearColor URDThemeManager::GetCurrentDangerColor() const
{
	return GetCurrentTheme().Danger;
}