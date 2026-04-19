#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"
#include "gestionCompte.h"

/*
int creerCompte(const char* name) {
    // Cree un objet cJSON contenant les infos 'name' et 'score'
    cJSON *json = cJSON_CreateObject();
    cJSON_AddStringToObject(json, "name", name);
    cJSON_AddNumberToObject(json, "score", 0);

    // Convertis l'objet cJSON en string JSON dans la var json_str
    char *json_str = cJSON_Print(json);

    // Ouvre le fichier scores.json et entre dedans le contenu de json_str en vérifiant si le fichier existe au prealable puis le ferme
    FILE *fp = fopen("scores.json", "w");
    if (fp == NULL) {
       printf("Erreur: Impossible d'ouvrir le fichier.\n");
       return 1;
   }
   printf("%s\n", json_str);
   fputs(json_str, fp);
   fclose;

   // Vide le contenu de la var json_str et supprime l'objet json
   cJSON_free(json_str);
   cJSON_Delete(json);
   return 0;
}
*/


int creerCompte(const char* name) {
    char *out;

    cJSON *root,*users,*user;

    //Cree la racine root du fichier et une liste de users
    root = cJSON_CreateObject();
    users = cJSON_CreateArray();

    cJSON_AddItemToObject(root, "users", users);

    //Cree un objet user et l'ajoute à la liste users
    cJSON_AddItemToArray(users, user = cJSON_CreateObject());

    //Ajoute les infos à l'objet user
    cJSON_AddItemToObject(user, "name", cJSON_CreateString(name));
    cJSON_AddNumberToObject(user, "score", 0);

    FILE *fp = fopen("scores.json", "w");
    if (fp == NULL) {
       printf("Erreur: Impossible d'ouvrir le fichier.\n");
       return 1;
    }

    out = cJSON_Print(root);
    printf("%s\n", out);
    fputs(out, fp);
    fclose;

    cJSON_Delete(root);

    return 0;
}

// cJSON_AddItemToArray(cJSON *array, cJSON *item);
// cJSON_InsertItemInArray(cJSON *array, int which, cJSON *newitem);
