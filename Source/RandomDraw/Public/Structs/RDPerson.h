#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RDGroup.h"
#include "RDPerson.generated.h"


/**
* 
*/
USTRUCT(BlueprintType)
struct RANDOMDRAW_API FRDPerson
{
	GENERATED_BODY()

public:
	
	/* Person ID */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDPerson)
		FString m_ID = "";

	/* Person Name */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDPerson)
		FString m_Name = "";
	
	/* First group ID */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDPerson)
		FString m_FirstGroupID = "";

	/* Second group ID */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDPerson)
		FString m_SecondGroupID = "";

	/**
	* Constructor
	*/
	FRDPerson(){}
	/**
	* Constructor by copy
	*/
	FRDPerson(const FRDPerson* _Person)
	{
		m_ID = _Person->m_ID;
		m_Name = _Person->m_Name;
		m_FirstGroupID = _Person->m_FirstGroupID;
		m_SecondGroupID = _Person->m_SecondGroupID;
	}

	/**
	* Indicates if the person is in same group in input
	* @param _GroupID - group comparated
	* @return indicates or not if the person is contained in the group
	*/
	bool GetIsInSameGroup(FString _GroupID)
	{
		if (_GroupID.IsEmpty())
		{
			return false;
		}

		if ((m_FirstGroupID == _GroupID) || (m_SecondGroupID == _GroupID))
		{
			return true;
		}

		return false;
	}

	/**
	* Indicates if the person is in same person in input
	* @param _Person - group comparated
	* @return indicates or not if the person is contained in the person group
	*/
	bool GetIsInSameGroup(FRDPerson* _Person)
	{
		return (GetIsInSameGroup(_Person->m_FirstGroupID) || GetIsInSameGroup(_Person->m_SecondGroupID));
	}

	FORCEINLINE void operator=(FRDPerson _Other)
	{
		m_ID = _Other.m_ID;
		m_Name = _Other.m_Name;
		m_FirstGroupID = _Other.m_FirstGroupID;
		m_SecondGroupID = _Other.m_SecondGroupID;
	}
};