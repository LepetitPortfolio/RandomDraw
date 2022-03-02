
#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"

/**
* Priority of Widget is rendered
*/
UENUM(BlueprintType)
enum class ERDPopupUI : uint8
{
	None,
	ErrorPopup,
	SaveDrawingPopup,
	ValidateActionPopup,
	Max		UMETA(Hidden)
};