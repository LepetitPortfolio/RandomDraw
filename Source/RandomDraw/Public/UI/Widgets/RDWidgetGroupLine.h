// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Widgets/RDWidgetBase.h"
#include "Structs\RDGroup.h"
#include "RDWidgetGroupLine.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDWidgetGroupLine : public URDWidgetBase
{
	GENERATED_BODY()

public:

	void InitValue(FRDGroup* _Group, class URDUIViewerGroup* _ViewerGroup);

protected:

	FRDGroup* m_Group = nullptr;

	UPROPERTY()
		class URDUIViewerGroup* m_ViewerGroup = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDWidgetGroupLine)
		FString m_Libelle = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDWidgetGroupLine)
		FLinearColor m_Color = FLinearColor::Black;

	UFUNCTION(BlueprintCallable, Category = RDWidgetGroupLine)
		void DeleteGroup();

	UFUNCTION()
	void ApplyDeleteGroup();

	UFUNCTION(BlueprintCallable, Category = RDWidgetGroupLine)
		void ModifyGroup();

};
