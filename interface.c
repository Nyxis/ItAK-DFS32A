#include "interface.h"
#include "carte.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to display the game board
void afficherTableau(Carte tableau[LIGNES][COLONNES]) {
    printf("\nÉtat actuel du tableau :\n");
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            if (tableau[i][j].force != 0) {
                printf("N%d-F%d ", tableau[i][j].niveau, tableau[i][j].force);
            } else {
                printf("[Empty] ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Shows the rules of the game
void afficherRegles() {
    printf("Bienvenue dans le jeu de cartes en ligne de commande !\n\n");
    printf("Règles du jeu :\n");
    printf("- Chaque joueur possède une main de cartes, chacune ayant un niveau, une couleur et une force.\n");
    printf("- Le niveau détermine la ligne sur laquelle une carte peut être placée :\n");
    printf("    * Niveau 1 : Placée uniquement sur la première ligne.\n");
    printf("    * Niveau 2 : Placée sur la deuxième ligne, si une carte de Niveau 1 est en dessous.\n");
    printf("    * Niveau 3 : Placée sur la troisième ligne, si une carte de Niveau 2 est en dessous.\n");
    printf("- La partie se termine si aucun joueur ne peut plus jouer ou si l’un des joueurs passe son tour.\n");
    printf("- À la fin de la partie, le joueur avec la force totale la plus élevée sur le tableau gagne !\n\n");
    printf("Pour commencer la partie, tapez 'ok' puis appuyez sur Entrée.\n\n");
}

// Wait for the player to type "ok" to start
void attendreDemarrage() {
    char input[10];
    do {
        printf("Tapez 'ok' pour commencer : ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';  // Supprime le saut de ligne
    } while (strcmp(input, "ok") != 0);
}

// Function to choose a card from the hand
int choisirCarte(Carte main[], int tailleMain) {
    char input[10];
    int choix = -1;

    printf("Votre main actuelle :\n");
    for (int i = 0; i < tailleMain; i++) {
        printf("%d: ", i + 1);
        afficherCarte(main[i]);
    }

    printf("Choisissez une carte dans votre main (1 à %d) ou -1 pour passer : ", tailleMain);
    if (fgets(input, sizeof(input), stdin) != NULL) {
        choix = atoi(input);
    }

    return (choix >= 1 && choix <= tailleMain) ? choix - 1 : -1;
}

// Function to choose location (row and column)
void choisirEmplacement(int *ligne, int *colonne) {
    char input[10];

    printf("Choisissez un niveau (1 à %d) : ", LIGNES);
    if (fgets(input, sizeof(input), stdin) != NULL) {
        *ligne = atoi(input) - 1;
    }

    printf("Choisissez une colonne (1 à %d) pour poser la carte : ", COLONNES);
    if (fgets(input, sizeof(input), stdin) != NULL) {
        *colonne = atoi(input) - 1;
    }
}
