// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/RDWidgetBase.h"

void URDWidgetBase::InitValue()
{

}

FColor URDWidgetBase::ReverseColorRGB(FColor _Color)
{

	_Color.R = ReverseColor(_Color.R);
	_Color.G = ReverseColor(_Color.G);
	_Color.B = ReverseColor(_Color.B);

	return _Color;
}

FLinearColor URDWidgetBase::WhiteOrBlackColor(FLinearColor _ColorBase)
{
	float mediumColor = (_ColorBase.R + _ColorBase.G + _ColorBase.B) / 3;

	if (mediumColor >= 0.5f)
	{
		return FLinearColor::Black;
	}

	return FLinearColor::White;
}

int URDWidgetBase::ReverseColor(int _ColorValue)
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
