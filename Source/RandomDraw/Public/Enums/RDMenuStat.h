#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"

/**
* Priority of Widget is rendered
*/
UENUM(BlueprintType)
enum class ERDMenuStat : uint8
{
	None,
	MainMenu,
	TicketsMenu,
	RandomDrawsViewer,
	RandomDrawViewer,
	NewRandomDrawViewer,
	GroupsViewer,
	PersonsViewer,
	CreateRandomDraw,
	CreatePerson,
	CreateGroup,
	ModifyPerson,
	ModifyGroup,
	Max		UMETA(Hidden)
};