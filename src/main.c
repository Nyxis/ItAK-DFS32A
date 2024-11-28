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
 * @param playerTurn int - Identifiant du joueur 9J1 = 0, J2 = 1)
 * @param decks Card** - Deck d'un joueur
 * @param sizeBoard int* - Tableau contenant la taille du board tel que {tailleLigne1, tailleLigne2, tailleLigne3}
 * @param board Card** - Board d'un joueur 
 */

void turnPlay (int* playerTurn, int remainingCard, Card** decks, int* sizeBoard, Card*** board){

    // On prompte l'utilisateur
    Card drawnCard = cardChooser(decks[0]);

    // On pose la carte sur le board
    board = boardUpdater(drawnCard, sizeBoard, board, &playerTurn);
    boardPrinter(sizeBoard, board);
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
    
    // Génération des decks et mise dans un tableau
    Card* decks[playerCount];

    for (int i = 0; i < playerCount; i++)
    {
       decks[i] = deckGenerator();
    }

    // On indique combien de cartes restent au joueur
    int remainingCards = 15;

    // Au début de la partie le board ne contient aucune carte
    // et la taille de chaque ligne est donc de 0
    int sizeBoard[3] = {0, 0, 0};

    // On initializer le board
    Card** board = boardInitializer();

    // Tant que J1 à toujours un des cartes et que c'est son tour il peut jouer
    while (playerTurn == 0 && remainingCards > 0)
    {
        turnPlay(playerTurn, remainingCards, decks, sizeBoard, board);

        remainingCards--;
    }

    // Quand J1 ne peux plus jouer, J2 peut jouer 3 tours
    for (int oppTurn = 0; oppTurn < 3; oppTurn++)
    {
        turnPlay(playerTurn, remainingCards, decks, sizeBoard, board);
    }
    
    // On libere l'espace occupé par le board
    free(board);
};