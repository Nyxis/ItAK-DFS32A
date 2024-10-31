#include <stdio.h>
#include "carte.h"

void afficherCarte(Carte carte) {
    const char* couleurs[] = {"Blanc", "Gris", "Noir", "Bleu", "Orange", 
                               "Rouge", "Violet", "Rose", "Jaune", "Vert"};
    printf("%d-%s-%d ", carte.niveau, couleurs[carte.couleur], carte.force);
}

void afficherTableau(Carte tableau[3][5]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (tableau[i][j].niveau != 0) { // Vérifie si la carte est jouée
                afficherCarte(tableau[i][j]);
            } else {
                printf("Vide ");
            }
        }
        printf("\n");
    }
}

int cartePeutEtreJouee(Carte carte, Carte tableau[3][5]) {
    int ligne = carte.niveau - 1;

    // Vérifier s'il y a une place sur la ligne pour jouer la carte
    for (int j = 0; j < 5; j++) {
        if (tableau[ligne][j].niveau == 0) {
            return 1; // Il y a de la place sur cette ligne
        }
    }

    // Vérifier si la carte de niveau supérieur est jouée
    if (carte.niveau > 1) {
        int ligneSuperieure = carte.niveau - 2; // Ligne de la carte de niveau supérieur
        for (int j = 0; j < 5; j++) {
            if (tableau[ligneSuperieure][j].niveau != 0) {
                return 1; // Une carte de niveau supérieur est présente
            }
        }
    }
    
    return 0; // Pas de place ou carte de niveau supérieur absente
}

void ajouterCarteAuTableau(Carte carte, Carte tableau[3][5], int ligne, int colonne) {
    tableau[ligne][colonne] = carte; // Ajoute la carte au tableau
}
