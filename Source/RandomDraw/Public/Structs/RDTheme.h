#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/DataTable.h"
#include "RDTheme.generated.h"


USTRUCT(BlueprintType)
struct FRDTheme : public FTableRowBase
{
    GENERATED_BODY()

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName ThemeName = FName("Default");

    UPROPERTY(EditAnywhere, BlueprintReadWrite) 
    FLinearColor Background = FLinearColor(0.10f, 0.10f, 0.14f);
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite) 
    FLinearColor Surface = FLinearColor(0.16f, 0.16f, 0.22f);
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite) 
    FLinearColor Primary = FLinearColor(0.55f, 0.30f, 0.95f);
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite) 
    FLinearColor Secondary = FLinearColor(0.20f, 0.85f, 0.90f); 
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite) 
    FLinearColor TextPrimary = FLinearColor(1.0f, 1.0f, 1.0f);
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite) 
    FLinearColor TextSecondary = FLinearColor(0.65f, 0.65f, 0.70f);
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite) 
    FLinearColor Danger = FLinearColor(0.95f, 0.25f, 0.30f);
};