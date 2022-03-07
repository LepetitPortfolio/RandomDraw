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

	/* UI Template */
	UPROPERTY(EditDefaultsOnly, Category = RDUIInstance)
	TSubclassOf<URDUIBase> m_UITemplate;

	/* UI Instance */
	UPROPERTY()
	URDUIBase* m_Instance = nullptr;

	/**
	* Contructor
	*/
	FRDUIInstance(){}
};