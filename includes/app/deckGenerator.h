#ifndef DECKGENERATOR_H
#define DECKGENERATOR_H

#include "cartes.h"

/**
 * Générateur de deck, faisant appel à cardGenerator() pour générer les cartes
 *
 * @return Card* - un tableau de taille tailleDeck de cartes générées aléatoirement
 */
Card* deckGenerator();

#endif