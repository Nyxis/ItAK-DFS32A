#ifndef CARDGENERATOR_H
#define CARDGENERATOR_H

#include "cartes.h"

extern char *colors[];

/**
 * Générateur aléatoire de cartes, chaque carte possède trois attributs :
 *   - Force (de 1 à 10)
 *   - Couleur
 *   - Niveau (de 1 à 3)
 *
 * @return Card - Retourne une carte avec les 3 attributs définis précédemment (générés aléatoirement)
 */

Card cardGenerator();

#endif