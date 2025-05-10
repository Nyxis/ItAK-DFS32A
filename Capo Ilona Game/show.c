#include "game_header.h"

// Afficher la main du joueur
void show_hand(Carte main[], int taille) {
    for (int i = 0; i < taille; i++) {
        printf("%d: ", i + 1);
        show_carte(main[i]);
        printf("\n");
    }
}


// Afficher le tableau de jeu
void show_tab(Carte tableau[LIGNES][COLONNES]) {
    char *tab_coul[10] = {"blanc", "gris", "noir", "bleu", "orange", "rouge", "violet", "rose", "jaune", "vert"};
    printf("[Map du jeu]\n");
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            if (tableau[i][j].niveau == 0) {
                printf("[     ] ");
            } else {
                printf("[niv:%d couleur:%s force:%d] ", tableau[i][j].niveau, tab_coul[tableau[i][j].couleur], tableau[i][j].force);
            }
        }
        printf("\n");
    }
}

// Afficher une carte
void show_carte(Carte carte) {
    const char* couleurs[] = {"Blanc", "Gris", "Noir", "Bleu", "Orange", "Rouge", "Violet", "Rose", "Jaune", "Vert"};
    printf("Niveau: %d, Couleur: %s, Force: %d", carte.niveau, couleurs[carte.couleur], carte.force);
}