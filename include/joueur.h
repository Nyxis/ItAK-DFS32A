#ifndef JOUEUR_H
#define JOUEUR_H

#include "carte.h"
#define MAX_CARTES 15

typedef struct {
    Carte cartes[MAX_CARTES];
    int nombreCartes;
    Carte tableau[3][5]; // Tableau de 3 lignes x 5 colonnes
} Joueur;

void afficherEtat(Joueur* joueur1, Joueur* joueur2);
void piocherCarte(Joueur* joueur, Carte carte);
int cartePeutEtreJouee(Carte carte, Carte tableau[3][5]);
void ajouterCarteAuTableau(Carte carte, Carte tableau[3][5], int ligne, int colonne);

#endif

