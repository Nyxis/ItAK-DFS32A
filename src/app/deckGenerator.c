#include <stdlib.h>
#include "../../includes/app/cartes.h"
#include "../../includes/app/deckGenerator.h"

/**
 * Générateur de deck, faisant appel à cardGenerator() pour générer les cartes
 * 
 * @return deck Card* - un tableau de taille tailleDeck de cartes générées aléatoirement
 */

Card *deckGenerator()
{
    // On défini la taille du deck
    const int tailleDeck = 15;

    // On crée un tableua dont la taille sera celle indiqué juste avant par 
    // la variable tailleDeck

    Card* deck = malloc(tailleDeck * sizeof(Card));

    for (int i = 0; i < tailleDeck; i++)
    {
        deck[i] = cardGenerator();
    }

    return deck;
};