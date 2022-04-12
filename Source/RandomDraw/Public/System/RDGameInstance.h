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

	/**
	* UE4 Function : Initilizes the Game instance 
	*/
	virtual void Init() override;

	/**
	* UE4 Function : stop all dependence of the Game instance
	*/
	virtual void Shutdown() override;
};
