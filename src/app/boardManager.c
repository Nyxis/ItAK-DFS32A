#include <stdio.h>
#include "../../includes/app/cartes.h"

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

Card** boardUpdater(Card playedCard, int* sizeBoard, Card** board, int* playerTurn){

    int indexLigne = playedCard.level - 1;

    switch (indexLigne)
    {
    case 0:
        if (sizeBoard[0] < 5)
        {
            sizeBoard[0]++;
            
            Card* tempBoard = realloc(board[0], sizeBoard[0] * sizeof(Card));
            if (tempBoard == NULL) {
                    printf("Erreur de réallocation mémoire !\n");
                    return board;
                }
            board[0] = tempBoard;
            board[0][sizeBoard[0] - 1] = playedCard;

            return board;
        }
        else
        {
            // fin du tour
            (*playerTurn)++;
            printf("Impossible de jouer, la main passe à l'autre joueur ! \n");
            return board;
        }
    
    default:

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
            (*playerTurn)++;
            printf("Impossible de jouer, la main passe à l'autre joueur ! \n");
            
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
    printf("sizeboard: %d \n", *sizeBoard);

    // for (int row = 0; row < 3; row++)
    // {
    //     // Impression des bordures
    //     for (int i = 0; i < sizeBoard[row]; i++)
    //     {
    //         printf("--------------------   ");
    //     }
    //     printf("\n");

    //     // Impression des informations des cartes (Level, Force, Color)
    //     for (int i = 0; i < sizeBoard[row]; i++)
    //     {
    //         printf("|  Level: %-8d |   ", board[row][i].level);
    //     }
    //     printf("\n");

    //     for (int i = 0; i < sizeBoard[row]; i++)
    //     {
    //         printf("|  Force: %-8d |   ", board[row][i].force);
    //     }
    //     printf("\n");

    //     for (int i = 0; i < sizeBoard[row]; i++)
    //     {
    //         printf("|  Color: %-8s |   ", board[row][i].color);
    //     }
    //     printf("\n");

    //     // Impression des bordures de fin
    //     for (int i = 0; i < sizeBoard[row]; i++)
    //     {
    //         printf("--------------------   ");
    //     }
    //     printf("\n\n");
    // }
}
