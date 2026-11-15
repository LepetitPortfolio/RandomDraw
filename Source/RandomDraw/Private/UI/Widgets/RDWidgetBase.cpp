// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widgets/RDWidgetBase.h"

void URDWidgetBase::InitValue()
{

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

