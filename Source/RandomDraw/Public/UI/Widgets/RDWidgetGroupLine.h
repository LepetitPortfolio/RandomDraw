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

	/**
	* Initializes the values
	* @param _Group - reference of group to displayed
	* @param _ViewerGroup - reference of Widget parent
	*/
	void InitValue(FRDGroup* _Group, class URDUIViewerGroup* _ViewerGroup);

protected:

	/* Reference of group to displayed */
	FRDGroup* m_Group = nullptr;

	/* Reference of Widget parent */
	UPROPERTY()
		class URDUIViewerGroup* m_ViewerGroup = nullptr;

	/* Libelle of group */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDWidgetGroupLine)
		FString m_Libelle = "";

	/* color of group */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RDWidgetGroupLine)
		FLinearColor m_Color = FLinearColor::Black;

	/**
	* Lauchs a process to delet a group data
	*/
	UFUNCTION(BlueprintCallable, Category = RDWidgetGroupLine)
		void DeleteGroup();

	/**
	* Applies the action of delete a group data after the confirmation
	*/
	UFUNCTION()
	void ApplyDeleteGroup();

	/**
	* Lauchs a process to modify a group data
	*/
	UFUNCTION(BlueprintCallable, Category = RDWidgetGroupLine)
		void ModifyGroup();

};
