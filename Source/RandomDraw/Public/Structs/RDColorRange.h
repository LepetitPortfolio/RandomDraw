#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RDColorRange.generated.h"


USTRUCT(BlueprintType)
struct FRDColorRange
{
    GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FLinearColor FirstColor = FLinearColor(0.135633f, 0.806952f, 0.947307f);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FLinearColor SecondColor = FLinearColor(0.002428f, 0.283149f, 0.445201f);


    FLinearColor GetColorRange() const
    {
		return SecondColor - FirstColor;
	}

};