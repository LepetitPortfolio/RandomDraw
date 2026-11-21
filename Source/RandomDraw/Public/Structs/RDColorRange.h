#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RDColorRange.generated.h"


USTRUCT(BlueprintType)
struct FRDColorRange
{
    GENERATED_BODY()

public:

    // ─────────────────────────────────────────────────────────────
    // Couleur de FOND de l'application (arrière-plan des écrans)
    // Valeur par défaut : gris très foncé bleuté (0.10, 0.10, 0.14)
    // ─────────────────────────────────────────────────────────────
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FLinearColor FirstColor = FLinearColor(0.0f, 0.0f, 0.0f);

    // ─────────────────────────────────────────────────────────────
    // Couleur des SURFACES surélevées : cartes, panneaux, popups,
    // barres de navigation... (légèrement plus clair que le fond)
    // Valeur par défaut : gris foncé (0.16, 0.16, 0.22)
    // ─────────────────────────────────────────────────────────────
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FLinearColor SecondColor = FLinearColor(1.0f, 1.0f, 1.0f);


    FLinearColor GetColorRange() const
    {
		return SecondColor - FirstColor;
	}

};