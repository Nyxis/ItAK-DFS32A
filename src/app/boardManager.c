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

    if (board == NULL) {
        fprintf(stderr, "Erreur : allocation mémoire échouée pour board\n");
        exit(EXIT_FAILURE);
    }

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
 * 
 * @return board Card** - Board du joueur
 */

Card** boardUpdater(int* playerTurn, Card playedCard, int* sizeBoard, Card** board){

    int indexLigne = playedCard.level - 1;

    if (indexLigne < 0 || indexLigne >= 3) {
            fprintf(stderr, "Erreur : niveau de carte invalide (%d)\n", playedCard.level);
            return board;
        }

    // Cas où on ajoute une carte à une ligne
    if (indexLigne == 0 && sizeBoard[0] < 5) {
        sizeBoard[0]++;
        board[indexLigne] = realloc(board[indexLigne], sizeBoard[0] * sizeof(Card));
        if (board[indexLigne] == NULL) {
            fprintf(stderr, "Erreur : allocation mémoire échouée pour board[%d]\n", indexLigne);
            exit(EXIT_FAILURE);
        }
        board[indexLigne][sizeBoard[0] - 1] = playedCard;
    } else if (indexLigne > 0 &&
               sizeBoard[indexLigne] < sizeBoard[indexLigne - 1] &&
               sizeBoard[indexLigne - 1] > 0) {
        sizeBoard[indexLigne]++;
        board[indexLigne] = realloc(board[indexLigne], sizeBoard[indexLigne] * sizeof(Card));
        if (board[indexLigne] == NULL) {
            fprintf(stderr, "Erreur : allocation mémoire échouée pour board[%d]\n", indexLigne);
            exit(EXIT_FAILURE);
        }
        board[indexLigne][sizeBoard[indexLigne] - 1] = playedCard;
    } else {
        (*playerTurn)++;
    }

    return board;
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
         printf("                       ");
         // Impression des bordures
         for (int i = 0; i < sizeBoard[row]; i++)
         {
             printf("--------------------   ");
         }
         printf("\n");

         printf("                       ");
         // Impression des informations des cartes (Level, Force, Color)
         for (int i = 0; i < sizeBoard[row]; i++)
         {
             printf("|  Level: %-8d |   ", board[row][i].level);
         }
         printf("\n");

        printf("Ligne nº%-15d", row + 1);
         for (int i = 0; i < sizeBoard[row]; i++)
         {
             printf("|  Force: %-8d |   ", board[row][i].force);
         }
         printf("\n");

         printf("                       ");
         for (int i = 0; i < sizeBoard[row]; i++)
         {
             printf("|  Color: %-8s |   ", board[row][i].color);
         }
         printf("\n");

         printf("                       ");
         // Impression des bordures de fin
         for (int i = 0; i < sizeBoard[row]; i++)
         {
             printf("--------------------   ");
         }
         printf("\n\n");
     }
}
