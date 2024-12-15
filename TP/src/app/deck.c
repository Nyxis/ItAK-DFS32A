#include <stdio.h>
#include "../../includes/app/deck.h"
#include "../../includes/app/card.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

Decks* genererDeck1()
{
    Decks* deck1 = malloc(sizeof(Decks)); 
    if (deck1 == NULL) {
        printf("Erreur d'allocation de mémoire\n");
        exit(1);
    }

    for (int i = 0; i < 15; ++i){
        Carte nouvelleCarte = creerCarte();
        char carteString[20];
        snprintf(carteString, sizeof(carteString), "%d-%s-%d", nouvelleCarte.niveau, nouvelleCarte.couleur, nouvelleCarte.force);
        (*deck1)[i] = strdup(carteString);
    }
    for (int i = 0 ; i< 15; i++)
    {
        printf("%s \n", (*deck1)[i]); 
    }
    printf("\n");
    return deck1;
}

Decks* genererDeck2()
{
    Decks* deck2 = malloc(sizeof(Decks)); 
    if (deck2 == NULL) {
        printf("Erreur d'allocation de mémoire\n");
        exit(1);
    }

    for (int i = 0; i < 15; ++i){
        Carte nouvelleCarte = creerCarte();
        char carteString[20];
        snprintf(carteString, sizeof(carteString), "%d-%s-%d", nouvelleCarte.niveau, nouvelleCarte.couleur, nouvelleCarte.force);
        (*deck2)[i] = strdup(carteString);
    }
    for (int i = 0 ; i< 15; i++)
    {
        printf("%s \n", (*deck2)[i]); 
    }
    printf("\n");
    return deck2;
}