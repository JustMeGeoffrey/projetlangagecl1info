#ifndef GESTIONCOMPTE_H_INCLUDED
#define GESTIONCOMPTE_H_INCLUDED

typedef struct {
    char  username[100];
    int   userscore;
} Session;

int ajoutUser();

int connexion(const char* name);

int getScore(const char* nameUser);

int nouveauScore(const char* nameUser, int newScore);

Session choixConnexionOuCreation();

#endif // GESTIONCOMPTE_H_INCLUDED
