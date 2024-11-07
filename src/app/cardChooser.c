#include <stdio.h>
#include "../../includes/app/cartes.h"

void cardPrinter(Card card){
    printf("--------------------   \n");
    printf("| Niv.: %-10d |   \n", card.level);
    printf("| Force: %-9d |   \n", card.force);
    printf("| Couleur: %-7s |   \n", card.color);
    printf("--------------------   \n \n");

}

int cardChooser(Card *deck)
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

    return choosenNumber;
}