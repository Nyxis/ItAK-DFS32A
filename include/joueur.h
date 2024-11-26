#ifndef JOUEUR_H
#define JOUEUR_H

#include "carte.h"

#define TAILLE_MAIN 5
#define LIGNES 3
#define COLONNES 5

typedef struct {
    Carte main[TAILLE_MAIN];
    Carte tableau[LIGNES][COLONNES];
    int nombre_cartes_main;
    char nom[50];
    int tours_restants;
} Joueur;

void initialiser_joueur(Joueur* joueur, const char* nom);
void piocher_carte(Joueur* joueur, Carte* pioche, int* indice_pioche);
int ajouter_carte_tableau(Joueur* joueur, int indice_carte_main, int ligne, int colonne);
int peut_jouer_carte(Joueur* joueur);
int calculer_force_totale(Joueur* joueur);

#endif
