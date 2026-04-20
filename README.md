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

