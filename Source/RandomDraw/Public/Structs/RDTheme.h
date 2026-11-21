#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RDColorRange.h"
#include "Engine/DataTable.h"
#include "RDTheme.generated.h"


USTRUCT(BlueprintType)
struct FRDTheme : public FTableRowBase
{
    GENERATED_BODY()

public:

    // ─────────────────────────────────────────────────────────────
    // Nom du thème (clé d'identification dans la DataTable)
    // Ex : "Default", "Light", "Neon"...
    // Sert à afficher le thème dans le sélecteur et à le retrouver via GetRow.
    // ─────────────────────────────────────────────────────────────
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName ThemeName = FName("Urbain");

    // ─────────────────────────────────────────────────────────────
    // Couleur de FOND de l'application (arrière-plan des écrans)
    // Valeur par défaut : gris très foncé bleuté (0.10, 0.10, 0.14)
    // ─────────────────────────────────────────────────────────────
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FLinearColor Background = FLinearColor(0.005182f, 0.006995f, 0.009134f);

    // ─────────────────────────────────────────────────────────────
    // Couleur des SURFACES surélevées : cartes, panneaux, popups,
    // barres de navigation... (légèrement plus clair que le fond)
    // Valeur par défaut : gris foncé (0.16, 0.16, 0.22)
    // ─────────────────────────────────────────────────────────────
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FLinearColor Surface = FLinearColor(0.011612f, 0.016807f, 0.024158f);

    // ─────────────────────────────────────────────────────────────
    // Couleur PRIMAIRE : actions principales (bouton "Tirer au sort",
    // éléments sélectionnés, titres importants)
    // Valeur par défaut : violet (0.55, 0.30, 0.95)
    // ─────────────────────────────────────────────────────────────
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FLinearColor Primary = FLinearColor(0.015996f, 0.651406f, 0.854993f);

    // ─────────────────────────────────────────────────────────────
    // Couleur du TEXTE PRINCIPAL : titres, contenu important
    // Doit contraster fortement avec Background/Surface
    // Valeur par défaut : blanc pur (1.0, 1.0, 1.0)
    // ─────────────────────────────────────────────────────────────
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FLinearColor TextPrimary = FLinearColor(0.871367f, 0.947307f, 1.0f);

    // ─────────────────────────────────────────────────────────────
    // Couleur du TEXTE SECONDAIRE : descriptions, métadonnées,
    // textes désactivés (plus discret que TextPrimary)
    // Valeur par défaut : gris clair (0.65, 0.65, 0.70)
    // ─────────────────────────────────────────────────────────────
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FLinearColor TextSecondary = FLinearColor(0.296138f, 0.366253f, 0.47932f);

    // ─────────────────────────────────────────────────────────────
    // Couleur DANGER : actions destructrices (supprimer une personne,
    // un groupe, un tirage), messages d'erreur
    // Valeur par défaut : rouge (0.95, 0.25, 0.30)
    // ─────────────────────────────────────────────────────────────
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FLinearColor Danger = FLinearColor(0.938686f, 0.165132f, 0.165132f);

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FRDColorRange ColorRange = FRDColorRange();
};