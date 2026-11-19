# RandomDraw

**RandomDraw** est une application mobile développée avec **Unreal Engine 4.27**, permettant de créer des groupes de personnes et d'effectuer des **tirages au sort aléatoires** entre leurs membres.

---

## 🎯 Présentation

RandomDraw repose sur un principe simple et ludique : organiser des participants en **groupes**, puis tirer au sort aléatoirement l'un d'entre eux.

Exemples d'utilisation :
- 🎁 déterminer à qui offrir un cadeau ;
- 🎄 organiser un tirage de Noël (Secret Santa) ;
- 🎲 sélectionner un gagnant dans un groupe ;
- 👥 désigner une personne au hasard pour une tâche.

---

## ✨ Fonctionnalités implémentées

### 👥 Gestion des personnes
- Création et modification de fiches personnes
- Visualisation de la liste des personnes

### 🗂️ Gestion des groupes
- Création et modification de groupes
- Visualisation des groupes

### 🎲 Tirages au sort
- Création de tirages avec sélection aléatoire d'une personne dans un groupe
- Historique des tirages effectués

### 🎫 Menu Tickets
- Écran dédié

### 📤 Partage Android
- Partage du résultat via le système natif Android (share sheet)
- Capture d'écran intégrée du résultat du tirage

### 💾 Sauvegarde
- Persistance des données (personnes, groupes, tirages, historique)

---

## 🛠️ Architecture technique

| Élément | Détail |
|---|---|
| Moteur | Unreal Engine 4.27 |
| Plateformes cibles | Android, iOS |
| Langages | C++ (module Runtime) + Blueprints/UMG |
| Rendu | Profil matériel **Mobile**, MSAA x2, orientation **Portrait** |

### Structure C++ (`Source/RandomDraw/`)
- **Managers/** : `RDGroupManager`, `RDPersonManager`, `RDRandomDrawManager`, `RDSaveManager`, `RDScreenshotManager`, `RDShareManager`, `RDThemeManager`
- **UI/** : classes C++ des Screens (16 écrans : MainMenu, CreatePerson, ModifyPerson, CreateGroup, ModifyGroup, viewers, sélecteurs, paramètres, Tickets…) et bases réutilisables (`RDUIBase`, `RDUIViewerBase`)
- **Structs/** : 8 structures de données (`RDPerson`, `RDGroup`, `RDRandomDraw`, `RDDraw`, `RDAppData`, `RDStateHistory`, `RDTheme`, `RDUIInstance`)
- **Save/** : `RDSaveData`
- **Enums/**, **FunctionLibrary/**, **System/** (`RDGameMode`, `RDGameInstance`)

### Blueprints / UMG (`Content/`)
- **System/** : `BP_RDGameMode`, HUD
- **UI/Screens/** : écrans du jeu
- **UI/Widgets/** : 13 widgets réutilisables (lignes personnes/groupes/tirages, sélecteur de couleur…)
- **UI/Popup/** : popups de confirmation
- **Level/** : map `Main` | **Textures/**, **Icones/**, **DataTables/**

---

## 📁 Structure du dépôt

RandomDraw/
├── Config/            → DefaultEngine.ini, DefaultGame.ini…
├── Content/           → Assets UE (Blueprints, UI, textures)
├── Plugins/
│   └── VisualStudioTools/   → outils VS (Win64)
├── Source/
│   └── RandomDraw/    → code C++ du jeu
├── RandomDraw.uproject
└── README.md


---

## 🚀 Installation & lancement

### Prérequis
- Unreal Engine **4.27**
- Visual Studio (Windows) avec le workload C++ Unreal
- Android NDK / SDK pour le packaging mobile

### Étapes
1. Cloner le dépôt : `git clone https://github.com/LepetitPortfolio/RandomDraw.git`
2. Ouvrir `RandomDraw.uproject` avec UE 4.27
3. Compiler, puis lancer depuis l'éditeur ou packager pour Android/iOS

### Configuration Android
- `MinSDKVersion=26`, `TargetSDKVersion=28`, build ArmV7 + Arm64, Gradle activé, APK universel avec splits ABI/langue/densité

---

## 🔮 Améliorations envisagées

- Envoi du résultat par e-mail / SMS
- Génération d'un lien partageable
- Partage étendu (iOS via `UIActivityViewController`, réseaux sociaux)
- Nouveau thème visuel (ex. « Néon Nuit » dark mode)
- Montée du `TargetSDKVersion` (28 → 34) pour la conformité Play Store

---

## 👤 Auteur

**Simon Lepetit** — Développeur jeux vidéo & gameplay
Portfolio : https://www.lepetitportfolio.fr/ | GitHub : https://github.com/LepetitPortfolio
