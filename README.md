# QObjectListModel

## Description

### English

**QObjectListModel** is a practical implementation of a modified version of the `qobject_list_model.h` file originally written by Vadim USOLTSEV. This project aims to provide a QObject-based list model, facilitating the management and display of objects in Qt applications.

### Français

**QObjectListModel** est une application pratique d'une version modifiée du fichier `qobject_list_model.h` écrit par Vadim USOLTSEV. Ce projet vise à fournir un modèle de liste basé sur QObject, facilitant la gestion et l'affichage des objets dans les applications Qt.

## Features / Fonctionnalités

### English

- **QObject-based List Model**: Allows the creation of list models using QObject.
- **Dynamic Properties**: Supports declared dynamic properties, offering increased flexibility.
- **Change Propagation**: Changes to object properties are automatically reflected in the model, ensuring real-time updates in associated views.
- **QML Compatibility**: Can be used in QML ListView, making it easy to integrate with modern user interfaces.
- **Simplified Object Management**: Simple methods for adding, inserting, and removing objects, with optional ownership handling.

### Français

- **Modèle de liste basé sur QObject** : Permet de créer des modèles de liste en utilisant des objets QObject.
- **Propriétés dynamiques** : Supporte les propriétés dynamiques déclarées, permettant une flexibilité accrue.
- **Propagation des changements** : Les modifications des propriétés des objets sont automatiquement reflétées dans le modèle, assurant une mise à jour en temps réel des vues associées.
- **Compatibilité QML** : Peut être utilisé dans les ListView de QML, facilitant l'intégration avec les interfaces utilisateur modernes.
- **Gestion simplifiée des objets** : Méthodes simples pour ajouter, insérer et supprimer des objets, avec possibilité de prise en charge de la propriété des objets.


## Installation

To use this project, simply clone the repository and include the necessary files in your Qt project.

Pour utiliser ce projet, il suffit de cloner le dépôt et d'inclure les fichiers nécessaires dans votre projet Qt.

```bash

git clone https://github.com/Doga-dev/QObjectListModel.git

```
## Usage / Utilisation

Here is an example of creating and using a QObject list model:

Voici un exemple de création et d’utilisation d’un modèle de liste QObject :

```cpp

auto model = new QObjectListModel(this);
model->addObject(new MyObject(...));
myView->setModel(model);

```

To use the model in QML:

Pour utiliser le modèle dans QML :

```qml

ListView {
    model: listModel // model from C++, for example as a context property
    delegate: ItemDelegate {
        width: parent.width
        text: name
    }
}

```

## Author / Auteur

This project was developed by Francis CHAPET, based on the original work of Vadim USOLTSEV.

Ce projet a été développé par Francis CHAPET, basé sur le travail original de Vadim USOLTSEV.

