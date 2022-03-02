// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Popups/RDPopupConfirmeAction.h"

void URDPopupConfirmeAction::InitPopupValue(FString _Message, FValidateAction const& _ActionsToDo)
{
	m_PopupMessage = _Message;
	m_ActionEvent = _ActionsToDo;
}

void URDPopupConfirmeAction::ValideAction()
{
	m_ActionEvent.Broadcast();
	RemoveFromViewport();
}

void URDPopupConfirmeAction::CancelAction()
{
	RemoveFromViewport();
}
