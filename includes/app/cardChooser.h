#ifndef CARDCHOOSER_H
#define CARDCHOOSER_H

#include "cartes.h"

/**
 * Sert à afficher une seule carte
 *
 * @param card Card - Carte
 */
void cardPrinter(Card card);

/**
 * Sert au joueur pour choisir une carte dans son deck
 *
 * @param deck Card* - Deck du joueur
 *
 * @return Card - Carte choisie par le joueur dans son deck
 */
Card cardChooser(Card* deck);

/**
 * Sert à faire piocher une carte au hasard dans le deck du joueur
 *
 * @param deck Card* - Deck du joueur
 * @param remainingCards int - Nombre de cartes restantes dans le deck
 *
 * @return Card - Carte piochée aléatoirement par le joueur
 */
Card cardRandomDrawer(Card* deck, int remainingCards);

#endif