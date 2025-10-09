// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Widgets/RDWidgetBase.h"
#include "Components/SizeBox.h"
#include "Components/VerticalBox.h"
#include "Structs/RDRandomDraw.h"
#include "RDDrawScreenWidget.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMDRAW_API URDDrawScreenWidget : public URDWidgetBase
{
	GENERATED_BODY()
	
public:

	/**
	* Generate the random draw list based on the randoom draw in input
	* @param _RandomDraw - Data of the random draw list to generate
	*/
	void GenerateRandomDrawList(FRDRandomDraw* _RandomDraw);

	/**
	* Return the size of draw screen
	* @return Size of draw screen
	*/
	FVector2D GetDrawScreenSize();

protected:
	/* Widget template to instantiate */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Draw Screen Widget")
		TSubclassOf<class URDWidgetDrawLine> m_WidgetTemplate;

	/* Default Size of draw screen */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Draw Screen Widget")
	FVector2D m_DefaultWidgetRootSize = FVector2D();

	/* Reference of Size box Widget in root */
	UPROPERTY(BlueprintReadOnly, Category = "RDUIViewerBase", meta = (BindWidget))
	USizeBox* m_WidgetChildRoot = nullptr;

	/* Reference of vertical box Widget where other widgets are stored */
	UPROPERTY(BlueprintReadOnly, Category = "RDUIViewerBase", meta = (BindWidget))
	UVerticalBox* m_WidgetList = nullptr;

	/* Random Draw Name */
	UPROPERTY(BlueprintReadOnly, Category = "Draw Screen Widget")
		FString m_RandomDrawLibelle = "";


	/**
	* UE4 Function : Called when the object is construct
	*/
	virtual void NativeOnInitialized() override;
	/**
	* UE4 Function : Called just before to display the UMG
	*/
	virtual void NativeConstruct() override;

	/**
	* Clear the Draw Screen and reset the size
	*/
	void ClearDrawScreen();

	/**
	* Increase the Draw Screen size based on the size in input
	* @param _AddSize - Size to add at the Draw Screen
	*/
	void AddDrawScreenSize(FVector2D _AddSize);
};
