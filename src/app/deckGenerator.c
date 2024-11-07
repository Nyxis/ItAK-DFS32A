#include "../../includes/app/cartes.h"
#include "../../includes/app/deckGenerator.h"

const int tailleDeck = 15;

Card deck[tailleDeck];

Card *deckGenerator()
{

    for (int i = 0; i < tailleDeck; i++)
    {
        deck[i] = cardGenerator();
    }

    return deck;
};