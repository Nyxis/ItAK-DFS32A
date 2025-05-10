#include "game_header.h"

Carte set_carte() {
    Carte carte;
    carte.niveau = (Niveau)(rand() % 3 + 1);
    carte.couleur = (Couleur)(rand() % 10);
    int force_values[] = {2, 3, 4, 5, 6, 10};
    carte.force = (Force)(force_values[rand() % 6]);
    return carte;
}



void set_tab(Carte tableau[LIGNES][COLONNES]) {
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            tableau[i][j].niveau = 0;
        }
    }
}