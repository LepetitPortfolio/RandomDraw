#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Enums/RDMenuStat.h"
#include "Enums/RDUIPriority.h"
#include "RDStateHistory.generated.h"


/**
* 
*/
USTRUCT(BlueprintType)
struct RANDOMDRAW_API FRDStateHistory
{
	GENERATED_BODY()

public:

	UPROPERTY()
		ERDMenuStat m_MenuStat;

	UPROPERTY()
		ERDUIPriority m_UIPriority;

	FRDStateHistory(){}
};