#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../includes/app/card.h"
#include "../includes/app/deck.h"

int main(int argc, char *argv[])
{   
    srand(time(NULL));
    
    Decks* deck1 = genererDeck1();
    Decks* deck2 = genererDeck2();

    return 0;
}