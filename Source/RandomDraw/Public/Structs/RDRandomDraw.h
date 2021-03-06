#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Structs\RDDraw.h"
#include "RDRandomDraw.generated.h"


/**
* 
*/
USTRUCT(BlueprintType)
struct RANDOMDRAW_API FRDRandomDraw
{
	GENERATED_BODY()

public:
	/* Random draw ID */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDRandomDraw)
		FString m_ID = "";

	/* Random draw Libelle */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDRandomDraw)
	FString m_Libelle = "";

	/* List of draw of random draw */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDRandomDraw)
	TArray<FRDDraw> m_Draws = TArray<FRDDraw>();

	/**
	* Constructor
	*/
	FRDRandomDraw(){}
	/**
	* Constructor by copy
	*/
	FRDRandomDraw(const FRDRandomDraw* _RandomDraw)
	{
		m_ID = _RandomDraw->m_ID;
		m_Libelle = _RandomDraw->m_Libelle;
		m_Draws = _RandomDraw->m_Draws;
	}

	FORCEINLINE void operator=(FRDRandomDraw _Other)
	{
		m_ID = _Other.m_ID;
		m_Libelle = _Other.m_Libelle;
		m_Draws = _Other.m_Draws;
	}
};