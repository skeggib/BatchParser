# BatchParser

**BatchParser** permet de lire et de modifier des scripts batch en C++.

## Utilisation

Pour les exemples qui vont suivre nous allons utiliser ce script batch (qui n'a aucun sens dans ce contexte) :

```bat
set REF_FRAME=63
@echo off
set MAYA_VERSION=2015
set MAYA_L=\\server1\%MAYA_VERSION%\R0I1
set MAYA_LOCATION=\\%MAYA_L%\%MAYA_VERSION%\
FOR /f \"tokens=*\" %%G IN ('dir /b') DO (\n\
	echo %%G
)
```

### Lecture d'un script

```c++
using namespace BatchParser;

string script = "..."; // Le script batch cité plus haut

BatchScript bat_script(script);
// Le constructeur de cette classe va parser le script 
// en le découpant en objets de type BatchInstruction 
// (contenus dans bat_script)
```

### Recherche dans un script

Nous souhaitons rechercher les lignes qui contiennent le texte "set MAYA" :

```c++
vector<BatchInstruction*> vec = bat_script.search("set MAYA");

for (int i = 0; i < vec.size(); i++)
	cout << vec[i]->getText() << endl;

/* Va donner :
set MAYA_VERSION=2015
set MAYA_L=\\server1\%MAYA_VERSION%\R0I1
set MAYA_LOCATION=\\%MAYA_L%\%MAYA_VERSION%\
*/
```

### Modification d'une instruction

Nous souhaitons changer le ligne du script où est affectée la variable `MAYA_LOCATION`, en premier temps on récupère la ligne concernée :

```c++
BatchInstruction* inst;

// Si on connait le numéro de la ligne à modifier
inst = bat_script.getInstruction(4);
// Si on ne le connait pas
inst = bat_script.search("set MAYA_LOCATION=")[0];
```

Un objet `BatchInstruction` est composé d'une commande et d'une série d'arguments `BatchArgument`.

Un objet `BatchArgument` est composé d'un nom et d'une valeur.

Par exemple :
`blender file.blend /v -o pic.png`

Donne :
- **Commande** : "blender"
- **Argument** 1 : **Nom** : vide, **Valeur** : "file.blend"
- **Argument** 2 : **Nom** : "/v", **Valeur** : vide
- **Argument** 3 : **Nom** : "-o", **Valeur** : "pic.png"

Pour modifier l'instruction `inst` :

```c++
inst.getArgument(1)->setValue("MAYA_LOCATION=/maya/");

cout << inst.getText() << endl;

/* Va donner :
set MAYA_LOCATION=/maya/
*/
```

## Développement

### Tests unitaires

Ce projet utilise `cpptest` pour réaliser ses tests unitaires.

Compiler les tests :

`make`

Lancer les tests :

`make test`