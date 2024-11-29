#ifndef BOARDMANAGER_H
#define BOARDMANAGER_H

#include "cartes.h"

/**
 * Sert à initialiser un board (plateau de jeu) composé de 3 lignes de 5 emplacements pour poser les cartes.
 *
 * @return Card** - Board du joueur.
 */
Card** boardInitializer();

/**
 * Sert à mettre à jour le board à chaque tour, en fonction de la carte jouée.
 *
 * @param playedCard Card - Carte jouée par le joueur.
 * @param sizeBoard int* - Taille actuelle du board.
 * @param board Card** - Board du joueur.
 * @param playerTurn int* - Identifiant du joueur (J1 = 0, J2 = 1).
 *
 * @return Card** - Le board du joueur mis à jour.
 */
Card** boardUpdater(int *playerTurn, Card playedCard, int* sizeBoard, Card** board);

/**
 * Sert à afficher l'état du board à un instant donné.
 *
 * @param sizeBoard int* - Taille actuelle du board.
 * @param board Card** - Board du joueur.
 */
void boardPrinter(int* sizeBoard, Card** board);

#endif