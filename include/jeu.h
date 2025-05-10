#ifndef JEU_H
#define JEU_H

#include "joueur.h"

#define TAILLE_PIOCHE 30

typedef struct {
    Joueur joueur1;
    Joueur joueur2;
    Carte pioche[TAILLE_PIOCHE];
    int indice_pioche;
} Jeu;

void initialiser_jeu(Jeu* jeu);
void melanger_pioche(Carte* pioche, int taille);
void jouer_jeu(Jeu* jeu);

#endif
