#include "exercices.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int addition(int a, int b) {
    int resultat;
    printf("Entrez le résultat de %d + %d:", a, b);
    scanf("%d", &resultat);
    if (resultat == a + b) {
        return 1;
    }
    return 0;
}

int soustraction(int a, int b) {
    if (a < b) {
        int c = b;
        b = a;
        a = c;
    }
    int resultat;
    printf("Entrez le résultat de %d - %d:", a, b);
    scanf("%d", &resultat);
    if (resultat == a - b) {
        return 1;
    }
    return 0;
}

int multiplication(int a, int b) {
    int resultat;
    printf("Entrez le résultat de %d x %d", a , b);
    scanf("%d", &resultat);
    if (resultat == a * b) {
        return 1;
    }
}

int tableMultiplication() {
    int table = 0;
    int resultat = 0;
    while ((table > 10) || (table < 1)) {
        printf("Entrez la table que vous souhaitez travailler (entre 1 et 10)");
        scanf("%d", &table);
    }
    printf("+---Table de %d ---+", table);
    for (int i = 1; i <= 10; i++) {
        printf("%d. %d x %d", i, table, i);
    }
    for (int i = 1; i <= 10; i++) {
        printf("Entrez le résultat de %d x %d", &table, &i);
        scanf("%d", resultat);
        if (resultat == i*table) {
            printf("Correct!");
        } else {
            printf("Incorrect!");
            return 0;
        }
    }
    return 1;
}

int division(int a, int b) {
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
    printf("Entrez le quotient de %d / %d:", a, b);
    scanf("%d", &quotient);
    int reste;
    printf("Entrez le reste de %d / %d:", a, b);
    scanf("%d", &reste);
    if (a == (quotient*b) + reste) {
        return 1;
    }
    return 0;
}

int random1_10() {
    srand(time(NULL)*(rand() % 10));
    return (rand() % 10) + 1;
}

int random0_100() {
    srand(time(NULL)*(rand() % 10));
    return rand() % 101;
}
