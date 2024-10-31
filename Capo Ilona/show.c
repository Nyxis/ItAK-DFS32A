#include "carte.h"

void show_tab(Joueur *joueur) {
    int row = 3, col = 5;
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 5; col++) {
            printf("[");
           show_carte(&joueur->cartes_j[row][col]);
           printf("]\n");
        }
    } printf("\n");
}

void show_carte(const Carte *carte) {
    const char *niveaux[] = {"1", "2", "3"};
    const char *force[] = {"2", "3", "4", "5", "6", "10"};
    const char *couleurs[] = {"Blanc", "Gris", "Noir", "Bleu", "Orange", "Rouge", "Violet", "Rose", "Jaune", "Vert"};

    if (carte != NULL) {
        printf("-niveau: %d" , carte->niveau );
        printf(" -couleur: %s ", couleurs[carte->couleur]);
        printf(" -force: %s", force[carte->force]);
    } else {
        printf("Votre carte est vide\n");
    }
}


void show_carte_played(Joueur *joueur) {
    int index = 0;
    for (index = 0; index < 5; index++) {
        show_carte(&joueur->carte_j[index]);
    }
        printf("\n");
}