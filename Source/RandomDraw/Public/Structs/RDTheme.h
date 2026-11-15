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
    FLinearColor Background = FLinearColor(0.04f, 0.05f, 0.10f); // fond app
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite) 
    FLinearColor Surface = FLinearColor(0.08f, 0.10f, 0.18f); // cartes
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite) 
    FLinearColor Primary = FLinearColor(0.55f, 0.36f, 0.96f); // violet accent
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite) 
    FLinearColor Secondary = FLinearColor(0.13f, 0.83f, 0.93f); // cyan accent
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite) 
    FLinearColor TextPrimary = FLinearColor(0.95f, 0.96f, 0.98f);
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite) 
    FLinearColor TextSecondary = FLinearColor(0.58f, 0.64f, 0.72f);
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite) 
    FLinearColor Danger = FLinearColor(0.96f, 0.36f, 0.42f);
};