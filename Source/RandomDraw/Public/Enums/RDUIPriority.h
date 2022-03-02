#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"

/**
* Priority of Widget is rendered
*/
UENUM(BlueprintType)
enum class ERDUIPriority : uint8
{
	PriorityNone = 0,
	Priority0 = 1,
	Priority1 = 25,
	Priority2 = 50,
	Priority3 = 75,
	Priority4 = 100,
	Priority5 = 125,
	Priority6 = 150,
	Priority7 = 175,
	Priority8 = 200,
	Priority9 = 225,
	Priority10 = 250,
	PriorityMax = 255
};