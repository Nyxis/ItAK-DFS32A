#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "cartes.h"
#include "./app/cardGenerator.c"
#include "./app/deckGenerator.c"
#include "./app/cardChooser.c"

int main(int argc, char *argv[])
{
    srand(time(NULL));

    Card *deck = deckGenerator();

    int playedCard = cardChooser(deck);

};