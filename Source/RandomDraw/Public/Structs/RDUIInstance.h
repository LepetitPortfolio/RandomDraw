#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UI/Screens/RDUIBase.h"
#include "RDUIInstance.generated.h"


/**
* 
*/
USTRUCT(BlueprintType)
struct RANDOMDRAW_API FRDUIInstance
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, Category = RDUIInstance)
	TSubclassOf<URDUIBase> m_UITemplate;

	UPROPERTY()
	URDUIBase* m_Instance = nullptr;

	FRDUIInstance(){}
};