#include "../include/exercices.h"
#include "../include/gestionCompte.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int menuExercices(Session session) {

    int choixExo;
    int pointsGagnes;
    int continuer;
    int finJeu = 0;

    while (!finJeu){
    continuer = 1;
    pointsGagnes = 0;
    printf("+ - - - - - - - - - - - +\n 1 : Addition a 100\n 2 : Soustraction a 100\n 3 : Multiplications a 10\n 4 : Tables de multiplications\n 5 : Divisions a 100\n 0 : Quitter\n+ - - - - - - - - - - - +\n");
    /*
    + - - - - - - - - - - - +
     1 : Addition à 100\n")
     2 : Soustraction à 100\n")
     3 : Multiplications à 10\n")
     4 : Tables de multiplications\n")
     5 : Divisions à 100\n")
     0 : Quitter\n")
     /!\ Vos points ne sont enregistrés
    + - - - - - - - - - - - +
    */
    printf("Votre choix: ");
    scanf("%d", &choixExo);
    printf("\n");

    switch(choixExo) {
        case 1:
            while(continuer == 1) {
                pointsGagnes += addition();
                printf("+ - - - - - - - - - - - +\n 0 : Retour au choix des exercices\n 1 : Nouveau Calcul\n+ - - - - - - - - - - - +\n");
                /*
                + - - - - - - - - - - - +
                 0 : Retour au choix des exercices
                 1 : Nouveau Calcul
                + - - - - - - - - - - - +
                */
                printf("Votre choix: ");
                scanf("%d", &continuer);
                printf("\n");
            }
            session.userscore+=pointsGagnes;
            nouveauScore(session.username, session.userscore);
            break;
        case 2:
            while(continuer == 1) {
                pointsGagnes += soustraction();
                printf("+ - - - - - - - - - - - +\n 0 : Retour au choix des exercices\n 1 : Nouveau Calcul\n+ - - - - - - - - - - - +\n");
                /*
                + - - - - - - - - - - - +
                 0 : Retour au choix des exercices
                 1 : Nouveau Calcul
                + - - - - - - - - - - - +
                */
                printf("Votre choix: ");
                scanf("%d", &continuer);
                printf("\n");
            }
            session.userscore+=pointsGagnes;
            nouveauScore(session.username, session.userscore);
            break;
        case 3:
            while(continuer == 1) {
                pointsGagnes += multiplication();
                printf("+ - - - - - - - - - - - +\n 0 : Retour au choix des exercices\n 1 : Nouveau Calcul\n+ - - - - - - - - - - - +\n");
                /*
                + - - - - - - - - - - - +
                 0 : Retour au choix des exercices
                 1 : Nouveau Calcul
                + - - - - - - - - - - - +
                */
                printf("Votre choix: ");
                scanf("%d", &continuer);
                printf("\n");
            }
            session.userscore+=pointsGagnes;
            nouveauScore(session.username, session.userscore);
            break;
        case 4:
            while(continuer == 1) {
                pointsGagnes += tableMultiplication();
                printf("+ - - - - - - - - - - - +\n 0 : Retour au choix des exercices\n 1 : Nouveau Calcul\n+ - - - - - - - - - - - +\n");
                /*
                + - - - - - - - - - - - +
                 0 : Retour au choix des exercices
                 1 : Nouveau Calcul
                + - - - - - - - - - - - +
                */
                printf("Votre choix: ");
                scanf("%d", &continuer);
                printf("\n");
            }
            session.userscore+=pointsGagnes;
            nouveauScore(session.username, session.userscore);
            break;
        case 5:
            while(continuer == 1) {
                pointsGagnes += division();
                printf("+ - - - - - - - - - - - +\n 0 : Retour au choix des exercices\n 1 : Nouveau Calcul\n+ - - - - - - - - - - - +\n");
                /*
                + - - - - - - - - - - - +
                 0 : Retour au choix des exercices
                 1 : Nouveau Calcul
                + - - - - - - - - - - - +
                */
                printf("Votre choix: ");
                scanf("%d", &continuer);
                printf("\n");
            }
            session.userscore+=pointsGagnes;
            nouveauScore(session.username, session.userscore);
            break;
        case 0:
            finJeu = 1;
    }
    }
    return 1;
}

