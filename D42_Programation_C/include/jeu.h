#ifndef JEU_H
#define JEU_H

#include "carte.h"

#define NB_CARTES_MAIN 5
#define NB_CARTES_TABLEAU 15

typedef struct {
    Carte main[NB_CARTES_MAIN];
    Carte tableau[NB_CARTES_TABLEAU];
    int score;
} Joueur;

void initialiser_joueur(Joueur *joueur);
void afficher_etat_partie(Joueur joueur1, Joueur joueur2);
int jouer_carte(Joueur *joueur, int index_carte);
void calculer_score(Joueur *joueur);
void piocher_carte(Joueur *joueur, Carte *pioche, int *index_pioche);

#endif // JEU_H
