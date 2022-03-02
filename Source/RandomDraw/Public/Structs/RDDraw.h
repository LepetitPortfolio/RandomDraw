#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Structs\RDPerson.h"
#include "RDDraw.generated.h"


/**
*
*/
USTRUCT(BlueprintType)
struct RANDOMDRAW_API FRDDraw
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDDraw)
		FString m_FirstPersonID = "";
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDDraw)
		FString m_FirstPersonName = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDDraw)
		FLinearColor m_FirstPersonColor = FLinearColor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDDraw)
		FString m_SecondPersonID = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDDraw)
		FString m_SecondPersonName = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDDraw)
		FLinearColor m_SecondPersonColor = FLinearColor();

	FRDDraw() {}
	FRDDraw(const FRDDraw* _Draw)
	{
		m_FirstPersonID = _Draw->m_FirstPersonID;
		m_SecondPersonID = _Draw->m_SecondPersonID;
	}

	FORCEINLINE void operator=(FRDDraw& _Other)
	{
		m_FirstPersonID = _Other.m_FirstPersonID;
		m_SecondPersonID = _Other.m_SecondPersonID;
	}

	FORCEINLINE void operator=(FRDDraw _Other)
	{
		m_FirstPersonID = _Other.m_FirstPersonID;
		m_SecondPersonID = _Other.m_SecondPersonID;
	}
};