// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Widgets/RDWidgetBase.h"
#include "Structs/RDPerson.h"
#include "RDWidgetPersonLine.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDWidgetPersonLine : public URDWidgetBase
{
	GENERATED_BODY()
	
public: 
	void InitValue(FRDPerson* _Person, class URDUIViewerPerson* _ViewerPerson);

	inline FRDPerson* GetPerson() { return m_Person; }

protected:

	FRDPerson* m_Person = nullptr;

	UPROPERTY()
	class URDUIViewerPerson* m_ViewerPerson = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDWidgetPersonLine)
	FString m_PersonName = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDWidgetPersonLine)
	FLinearColor m_Color = FLinearColor::Black;

	UFUNCTION(BlueprintCallable, Category = RDWidgetPersonLine)
		void DeleteThePerson();

	UFUNCTION()
	void ApplyDeleteGroup();


	UFUNCTION(BlueprintCallable, Category = RDWidgetPersonLine)
		void ModifyThePerson();

};