int addition() {
    int a = random0_100();
    int b = random0_100();
    int resultat;
    int essais = 1;
    printf("Entrez le resultat de %d + %d:", a, b);
    scanf("%d", &resultat);

    while (resultat != a + b) {
        essais += 1;
        printf("\nIncorrect. Entrez le resultat de %d + %d:", a, b);
        scanf("%d", &resultat);
    }
    if(essais==1){
        printf("Vous gagnez 5 points!\n\n");
        return 5;
    } else if ((essais>1)&&(essais<=3)) {
        printf("Vous gagnez 3 points!\n\n");
        return 3;
    }
    printf("Vous gagnez 1 point!\n\n");
    return 1;
}


int soustraction() {
    int a = random0_100();
    int b = random0_100();
    int essais = 1;
    if (a < b) {
        int c = b;
        b = a;
        a = c;
    }
    int resultat;
    printf("Entrez le resultat de %d - %d:", a, b);
    scanf("%d", &resultat);
    while (resultat != a - b) {
        printf("\nIncorrect. Entrez le resultat de %d - %d:", a, b);
        essais += 1;
        scanf("%d", &resultat);
    }
    if(essais==1){
        printf("Vous gagnez 5 points!\n\n");
        return 5;
    } else if ((essais>1)&&(essais<=3)) {
        printf("Vous gagnez 3 points!\n\n");
        return 3;
    }
    printf("Vous gagnez 1 point!\n\n");
    return 1;
}

int multiplication() {
    int a = random1_10();
    int b = random1_10();
    int essais = 1;
    int resultat;
    printf("Entrez le resultat de %d x %d:", a , b);
    scanf("%d", &resultat);
    while (resultat != a * b) {
        printf("\nIncorrect. Entrez le resultat de %d x %d:", a , b);
        essais += 1;
        scanf("%d", &resultat);
    }
    if(essais==1){
        printf("Vous gagnez 5 points!\n\n");
        return 5;
    } else if ((essais>1)&&(essais<=3)) {
        printf("Vous gagnez 3 points!\n\n");
        return 3;
    }
    printf("Vous gagnez 1 point!\n\n");
    return 1;
}

int tableMultiplication() {
    int table = 0;
    int resultat = 0;
    int essais = 1;
    while ((table > 10) || (table < 1)) {
        printf("Entrez la table que vous souhaitez travailler (entre 1 et 10): ");
        scanf("%d", &table);
    }
    printf("\n+---Table de %d ---+\n", table);
    for (int i = 1; i <= 10; i++) {
        printf("%d. %d x %d\n", i, table, i);
    }
    for (int i = 1; i <= 10; i++) {
        printf("\nEntrez le resultat de %d x %d: ", table, i);
        scanf("%d", &resultat);
        while (resultat != (i*table)) {
            printf("Incorrect! Entrez le resultat de %d x %d: ", table, i);
            essais += 1;
            scanf("%d", &resultat);
        }
        printf("Correct!");
    }
    printf("\n");
    if(essais==1){
        printf("Vous gagnez 5 points!\n\n");
        return 5;
    } else if ((essais>1)&&(essais<=3)) {
        printf("Vous gagnez 3 points!\n\n");
        return 3;
    }
    printf("Vous gagnez 1 point!\n\n");
    return 1;
}

int division() {
    int a = random0_100();
    int b = random0_100();
    int essais = 1;
    if (a==0) {
        a = 1;
    } else if (b==0) {
        a = 1;
    }
    if (a < b) {
        int c = a;
        a = b;
        b = c;
    }
    int quotient;
    printf("\nEntrez le quotient de %d / %d:\n", a, b);
    scanf("%d", &quotient);
    int reste;
    printf("\nEntrez le reste de %d / %d:\n", a, b);
    scanf("%d", &reste);
    while (a != (quotient*b) + reste) {
        essais += 1;
        printf("\nIncorrect. Entrez le quotient de %d / %d:\n", a, b);
        scanf("%d", &quotient);
        printf("\nEntrez le reste de %d / %d:\n", a, b);
        scanf("%d", &reste);
    }
    if(essais==1){
        printf("Vous gagnez 5 points!\n\n");
        return 5;
    } else if ((essais>1)&&(essais<=3)) {
        printf("Vous gagnez 3 points!\n\n");
        return 3;
    }
    printf("Vous gagnez 1 point!\n\n");
    return 1;
}

int random1_10() {
    srand(time(NULL)*rand() % 10);
    return (rand() % 10) + 1;
}

int random0_100() {
    srand(time(NULL)*rand() % 10);
    return rand() % 101;
}
