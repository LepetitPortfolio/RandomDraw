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
	bool LaunchDrawing(TArray<FRDPerson*> _Persons, bool _IgnoreGroup);

	inline void SetRandomDrawView(FRDRandomDraw* _RandomDraw) { m_RandomDrawView = _RandomDraw; }
	inline FRDRandomDraw* GetRandomDrawView() { return m_RandomDrawView; }
	inline FRDRandomDraw* GetRandomDraw() { return &m_RandomDraw; }

	void SaveDrawing(FString _DrawingName);

	void FixRandomDrawValues(FRDRandomDraw* _RandomDraw);

	void DeleteRandomDraw(FRDRandomDraw* _RandomDraw);

protected:

	FRDRandomDraw m_RandomDraw = FRDRandomDraw();

	FRDRandomDraw* m_RandomDrawView = nullptr;

	int m_MaxDrawingTry = 100;



};
