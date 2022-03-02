// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Popups/RDPopupBase.h"

void URDPopupBase::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void URDPopupBase::NativeConstruct()
{
	Super::NativeConstruct();
}

void URDPopupBase::ClosePopup()
{
	RemoveFromParent();
}
