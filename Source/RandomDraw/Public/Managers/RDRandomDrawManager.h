// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Structs/RDPerson.h"
#include "Structs/RDRandomDraw.h"
#include "RDRandomDrawManager.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDRandomDrawManager : public UObject
{
	GENERATED_BODY()

public:
	/**
	* launches the process of random drawing
	* @param _Persons - list of persons in random drawing
	* @param _IgnoreGroup - indicates if the random draw ignore or not the group system
	* @return indicates if the random draw is a sucess or not 
	*/
	bool LaunchDrawing(TArray<FRDPerson*> _Persons, bool _IgnoreGroup);

	/**
	* Set a new reference of a random draw to view
	* @param _RandomDraw - random draw reference
	*/
	inline void SetRandomDrawView(FRDRandomDraw* _RandomDraw) { m_RandomDrawView = _RandomDraw; }
	/**
	* return reference of the random draw to view
	* @return reference of random draw to view
	*/
	inline FRDRandomDraw* GetRandomDrawView() { return m_RandomDrawView; }
	/**
	* return reference of the random draw
	* @return reference of random draw
	*/
	inline FRDRandomDraw* GetRandomDraw() { return &m_RandomDraw; }

	/**
	* Saves the new random draw
	* @param _DrawingName - random draw name
	*/
	void SaveDrawing(FString _DrawingName);

	/**
	* Fix Random Draw Values in case the original data are deleted
	* @param _RandomDraw - Random Draw of the values to be fixed 
	*/
	void FixRandomDrawValues(FRDRandomDraw* _RandomDraw);

	/**
	* delete a Random Draw besed on data in input
	* @param _RandomDraw - Random Draw data to deleted
	*/
	void DeleteRandomDraw(FRDRandomDraw* _RandomDraw);

protected:

	/* New random draw create */
	FRDRandomDraw m_RandomDraw = FRDRandomDraw();

	/* Random  draw to view */
	FRDRandomDraw* m_RandomDrawView = nullptr;

	/* Max random draw try */
	int m_MaxDrawingTry = 100;



};
