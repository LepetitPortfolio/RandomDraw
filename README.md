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
- Création et modification de fiches personnes (UI_CreatePerson, UI_ModifyPerson, UI_PersonnViewer)
- Visualisation de la liste des personnes

### 🗂️ Gestion des groupes
- Création de groupes (UI_CreateGroup)
- Modification de groupes (UI_ModifyGroup)
- Visualisation des groupes (UI_GroupsViewer)

### 🎲 Tirages au sort
- Création de tirages (UI_NewRandomDrawViewer)
- Sélection aléatoire d'une personne dans un groupe (UI_RandomDrawPersonSelector)
- Historique des tirages (UI_RandomDrawsViewer, UI_RandomDrawViewer)

### 🎫 Menu Tickets
- Écran dédié (UI_TicketsMenu)

### 📤 Partage Android (plugin RDAndroidShare)
- Partage du résultat via le système natif Android
- Capture d'écran intégrée (RDScreenshotManager, RDShareManager)

### 💾 Sauvegarde
- Système de sauvegarde via RDSaveManager / RDSaveData

---

## 🛠️ Architecture technique

| Élément | Détail |
|---|---|
| Moteur | Unreal Engine 4.27 |
| Plateformes cibles | Android, iOS |
| Langages | C++ + Blueprints (UMG) |

### Structure C++ (Source/RandomDraw)
- Managers/ : RDGroupManager, RDPersonManager, RDRandomDrawManager, RDSaveManager, RDScreenshotManager, RDShareManager
- UI/ : classes C++ des Screens, Widgets et Popups
- Save/ : RDSaveData (structure de sauvegarde)
- Structs/, Enums/, FunctionLibrary/, System/

### Blueprints / UMG (Content/)
- System/ : BP_RDGameMode, BP_RDHUD
- UI/Screens/ : 13 écrans (MainMenu, CreateGroup, RandomDrawViewer, etc.)
- UI/Widgets/ : 13 widgets réutilisables (GroupLine, PersonLine, DrawLine, ColorSelector…)
- UI/Popup/ : popups de confirmation
- Level/, Textures/, Icones/

### Plugin personnalisé
- RDAndroidShare (Plugins/RDAndroidShare) : plugin maison pour le partage natif Android (UPL + intégration Java)

---

## 📁 Structure du dépôt

RandomDraw/
├── Config/                     → DefaultEngine.ini, DefaultGame.ini, etc.
├── Content/                    → Assets UE (Blueprints, UI, textures)
├── Plugins/
│   ├── RDAndroidShare/         → Plugin perso (partage Android)
│   └── VisualStudioTools/      → Outils VS
├── Source/
│   └── RandomDraw/             → Code C++ du jeu
├── RandomDraw.uproject
└── README.md

---

## 🚀 Installation & lancement

### Prérequis
- Unreal Engine 4.27
- Visual Studio (Windows) avec workload C++ Unreal
- Android NDK / SDK pour le packaging mobile

### Étapes
1. Cloner le dépôt : git clone https://github.com/LepetitPortfolio/RandomDraw.git
2. Ouvrir RandomDraw.uproject avec UE 4.27
3. Compiler, puis lancer depuis l'éditeur ou packager pour Android/iOS

---

## 🔮 Améliorations envisagées

- Envoi du résultat par e-mail / SMS
- Génération d'un lien partageable
- Partage étendu (iOS, réseaux sociaux)
- Nouveau thème visuel (ex. « Néon Nuit » dark mode)

---

## 👤 Auteur

**Simon Lepetit** — Développeur jeux vidéo & gameplay
Portfolio : https://www.lepetitportfolio.fr/ | GitHub : https://github.com/LepetitPortfolio/RandomDraw
