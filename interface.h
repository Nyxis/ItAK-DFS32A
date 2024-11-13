#ifndef INTERFACE_H
#define INTERFACE_H

#include "carte.h"
#include "jeu.h"

void afficherTableau(Carte tableau[LIGNES][COLONNES]);
void afficherRegles();
void attendreDemarrage();
int choisirCarte(Carte main[], int tailleMain);
void choisirEmplacement(int *ligne, int *colonne);

#endif // INTERFACE_H
