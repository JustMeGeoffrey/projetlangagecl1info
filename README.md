# projetlangagecl1info
Projet en langage C réalisé dans le cadre de ma première année de licence informatique

Utilisation de l'application:
Il est nécessaire de télécharger le fichier exécutable ET le fichier scores.json dans le même dossier. Sans le fichier scores.json, l'application ne peut pas fonctionner correctement.



Edition du code source:
Le code source a été redigé via l'IDE CodeBlocks et contient donc des fichiers générés automatiquement par ce dernier. Les fichiers contenant du code rédigé manuellement ou nécessaire à la compilation sont:
- main.c
- scores.json
- include/cJSON.h
- include/exercices.h
- include/gestionCompte.h
- src/cJSON.c
- src/exercices.c
- src/gestionCompte.c

Afin de compiler manuellement, tout ces fichiers doivent être présents dans un même dossier en gardant l'arborescence mentionnée.
La commande suivante doit ensuite être entrée dans le terminal du dossier contenant les fichiers: C:\"Program Files"\CodeBlocks\MinGW\bin\gcc.exe -I include main.c src/*.c -o v1.exe
Le chemin vers le compilateur (C:\"Program Files"\CodeBlocks\MinGW\bin\gcc.exe) peut varier entre utilisateurs. 



Explication des fonctions:

--- EXERCICES.C
- int menuExercices(Session session){}
Cette fonction prend en paramètre une structure Session contenant le nom et le score de l'utilisateur et permet de choisir l'exercice souhaité ou de quitter le programme.

- int random1_10(){}
Cette fonction génère et renvoie un nombre de 1 à 10.

- int random0_100(){}
Cette fonction génère et renvoie un nombre de 0 à 100.

- int addition/soustraction/multiplication(){}
Ces fonctions génèrent une addition/soustraction avec des valeurs allant de 0 à 100 ou une multiplication avec des valeurs allant de 1 à 10 et attend une réponse de l'utilisateur. Tant que la bonne réponse n'est pas trouvée, la fonction pose la question. Un nombre de points est ensuite donné en fonction du nombre d'essais nécessaires.

-int tableMultiplication(){}
Cette fonction demande à l'utilisateur quelle table il souhaite travailler puis demande la réponse pour chaque multiple de cette table allant de 1 à 10. Tant que la bonne réponse n'est pas trouvée, la fonction pose la question. Un nombre de points est ensuite donné en fonction du nombre d'essais nécessaires.

-int division(){}
Cette fonction génère une division euclidienne avec des valeurs allant de 0 à 100 et demande le quotient puis le reste de cette division. Tant que les deux bonnes réponses ne sont pas trouvées, la fonction pose la question. Un nombre de points est ensuite donné en fonction du nombre d'essais nécessaires.



--- GESTIONCOMPTE.c
-Session choixConnexionOuCreation(){}
Cette fonnction demande à l'utilisateur si il souhaite se connecter ou créer un compte. Si l'utilisateur décide de créer un compte, la fonction ajoutUser est appelée. Si lors de la connexion le nom fournis n'existe pas dans scores.json, un message d'erreur apparait et l'utilisateur reviens au menu. Sinon, le nom et le score de l'utilisateur sont affichés et une structure Session est retournée avec ces deux informations.

-int ajoutUser(){}
Cette fonction demande à l'utilisateur d'entrer un nom, charge en mémoire le contenu du fichier scores.json, ajoute un utilisateur à la fin du contenu chargé puis remplace le contenu du fichier par le contenu modifié.

-int connexion(const char* nameLogin){}
Cette fonction prend en paramètre le nom d'utilisateur désiré, charge en mémoire le contenu du fichier scores.json, parcours tout les utilisateurs contenus puis retourne 1 si l'utilisateur désiré est trouvé, sinon retourne 0.

-int getScore(const char* nameUser){}
Cette fonction prend en paramètre le nom d'utilisateur désiré, charge en mémoire le contenu du fichier scores.json, parcours tout les utilisateurs contenus puis retourne le score associé si l'utilisateur désiré est trouvé, sinon retourne 0.

-int nouveauScore(const char* nameUser, int newScore){}
Cette fonction prend en paramètre le nom d'utilisateur désiré et son nouveau score, charge en mémoire le contenu du fichier scores.json, parcours tout les utilisateurs contenus, remplace le score associé par le nouveau score dans le contenu chargé puis remplace le contenu du fichier par le contenu modifié.
