// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintPlatformLibrary.h"
#include "RDGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDGameInstance : public UPlatformGameInstance
{
	GENERATED_BODY()
	
protected:

	virtual void Init() override;

	virtual void Shutdown() override;
};
