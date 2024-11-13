#ifndef JEU_H
#define JEU_H

#include "carte.h"
#include <stdbool.h>

#define LIGNES 3
#define COLONNES 5

// Déclarations de fonctions existantes
int peutPlacerCarte(Carte tableau[LIGNES][COLONNES], int ligne, int colonne, Niveau niveau);
int calculerScoreJoueur(Carte tableau[LIGNES][COLONNES], int joueurNum);
int peutJouer(Carte main[], int tailleMain, Carte tableau[LIGNES][COLONNES]);

// Déclaration de la fonction d'initialisation aléatoire
void initialiserAleatoire();

// Déclarations des nouvelles fonctions
void initialiserPartie(Carte mainJoueur1[], Carte mainJoueur2[], Carte tableau[LIGNES][COLONNES]);
bool tourDeJoueur(Carte main[], int *tailleMain, Carte tableau[LIGNES][COLONNES], int joueurNum, int *passesTurnCount);
bool verifierFinPartie(int passesTurnCountJ1, int passesTurnCountJ2, Carte mainJoueur1[], int tailleMainJ1, Carte mainJoueur2[], int tailleMainJ2, Carte tableau[LIGNES][COLONNES]);
void afficherResultats(Carte tableau[LIGNES][COLONNES]);

#endif // JEU_H
