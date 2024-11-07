#include <stdio.h>
#include "../../includes/app/cartes.h"

char *colors[] = {
    "BLANC",
    "GRIS",
    "NOIR",
    "BLEU",
    "ORANGE",
    "ROUGE",
    "VIOLET",
    "ROSE",
    "JAUNE",
    "VERT"};

Card cardGenerator()
{

    int force = (rand() % 6) + 2;

    if (force == 7)
    {
        force = 10;
    }

    Card card;
    card.level = (rand() % 3) + 1;   // Level
    card.force = force;              // Force
    card.color = colors[rand() % 10]; // Couleur

    return card;
};
