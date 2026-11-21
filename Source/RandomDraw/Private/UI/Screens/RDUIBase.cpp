// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Screens/RDUIBase.h"
#include "FunctionLibrary/RDFunctionLibrary.h"
#include "Managers/RDThemeManager.h"

FColor URDUIBase::ReverseColorRGB(FColor _Color)
{
	_Color.R = ReverseColor(_Color.R);
	_Color.G = ReverseColor(_Color.G);
	_Color.B = ReverseColor(_Color.B);

	return _Color;
}

FText URDUIBase::GetThemeName()
{
	return FText::FromName(URDFunctionLibrary::GetThemeManager()->GetCurrentThemeName());
}

FLinearColor URDUIBase::GetBackgroundColor()
{
	return FLinearColor(URDFunctionLibrary::GetThemeManager()->GetCurrentBackgroundColor());
}

FLinearColor URDUIBase::GetSurfaceColor()
{
	return FLinearColor(URDFunctionLibrary::GetThemeManager()->GetCurrentSurfaceColor());
}

FLinearColor URDUIBase::GetPrimaryColor()
{
	return FLinearColor(URDFunctionLibrary::GetThemeManager()->GetCurrentPrimaryColor());
}

FLinearColor URDUIBase::GetTextPrimaryColor()
{
	return FLinearColor(URDFunctionLibrary::GetThemeManager()->GetCurrentTextPrimaryColor());
}

FLinearColor URDUIBase::GetTextSecondaryColor()
{
	return FLinearColor(URDFunctionLibrary::GetThemeManager()->GetCurrentTextSecondaryColor());
}

FLinearColor URDUIBase::GetDangerColor()
{
	return FLinearColor(URDFunctionLibrary::GetThemeManager()->GetCurrentDangerColor());
}

FLinearColor URDUIBase::GetColorGroup(FString _GroupID)
{
	return FLinearColor(URDFunctionLibrary::GetThemeManager()->GetColorOfGroup(_GroupID));
}

void URDUIBase::ChangeColorStyle(UButton* _Button, FLinearColor _Color)
{
	_Button->BackgroundColor = _Color;
}

int URDUIBase::ReverseColor(int _ColorValue)
{
	_ColorValue = FMath::Clamp(_ColorValue, 0, 255);
	int halfColorValue = 255 / 2;
	int newValue = 0;

	if (_ColorValue <= halfColorValue)
	{
		newValue = halfColorValue + halfColorValue - _ColorValue + 1;
	}
	else
	{
		newValue = halfColorValue - (_ColorValue - halfColorValue) + 1;
	}
	return newValue;
}


