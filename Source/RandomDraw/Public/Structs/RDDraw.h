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

	/* First person ID Drawed */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDDraw)
		FString m_FirstPersonID = "";
	
	/* First person name Drawed */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDDraw)
		FString m_FirstPersonName = "";

	/* First person color Drawed */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDDraw)
		FLinearColor m_FirstPersonColor = FLinearColor();

	/* Second person ID Drawed */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDDraw)
		FString m_SecondPersonID = "";

	/* Second person Name Drawed */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDDraw)
		FString m_SecondPersonName = "";

	/* Second person Color Drawed */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDDraw)
		FLinearColor m_SecondPersonColor = FLinearColor();

	/**
	* Constructor
	*/
	FRDDraw() {}
	/**
	* Constructor by copy
	*/
	FRDDraw(const FRDDraw* _Draw)
	{
		m_FirstPersonID = _Draw->m_FirstPersonID;
		m_SecondPersonID = _Draw->m_SecondPersonID;
	}

	FORCEINLINE void operator=(FRDDraw _Other)
	{
		m_FirstPersonID = _Other.m_FirstPersonID;
		m_SecondPersonID = _Other.m_SecondPersonID;
	}
};