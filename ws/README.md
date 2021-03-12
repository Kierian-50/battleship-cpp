Battleship game | Jeu de Bataille Navale
==

**Version 1.0.0**

## Contributors

- Kierian Tirlemont <tirlemont.e1900238@etud.univ-ubs.fr>
- If you want to contribute to this project you're welcome.

## Date

- February 2021

## Languages used | Languages utilisés

- C++ using the g++ compiler (g++ --version : g++ (Ubuntu 10.2.0-13ubuntu1) 10.2.0)

#### Libraries | Librairies

- iostream
- sstream
- fstream
- string
- vector
- cstdlib
- ctime
- map
- algorithm
- sys/types.h
- sys/socket.h
- netinet/in.h
- netdb.h
- unistd.h
- cstring
- arpa/inet.h
- errno.h
- fcntl.h
- stdexcept

## In which context did I this project? | Dans quel contexte a été réalisé ce projet ?

I did this project as part of my studies in IT in the university of Vannes. In 
fact, it's the final project of the c++ module.

Ce projet a été réalisé pour mes études d'informatique à l'IUT de Vannes. En fait,
il s'agit du projet final du module de c++.

## The goal of the project | L'objectif du projet

The goal of the project is to reproduce the battleship game. The game would be 
playable in command line. It will works thought a server and a client playing 
together.

Le but du projet est de reproduire le jeu de bataille navale. Le jeu sera jouable
en ligne de commande. Il fonctionnera a travers un serveur et un client jouant 
ensemble.

## The progress of the project | La progression du projet

The project is finish for me because the goals of the project were made. The battleship
game works perfectly. The only things that could be improve is the ux design 
because I must admit that the design of the game is not very beautiful. Moreover,
the project is only playable in french, it could great to have a multilingual.

Le projet est fini pour moi puisque les buts du projet ont été réalisés. La bataille
navale fonctionne parfaitement. La seule chose qui pourrait être améliorer est le 
design utilisateur car je dois avouer que le jeu n'est pas très beau. De plus, le
jeu est uniquement en français ca pourrait être interessant de rendre le jeu multilangue.

## The required file to execute this software | Les fichiers requis avec le logiciel

The tree structure of the project :

L'arborescence du projet :
```
-- battleship
    |-- bin
        `-- *.o
        `- *.bin
    |-- src
        `- *.h
        `- *.cpp 
    |-- ws
        `-flotille.txt
        `-makefile
        `-deroulement.txt
        `-README.txt
    |-- README.md
```

The tree structure is necessary to run the project. Moreover, you must have the
flotille.txt's file. In this file, you will have to write the name of the boats
that you want on the board, the length of the boat and the number of boats of this
class/type like this :

L'arborescence du projet est nécessaire pour exécuter le projet. De plus, vous devrez
implementer le fichier flotille.txt. Dans ce fichier, vous devrez écrire le nom des 
bateaux qui seront sur le plateau, la taille du bateau et le nombre de bateau de la
classe.

```
Name_of_boat number_of_boat_of_this_type length_of_boat
```

When the line starts with a '#', the line is not taken into account, this is a comment line.

Quand la ligne commence avec un '#', la ligne n'est pas pris en compte, la ligne est commenté.

## Installation

To run the project, you've to be in the ws's directory.

Pour lancer le projet, vous devez être dans le dossier ws.
```bash
cd ws
```
When you're in this directory, you can use the make file to easily launch the project.

Quand vous êtes dans le dossier, vous pouvez utiliser le fichier make pour lancer le projet facilement.

#### Run the test | Lancer les tests

To run the three tests classes (testCGui, textCArmada, testCBateau), you can use the command bellow:

Pour lancer les trois classes (testCGui, textCArmada, testCBateau), vous pouvez utilisez les commandes si dessous:
```bash
make testGCui
make testCArmada
make testCBateau
```

#### Run the game | Lancer le jeu

To play, you can use this command:

Pour joueur, vous pouvez utiliser la commande ci-dessous:
```bash
make lanceurFinal
```
As mentioned higher, you must have set the flotille.txt's file. Next, it'll ask you to select a server and a client.
After that you will be able to play.

Comme mentionner plus haut, vous devrez avoir paramètrer le fichier flotille.txt. Ensuite, on vous demandera de choisir
le serveur et le client. Après vous serez en mesure de jouer.