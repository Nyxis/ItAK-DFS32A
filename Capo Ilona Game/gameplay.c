#include "game_header.h"

int can_be_played(Carte tableau[LIGNES][COLONNES], int row, int col) {
    return tableau[row][col].niveau == 0;
}

int place_carte(Carte tableau[LIGNES][COLONNES], Carte carte) {
    int row = carte.niveau - 1;
    for (int col = 0; col < COLONNES; col++) {
        if (can_be_played(tableau, row, col)) {
            tableau[row][col] = carte;
            return 1;
        }
    }
    return 0; 
}



int calcul_force(Carte tableau[LIGNES][COLONNES]) {
    int force_totale = 0;
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            if (tableau[i][j].niveau != 0) {
                force_totale += tableau[i][j].force;
            }
        }
    }
    return force_totale;
}

void tour_joueur(Carte tableau[LIGNES][COLONNES], Carte main[], int* taille_main) {
    int choix;
    show_hand(main, *taille_main);
    printf("Choisissez une carte à jouer (1 à %d) ou -1 pour passer: ", *taille_main);
    scanf("%d", &choix);

    if (choix == -1) {
        printf("Vous avez passé votre tour.\n");
        return;
    }

    if (choix < 1 || choix > *taille_main) {
        printf("Choix invalide.\n");
        return;
    }

    Carte carte = main[choix - 1];
    if (place_carte(tableau, carte)) {
        printf("Carte placée dans le tableau.\n");
        for (int i = choix - 1; i < *taille_main - 1; i++) {
            main[i] = main[i + 1];
        }
        (*taille_main)--;
    } else {
        printf("Pas de place pour cette carte dans le tableau!\n");
    }
    show_tab(tableau);
}
