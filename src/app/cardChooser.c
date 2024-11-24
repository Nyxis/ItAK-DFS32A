#include <stdio.h>
#include "../../includes/app/cartes.h"

/**
 * Sert à afficher une seule carte
 * 
 * @param card Card - Carte
 */

void cardPrinter(Card card){
    printf("--------------------   \n");
    printf("| Niv.: %-10d |   \n", card.level);
    printf("| Force: %-9d |   \n", card.force);
    printf("| Couleur: %-7s |   \n", card.color);
    printf("--------------------   \n \n");

};

/**
 * /!\ DEPRECATED /!\
 * Sert au joueur pour choisir une carte dans son deck
 * 
 * @param deck Card* - Deck du joueur
 * 
 * @return deck[i] Card - Carte choisie par le joueur dans son deck
 */

Card cardChooser(Card* deck)
{
    int choosenNumber;
    int playingChoice = 0;

    while (playingChoice == 0)
    {
        int cardNumber = 0;

        printf("Votre main est: \n \n");

        for (int row = 1; row < 4; row++)
        {

            for (int i = 0; i < 5; i++)
            {
                printf("| Carte n.%-8d |   ", cardNumber + i + 1);
            }

            printf("\n");
            
            for (int i = 0; i < 5; i++)
            {
                printf("--------------------   ");
            }

            printf("\n");

            for (int i = 0; i < 5; i++)
            {
                printf("| Niv.: %-10d |   ", deck[cardNumber + i].level);
            }

            printf("\n");

            for (int i = 0; i < 5; i++)
            {
                printf("| Force: %-9d |   ", deck[cardNumber + i].force);
            }

            printf("\n");

            for (int i = 0; i < 5; i++)
            {
                printf("| Couleur: %-7s |   ", deck[cardNumber + i].color);
            }

            printf("\n");

            for (int i = 0; i < 5; i++)
            {
                printf("--------------------   ");
            }

            printf("\n \n");

            cardNumber += 5; 

        }

        printf("Quel carte souhaitez-vous jouer ? \n");
        scanf("%d", &choosenNumber);
        printf("\nVous allez jouer la carte %d : \n \n", choosenNumber);

        cardPrinter(deck[choosenNumber - 1]);

        printf("\nÊtes-vous sûr ? [y/n] \n");

        char playerConfirmation;
        scanf("%s", &playerConfirmation);

        if (playerConfirmation == 'y')
        {
            playingChoice = 1;
        }
        
    }

    return deck[choosenNumber - 1];
};

/**
 * Sert a faire piocher une carte au hasard dans le deck du joueur
 * 
 * @param deck Card* - Deck du joueur
 * @param remainingCards int - Nombre de cartes restante dans le deck
 * 
 * @return card Card - Carte piochée aléatoirement par le joueur
 */

Card cardRandomDrawer(Card* deck, int remainingCards)
{
    int randomIndex = rand() % (remainingCards);
    Card selectedCard = deck[randomIndex];
    deck[randomIndex] = deck[remainingCards - 1];
    remainingCards--;

    deck = realloc(deck, remainingCards * sizeof(Card));

    return selectedCard;
};