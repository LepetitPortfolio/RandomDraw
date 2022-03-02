#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/Color.h"
#include "RDGroup.generated.h"


/**
* 
*/
USTRUCT(BlueprintType)
struct RANDOMDRAW_API FRDGroup
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDGroup)
		FString m_ID = "";
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDGroup)
		FString m_Libelle = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDGroup)
		FLinearColor m_Color = FLinearColor::Black;

	FRDGroup(){}
	FRDGroup(const FRDGroup* _Group)
	{
		m_ID = _Group->m_ID;
		m_Libelle = _Group->m_Libelle;
		m_Color = _Group->m_Color;
	}

	FORCEINLINE void operator=(FRDGroup _Other)
	{
		m_ID = _Other.m_ID;
		m_Libelle = _Other.m_Libelle;
		m_Color = _Other.m_Color;
	}
};