#include <stdio.h>
#include <stdlib.h>
#include "../../includes/app/boardManager.h"

/** 
 * Sert à initialiser un board (plateau de jeu) composé
 * de 3 lignes de 5 emplacements pour poser les cartes
 * 
 * @return board Card** - Board du joueur
 */

Card** boardInitializer(){

    Card** board = malloc(3 * sizeof(Card*));

    for (int i = 0; i < 3; i++) {
        board[i] = NULL;
    }

    return board;
}

/**
 * Sert à mettre à jour le board a chaque tour
 * 
 * @param playedCard Card - Index de la carte choisie par le joueur
 * @param sizeBoard int* - Taille actuelle du board
 * @param board Card** - Board du joueur
 * @param playerTurn int* - Identifiant du joueur (J1 = 0, J2 = 1)
 * 
 * @return board Card** - Board du joueur
 */

Card** boardUpdater(Card playedCard, int* sizeBoard, Card** board, int *playerTurn){

    // 
    int indexLigne = playedCard.level - 1;

    switch (indexLigne)
    {
    case 0:
        
        if (sizeBoard[0] <= 5)
        {
            sizeBoard[0]++;
            board[0] = realloc(board[0], sizeBoard[0] * sizeof(Card));
            board[0][sizeBoard[0] - 1] = playedCard;

            return board;
        }
        else
        {
            // fin du tour
            printf("Impossible de jouer, la main passe à J2 \n");
            *playerTurn = 2;
            
            return board;
        }
    
    default:

        printf("Cas level 2 et 3 \n");
        printf("ligne: %d \n", sizeBoard[indexLigne]);
        printf("ligne du dessous: %d \n", sizeBoard[indexLigne -1]);

        if (sizeBoard[indexLigne] < sizeBoard[indexLigne - 1] && sizeBoard[indexLigne - 1] != 0)
        {
            sizeBoard[indexLigne]++;
            board[indexLigne] = realloc(board[indexLigne], sizeBoard[indexLigne] * sizeof(Card));
            board[indexLigne][sizeBoard[indexLigne] - 1] = playedCard;

            return board;
        }
        else
        {
            // fin du tour
            printf("Impossible de jouer, la main passe à J2 \n");
            *playerTurn = 1;

            return board;
        }
    }
}

/**
 * Sert à afficher l'état du board un instant donné
 * 
 * @param sizeBoard int* - Taille actuelle du board
 * @param board Card** - Board du joueur
 */

void boardPrinter(int* sizeBoard, Card** board){
    for (int row = 0; row < 3; row++)
    {
        printf("\n");
        
        for (int i = 0; i < sizeBoard[row] + 1; i++)
        {
            if (i == 0)
            {

                printf("                       ");

            } else {

                printf("--------------------   ");

            }
        }

        printf("\n");

        for (int i = 0; i < sizeBoard[row] + 1; i++)
        {
            if (i == 0)
            {

                printf("                       ");

            } else {

                printf("|  Level: %-8d |   ", board[row][i - 1].level);

            }
        }

        printf("\n");

        for (int i = 0; i < sizeBoard[row] + 1; i++)
        {
            if (i == 0)
            {

                printf("Level %d                ", row + 1);

            } else {

                printf("|  Force: %-8d |   ", board[row][i - 1].force);
            
            }
        }

        printf("\n");

        for (int i = 0; i < sizeBoard[row] + 1; i++)
        {
            if (i == 0)
            {

                printf("                       ");

            } else {

                printf("|  Color: %-8s |   ", board[row][i - 1].color);

            }
        }

        printf("\n");

        for (int i = 0; i < sizeBoard[row] + 1; i++)
        {
            if (i == 0)
            {

                printf("                       ");

            } else {

                printf("--------------------   ");

            }
        }

        printf("\n \n");

    }
}