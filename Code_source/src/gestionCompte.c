#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/cJSON.h"
#include "../include/gestionCompte.h"



int ajoutUser() {

    char nameTemp[100];
    printf("Entrez votre nom d'utilisateur: ");
    scanf("%s", nameTemp);
    printf("\n");
    const char* name = nameTemp;

    //Ouvre le fichier en mode lecture
    FILE *fp = fopen("scores.json", "r");


    //Crée un buffer et y écrit le contenu du fichier
    char buffer[1024] = {0};
    cJSON *json = NULL;

    //Parse le buffer dans json
    if (fp) {
        int len = fread(buffer, 1, sizeof(buffer) - 1, fp);
        fclose(fp);
        buffer[len] = '\0';

        json = cJSON_Parse(buffer);
    }

    //Récupère dans users tout les users du JSON
    cJSON *users = cJSON_GetObjectItem(json, "users");

    //Crée un utilisateur et lui donne un nom passé en paramètre de la fonction et lui attribue un score de 0
    cJSON *user = cJSON_CreateObject();
    cJSON_AddStringToObject(user, "name", name);
    cJSON_AddNumberToObject(user, "score", 0);

    //Ajoute le nouveau user aux autres users
    cJSON_AddItemToArray(users, user);

    //Met le contenu de json dans la variable string
    char *string = cJSON_Print(json);

    // Sauvegarde dans le contenu de string dans le fichier JSON
    fp = fopen("scores.json", "w");
    if (fp) {
        fputs(string, fp);
        fclose(fp);
    }

    cJSON_Delete(json);

    return 0;
}

int connexion(const char* nameLogin) {

    int found = 0;
    cJSON *user = NULL;

    //Ouvre le fichier en mode lecture
    FILE *fp = fopen("scores.json", "r");

    //Crée un buffer et y écrit le contenu du fichier
    char buffer[1024] = {0};
    cJSON *json = NULL;

    //Parse le buffer dans json
    if (fp) {
        int len = fread(buffer, 1, sizeof(buffer) - 1, fp);
        fclose(fp);
        buffer[len] = '\0';

        json = cJSON_Parse(buffer);
    }

    //Récupère dans users tout les users du JSON
    cJSON *users = cJSON_GetObjectItem(json, "users");

    cJSON_ArrayForEach(user, users){
        cJSON *name = cJSON_GetObjectItemCaseSensitive(user, "name");

        if (strcmp(name->valuestring, nameLogin) == 0){ //Compare les valeurs des deux variables et retourne 0 si identique
            return 1;
        }
    }

    return 0;

}

int getScore(const char* nameUser){

    cJSON *user = NULL;

    //Ouvre le fichier en mode lecture
    FILE *fp = fopen("scores.json", "r");

    //Crée un buffer et y écrit le contenu du fichier
    char buffer[1024] = {0};
    cJSON *json = NULL;

    //Parse le buffer dans json
    if (fp) {
        int len = fread(buffer, 1, sizeof(buffer) - 1, fp);
        fclose(fp);
        buffer[len] = '\0';

        json = cJSON_Parse(buffer);
    }

    //Récupère dans users tout les users du JSON
    cJSON *users = cJSON_GetObjectItem(json, "users");

    cJSON_ArrayForEach(user, users){
        cJSON *name = cJSON_GetObjectItemCaseSensitive(user, "name");
        cJSON *score = cJSON_GetObjectItemCaseSensitive(user, "score");

        if (strcmp(name->valuestring, nameUser) == 0){ //Compare les valeurs des deux variables et retourne le score correspondant si identique
            return (score->valueint);
        }
    }

    return 0;

}

int nouveauScore(const char* nameUser, int newScore) {

    cJSON *user = NULL;

    // Ouvre le fichier en mode lecture
    FILE *fp = fopen("scores.json", "r");

    // Crée un buffer et y écrit le contenu du fichier
    char buffer[1024] = {0};
    cJSON *json = NULL;

    // Parse le buffer dans json
    if (fp) {
        int len = fread(buffer, 1, sizeof(buffer) - 1, fp);
        fclose(fp);
        buffer[len] = '\0';

        json = cJSON_Parse(buffer);
    }

    // Récupère dans users tous les users du JSON
    cJSON *users = cJSON_GetObjectItem(json, "users");

    int found = 0;

    // Vérifie si le nom actuel est celui voulu en paramètre et change le score si oui
    cJSON_ArrayForEach(user, users) {
        cJSON *name  = cJSON_GetObjectItemCaseSensitive(user, "name");
        cJSON *score = cJSON_GetObjectItemCaseSensitive(user, "score");

        if (strcmp(name->valuestring, nameUser) == 0) {
            cJSON_SetNumberValue(score, newScore);
            found = 1;
            break;
        }
    }

    // Sauvegarde le JSON modifié dans le fichier
    char *string = cJSON_Print(json);
    fp = fopen("scores.json", "w");
    if (fp) {
        fputs(string, fp);
        fclose(fp);
    }

    free(string);
    cJSON_Delete(json);

    return 1;
}

Session choixConnexionOuCreation() {
    int connected = 0;
    char name[100];
    int score = 0;
    Session session = {"",0};

    while (connected!=1) {

        int choix;
        printf("+ - - - - - - - - - - - +\n");
        printf(" 1 : Connexion\n");
        printf(" 2 : Creation de compte\n");
        printf("+ - - - - - - - - - - - +\n");
        printf("Votre choix: ");
        scanf("%d", &choix);
        if(choix==1){
            printf("\nEntrez votre nom d'utilisateur: ");
            scanf("%99s", name);
            int result = connexion(name);
            if (result == 1){
                score = getScore(name);
                printf("Connexion reussie !\n");
                printf("nom: %s , score: %d\n\n",name ,score);
                connected = 1;
            }
            else {
                printf("Utilisateur introuvable.\n");
            }
        } else if(choix==2){
            ajoutUser();
            printf("Compte cree avec succes.\n");
        } else {
            printf("Choix invalide.\n");
        }
    };
    strcpy(session.username, name);
    session.userscore = score;
    return session;
}
