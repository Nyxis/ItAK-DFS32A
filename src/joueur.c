#include <stdio.h>
#include "joueur.h"

void piocherCarte(Joueur* joueur, Carte carte) {
    if (joueur->nombreCartes < MAX_CARTES) {
        joueur->cartes[joueur->nombreCartes] = carte; // Ajoute la carte à la main
        joueur->nombreCartes++;
    }
}

void afficherEtat(Joueur* joueur1, Joueur* joueur2) {
    printf("Etat du Joueur 1:\n");
    afficherTableau(joueur1->tableau);
    printf("Main:\n");
    for (int i = 0; i < joueur1->nombreCartes; i++) {
        afficherCarte(joueur1->cartes[i]);
    }
    printf("\n");

    printf("Etat du Joueur 2:\n");
    afficherTableau(joueur2->tableau);
    printf("Main:\n");
    for (int i = 0; i < joueur2->nombreCartes; i++) {
        afficherCarte(joueur2->cartes[i]);
    }
    printf("\n");
}
