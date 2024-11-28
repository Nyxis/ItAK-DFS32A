#include <stdio.h>
#include <stdlib.h>
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

/**
 * Générateur aleatoire de cartes, chaque carte possède trois attributs:
 *   - Force (de 1 à 10)
 *   - Couleur
 *   - Niveau (de 1 à 3)
 * 
 * @return card Card - Retourne une carte avec les 3 attributs définis précédement (générés aléatoirement)
 */

Card cardGenerator()
{

    int force = (rand() % 6) + 2;

    if (force == 7)
    {
        force = 10;
    }

    Card card;
    card.level = (rand() % 3) + 1;    // Level
    card.force = force;               // Force
    card.color = colors[rand() % 10]; // Couleur

    return card;
};
