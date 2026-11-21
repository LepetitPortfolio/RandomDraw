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

## ✨ Fonctionnalités

### 👥 Gestion des personnes
- Création / modification de fiches personnes, liste des personnes

### 🗂️ Gestion des groupes
- Création / modification de groupes, liste des groupes

### 🎲 Tirages au sort
- Tirage aléatoire d'une personne dans un groupe, historique des tirages

### 🎨 Système de thèmes
- Thèmes définis dans une **DataTable** (`FRDTheme`) : `Background`, `Surface`, `Primary`, `TextPrimary`, `TextSecondary`, `Danger` + plage de dégradé (`FRDColorRange`)
- Géré par `RDThemeManager`

### 🎫 Menu Tickets
- Écran dédié

### 📤 Partage Android
- Partage du résultat via le share sheet natif (APL `RDShare_APL.xml` : `FileProvider` AndroidX + JNI)
- Capture d'écran intégrée du résultat

### 💾 Sauvegarde
- Persistance des données via `RDSaveManager` / `RDSaveData`

---

## 🛠️ Architecture technique

| Élément | Détail |
|---|---|
| Moteur | Unreal Engine 4.27 |
| Plateformes cibles | Android, iOS |
| Langages | C++ (module Runtime) + Blueprints/UMG |
| Rendu | Profil Mobile, MSAA x2, orientation Portrait |

### Modules C++ (`Source/RandomDraw/`)
- **Managers/** : `RDPersonManager`, `RDGroupManager`, `RDRandomDrawManager`, `RDSaveManager`, `RDScreenshotManager`, `RDShareManager`, `RDThemeManager`
- **Structs/** : `RDPerson`, `RDGroup`, `RDRandomDraw`, `RDDraw`, `RDAppData`, `RDStateHistory`, `RDTheme`, `RDColorRange`, `RDUIInstance`
- **UI/** : 15 classes d'écrans (`RDUIBase`, `RDUIViewerBase`, MainMenu, Create/Modify Person/Group, viewers, sélecteurs, Settings, Tickets…), popups et widgets
- **Build/Android/** : `RDShare_APL.xml` (partage natif Android)

---

## 📁 Structure du dépôt

RandomDraw/
├── Config/            → DefaultEngine.ini, DefaultGame.ini…
├── Content/           → Assets UE (Blueprints, UI, DataTables, textures)
├── Plugins/VisualStudioTools/
├── Source/RandomDraw/ → code C++ (Managers, Structs, UI, Build/Android)
├── RandomDraw.uproject
└── README.md

---

## 🚀 Installation & lancement

### Prérequis
- Unreal Engine **4.27**
- Visual Studio (Windows) avec workload C++ Unreal
- Android NDK / SDK pour le packaging mobile

### Étapes
1. `git clone https://github.com/LepetitPortfolio/RandomDraw.git`
2. Ouvrir `RandomDraw.uproject` avec UE 4.27
3. Compiler puis lancer depuis l'éditeur ou packager pour Android/iOS

---

## 👤 Auteur

**Simon Lepetit** — Portfolio : https://www.lepetitportfolio.fr/ | GitHub : https://github.com/LepetitPortfolio