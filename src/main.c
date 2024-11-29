#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#include "cartes.h"
#include "./app/cardGenerator.c"
#include "./app/deckGenerator.c"
#include "./app/cardChooser.c"
#include "./app/boardManager.c"

/**
 * Deroulement d'un tour
 * 
 * @param playerTurn int - Identifiant du joueur (J1 = 0, J2 = 1)
 * @param decks Card** - Deck d'un joueur
 * @param sizeBoard int* - Tableau contenant la taille du board tel que {tailleLigne1, tailleLigne2, tailleLigne3}
 * @param board Card** - Board d'un joueur 
 */

void turnPlay (int* playerTurn, int remainingCard, Card* decks, int* sizeBoard, Card** board){
    // On tire une carte
    Card drawnCard = cardRandomDrawer(decks, remainingCard);

    // On pose la carte sur le board
    board = boardUpdater(playerTurn, drawnCard, sizeBoard, board);
}


// Fonction pour liberer la mémoire d'un board
void freeBoard(Card** board, int* sizeBoard) {
    if (board == NULL) return;

    for (int i = 0; i < 3; i++) {
        if (board[i] != NULL) {
            free(board[i]);
            board[i] = NULL; // Assurez-vous de ne pas doubler la libération
        }
    }
    free(board);
}

/**
 * Main fonction, contient toute la logique
 * 
 * @param argc int - Nombre d'arguments passés à la fonction
 * @param argv char* - Tableau contenant les arguments passés
 */

int main()
{
    // "Moteur" de randomisation
    srand(time(NULL));

    // Nombre de joueurs
    const int playerCount = 2;
    int playerTurn = 0;
    
    // Génération du deck de J1
   Card* deck1 = deckGenerator();

    // On indique combien de cartes restent au joueur
    int remainingCards = 15;

    // Au début de la partie le board ne contient aucune carte
    // et la taille de chaque ligne est donc de 0
    int sizeBoard[3] = {0, 0, 0};

    // On initialiser le board du 1er joueur
    Card** board = boardInitializer();

    // Tant que J1 à toujours un des cartes et que c'est son tour il peut jouer
    printf("Joueur nº%d\n", playerTurn +1);
    while (playerTurn == 0 && remainingCards > 0)
    {
        turnPlay(&playerTurn, remainingCards, deck1, sizeBoard, board);

        remainingCards--;
    }

    // On affiche le board de J1
    boardPrinter(sizeBoard, board);

    // Le joueur1 à un aucun point au début
    int pointJ1 = 0;

    //
    for (int i = 0; i < 3; i++){
        for(int j = 0; j < sizeBoard[i]; j++){
            pointJ1 = pointJ1 + board[i][j].force;
        }
    }

    freeBoard(board, sizeBoard);

    printf("Joueur 1 à gagné %d points !\n \n", pointJ1);

    // Au début de la partie le board ne contient aucune carte
    // et la taille de chaque ligne est donc de 0
    int sizeBoard2[3] = {0, 0, 0};

    Card* deck2 = deckGenerator();

    Card** board2 = boardInitializer();
    remainingCards = 15;

    // On passe la main au second joueur
    printf("___________________________________________________________________________________________________________________________\n");
    printf("La main passe au joueur 2!\n \n");

    for (int oppTurn = 0; oppTurn < 3; oppTurn++)
    {
        turnPlay(&playerTurn, remainingCards, deck2, sizeBoard2, board2);
    }

    boardPrinter(sizeBoard2, board2);

    int pointJ2 = 0;

    for (int i = 0; i < 3; i++)
    {
        for(int j = 0; j < sizeBoard2[i]; j++)
        {
            pointJ2 = pointJ2 + board2[i][j].force;
        }
    }

    freeBoard(board2, sizeBoard2);

    printf("Joueur 2 à gagné %d points !\n \n", pointJ2);

    if (pointJ1 > pointJ2){
        printf("Joueur 1 à gagné avec %d point(s)!", pointJ1);
    } else if (pointJ2 > pointJ1){
        printf("Joueur 2 à gagné avec %d point(s)!", pointJ2);
    } else {
        printf("Égalité à %d point(s) !", pointJ1);
    }
};