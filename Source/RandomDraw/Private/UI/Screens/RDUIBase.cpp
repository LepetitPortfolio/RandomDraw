// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Screens/RDUIBase.h"

FColor URDUIBase::ReverseColorRGB(FColor _Color)
{
	_Color.R = ReverseColor(_Color.R);
	_Color.G = ReverseColor(_Color.G);
	_Color.B = ReverseColor(_Color.B);

	return _Color;
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


