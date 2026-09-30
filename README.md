# RandomDraw

**RandomDraw** est une application mobile développée avec **Unreal Engine 4.27**, permettant d'effectuer simplement des **tirages au sort aléatoires entre plusieurs participants**.

L'objectif du projet est de proposer un outil simple et ludique pour déterminer aléatoirement une personne parmi un groupe.

Par exemple :
- 🎁 déterminer à qui offrir un cadeau ;
- 🎄 organiser un tirage de Noël ;
- 🎲 sélectionner aléatoirement un participant ;
- 👥 choisir une personne dans un groupe.

---

## 🎯 Présentation

RandomDraw est un projet personnel réalisé avec **Unreal Engine 4.27**.

L'application repose sur un principe volontairement simple : permettre à l'utilisateur de définir un ensemble de participants, puis de sélectionner aléatoirement l'un d'entre eux.

Le projet a également été pensé comme une base pouvant être enrichie par différents systèmes autour du tirage au sort.

---

## ✨ Fonctionnalités

### Tirage aléatoire

Le cœur de l'application permet de sélectionner aléatoirement un participant parmi une liste.

### Application mobile

Le projet est configuré pour cibler les plateformes mobiles :

- Android
- iOS

Les plateformes cibles sont directement définies dans le fichier `RandomDraw.uproject`.

---

## 🛠️ Technologies utilisées

| Technologie | Utilisation |
|---|---|
| **Unreal Engine 4.27** | Moteur principal du projet |
| **C++** | Programmation des systèmes du projet |
| **Blueprints** | Création et gestion de la logique et de l'interface |
| **Android** | Plateforme mobile cible |
| **iOS** | Plateforme mobile cible |

Le projet utilise **Unreal Engine 4.27**, comme indiqué dans sa configuration `.uproject`.

---

## 📁 Structure du projet

```text
RandomDraw/
│
├── Config/
│   └── Configuration du projet
│
├── Content/
│   └── Assets, Blueprints et ressources Unreal Engine
│
├── Plugins/
│   └── VisualStudioTools/
│
├── Source/
│   └── Code source C++
│
├── .gitattributes
├── .gitignore
├── RandomDraw.uproject
├── shadertoolsconfig.json
└── README.md
```

Cette organisation correspond à la structure actuellement présente dans le dépôt GitHub.

---

## 🚀 Installation

### Prérequis

Pour ouvrir et modifier le projet, il est nécessaire de disposer de :

- **Unreal Engine 4.27**
- **Visual Studio** avec les outils nécessaires au développement Unreal Engine
- Les outils de développement correspondant à la plateforme mobile ciblée

### Récupération du projet

Cloner le dépôt :

```bash
git clone https://github.com/LepetitPortfolio/RandomDraw.git
```

Puis ouvrir le projet :

```text
RandomDraw/RandomDraw.uproject
```

Le projet utilise le module `RandomDraw` et le plugin `VisualStudioTools`.

---

## ▶️ Lancement

Après avoir ouvert `RandomDraw.uproject` avec Unreal Engine 4.27 :

1. Générer les fichiers de projet si nécessaire.
2. Ouvrir le projet dans Unreal Engine.
3. Compiler le projet.
4. Lancer l'application depuis l'éditeur.
5. Tester le système de tirage.

Pour une utilisation sur mobile, sélectionner la plateforme cible souhaitée et effectuer le packaging du projet.

---

## 📱 Plateformes

Le projet est actuellement configuré pour les plateformes suivantes :

- **Android**
- **iOS**

Ces deux plateformes apparaissent comme plateformes cibles dans la configuration du projet Unreal.

---

## 🔮 Améliorations envisagées

Plusieurs évolutions peuvent être envisagées pour développer davantage le projet.

### Attribution de tâches

Ajouter un système permettant non seulement de sélectionner une personne, mais également de lui **attribuer automatiquement une tâche**.

Exemple :

```text
Alice → Préparer le repas
Bob   → Acheter les boissons
Claire → Installer la décoration
David → Nettoyer après la soirée
```

---

### Partage du résultat

Ajouter la possibilité de **partager le résultat d'un tirage** directement sur les réseaux sociaux.

Cela permettrait notamment de partager facilement le résultat avec les autres participants.

---

### Envoi aux participants

Ajouter différentes possibilités de communication :

- 📧 envoi du résultat par e-mail ;
- 📱 envoi par SMS ;
- 🔗 génération d'un lien partageable.

Ces pistes correspondent notamment aux évolutions envisagées dans la description originale du projet.

---

## 🎓 Objectifs du projet

Au-delà de son utilisation en tant qu'application, RandomDraw constitue également un **projet personnel de développement** permettant d'expérimenter différents aspects du développement avec Unreal Engine :

- développement C++ ;
- développement Blueprint ;
- conception d'une application mobile ;
- gestion d'une interface utilisateur ;
- génération de résultats aléatoires ;
- déploiement sur plateformes mobiles ;
- organisation d'un projet Unreal Engine.

---

## 📌 État du projet

> **Projet personnel — développement / expérimentation**

RandomDraw constitue une base fonctionnelle destinée à être progressivement améliorée.

Certaines fonctionnalités présentées dans la section **Améliorations envisagées** ne sont pas encore implémentées.

---

## 👤 Auteur

**Simon Lepetit**

Développeur informatique spécialisé dans le **développement de jeux vidéo et la programmation gameplay**.

Passionné par la création d'expériences interactives, j'utilise notamment **C++, C#, Unreal Engine et Unity** pour concevoir et expérimenter différents systèmes.

---

## 🔗 Liens

- **Dépôt GitHub :** https://github.com/LepetitPortfolio/RandomDraw
- **Portfolio :** https://www.lepetitportfolio.fr/

---

## 📄 Licence

Aucune licence open source spécifique n'est actuellement indiquée dans le dépôt.

Pour toute réutilisation ou redistribution du code, veuillez vous référer aux conditions définies par l'auteur du projet.
