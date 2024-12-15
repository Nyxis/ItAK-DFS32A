#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../includes/app/card.h"

int niveaux[3] = {1,2,3};

char *couleurs[10] = {
    "BLANC",
    "GRIS",
    "NOIR",
    "BLEU",
    "ORANGE",
    "ROUGE",
    "VIOLET",
    "ROSE",
    "JAUNE",
    "VERT"
};

int forces[6] = {2,3,4,5,6,10};

const int MIN = 0, MAX_level = 2, MAX_couleur = 9, MAX_force = 5;

Carte creerCarte()
{
    int randLevel = (rand() % (MAX_level + 1 - MIN)) + MIN; // MIN <= nombre <= MAX
    int randCouleur = (rand() % (MAX_couleur + 1 - MIN)) + MIN; // MIN <= nombre <= MAX
    int randForce = (rand() % (MAX_force + 1 - MIN)) + MIN; // MIN <= nombre <= MAX

    Carte nouvelleCarte = {niveaux[randLevel], couleurs[randCouleur], forces[randForce]};
    return nouvelleCarte;

    // printf("%d-%s-%d\n", nouvelleCarte.niveau, nouvelleCarte.couleur, nouvelleCarte.force);
}