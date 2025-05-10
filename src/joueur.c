#include <stdio.h>
#include <string.h>
#include "joueur.h"
#include <jeu.h>

void initialiser_joueur(Joueur* joueur, const char* nom) {
    joueur->nombre_cartes_main = 0;
    joueur->tours_restants = 3;
    strncpy(joueur->nom, nom, sizeof(joueur->nom) - 1);
    joueur->nom[sizeof(joueur->nom) - 1] = '\0';

    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            joueur->tableau[i][j].niveau = 0;
            joueur->tableau[i][j].couleur = BLANC;
            joueur->tableau[i][j].force = FORCE_2;
        }
    }
}

void piocher_carte(Joueur* joueur, Carte* pioche, int* indice_pioche) {
    if (joueur->nombre_cartes_main < TAILLE_MAIN && *indice_pioche < TAILLE_PIOCHE) {
        joueur->main[joueur->nombre_cartes_main] = pioche[*indice_pioche];
        joueur->nombre_cartes_main++;
        (*indice_pioche)++;
    }
}

int ajouter_carte_tableau(Joueur* joueur, int indice_carte_main, int ligne, int colonne) {
    if (indice_carte_main < 0 || indice_carte_main >= joueur->nombre_cartes_main) {
        return 0;
    }

    Carte carte = joueur->main[indice_carte_main];

    if (ligne != (int)(carte.niveau) - 1) {
        return 0;
    }
    if (ligne < 0 || ligne >= LIGNES || colonne < 0 || colonne >= COLONNES) {
        return 0;
    }
    if (joueur->tableau[ligne][colonne].niveau != 0) {
        return 0;
    }

    if (carte.niveau > 1) {
        if (ligne == 0) {
            return 0;
        }
        NiveauCarte niveau_requis = (NiveauCarte)(carte.niveau - 1);
        if (joueur->tableau[ligne - 1][colonne].niveau != niveau_requis) {
            return 0;
        }
    }

    joueur->tableau[ligne][colonne] = carte;

    for (int i = indice_carte_main; i < joueur->nombre_cartes_main - 1; i++) {
        joueur->main[i] = joueur->main[i + 1];
    }
    joueur->nombre_cartes_main--;

    return 1;
}

int peut_jouer_carte(Joueur* joueur) {
    for (int i = 0; i < joueur->nombre_cartes_main; i++) {
        Carte carte = joueur->main[i];
        int ligne_cible = (int)(carte.niveau) - 1;

        if (ligne_cible < 0 || ligne_cible >= LIGNES) {
            continue;
        }

        for (int colonne = 0; colonne < COLONNES; colonne++) {
            if (joueur->tableau[ligne_cible][colonne].niveau == 0) {
                if (carte.niveau == 1) {
                    return 1;
                } else {
                    if (ligne_cible == 0) {
                        continue;
                    }
                    NiveauCarte niveau_requis = (NiveauCarte)(carte.niveau - 1);
                    if (joueur->tableau[ligne_cible - 1][colonne].niveau == niveau_requis) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int calculer_force_totale(Joueur* joueur) {
    int total = 0;
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            if (joueur->tableau[i][j].niveau != 0) {
                total += joueur->tableau[i][j].force;
            }
        }
    }
    return total;
}
