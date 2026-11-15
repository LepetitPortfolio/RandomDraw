#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RDGroup.h"
#include "RDPerson.h"
#include "RDRandomDraw.h"
#include "RDTheme.h"
#include "RDAppData.generated.h"


/**
* All Data managed in this application
*/
USTRUCT(BlueprintType)
struct RANDOMDRAW_API FRDAppData
{
	GENERATED_BODY()

public:

	/* List of Group */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDAppData)
	TMap<FString, FRDGroup> m_Groups = TMap<FString, FRDGroup>();

	/* List of Person */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDAppData)
	TMap<FString, FRDPerson> m_Persons = TMap<FString, FRDPerson>();

	/* List of Random Draw */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDAppData)
	TMap<FString, FRDRandomDraw> m_RandomDraws = TMap<FString, FRDRandomDraw>();

	/* Current Theme */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDAppData)
	FRDTheme m_CurrentTheme;

	/**
	* Constructor
	*/
	FRDAppData() {}
	/**
	* Constructor by copy
	*/
	FRDAppData(const FRDAppData* _AppData)
	{
		m_Groups = _AppData->m_Groups;
		m_Persons = _AppData->m_Persons;
		m_RandomDraws = _AppData->m_RandomDraws;
		m_CurrentTheme = _AppData->m_CurrentTheme;
	}
	
	FORCEINLINE void operator=(FRDAppData _Other)
	{
		m_Groups = _Other.m_Groups;
		m_Persons = _Other.m_Persons;
		m_RandomDraws = _Other.m_RandomDraws;
		m_CurrentTheme = _Other.m_CurrentTheme;
	}
};