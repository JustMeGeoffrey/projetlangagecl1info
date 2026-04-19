#include <stdio.h>
#include "include/exercices.h"
#include "include/gestionCompte.h"

// C:\"Program Files"\CodeBlocks\MinGW\bin\gcc.exe --version

// C:\"Program Files"\CodeBlocks\MinGW\bin\gcc.exe -I include main.c src/*.c -o v1.exe

int main(void) {
    Session session = {"",0};
    int temp;
    int score;

    session = choixConnexionOuCreation();
    menuExercices(session);
    return 0;
}
