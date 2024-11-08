#include <stdio.h>

#define LIGNES 3
#define COLONNES 5

// Definition of possible levels
typedef enum {
    NIVEAU_1 = 1,
    NIVEAU_2,
    NIVEAU_3
} Niveau;

// Definition of possible colors
typedef enum {
    BLANC, GRIS, NOIR, BLEU, ORANGE, ROUGE, VIOLET, ROSE, JAUNE, VERT
} Couleur;

// Definition of possible strength for a card
typedef enum {
    FORCE_2 = 2, FORCE_3, FORCE_4, FORCE_5, FORCE_6, FORCE_10
} Force;

// Structure representing a card
typedef struct {
    Niveau niveau;
    Couleur couleur;
    Force force;
} Carte;

// Viewing function for a card
void afficherCarte(Carte carte) {
    const char *couleurs[] = {"Blanc", "Gris", "Noir", "Bleu", "Orange", "Rouge", "Violet", "Rose", "Jaune", "Vert"};
    printf("Niveau: %d, Couleur: %s, Force: %d\n", carte.niveau, couleurs[carte.couleur], carte.force);
}

// Display function for the game state, including the board and each player's hand
void afficherEtatPartie(Carte tableau[LIGNES][COLONNES], Carte mainJoueur1[], int tailleMainJ1, Carte mainJoueur2[], int tailleMainJ2) {
    printf("Game Board:\n");
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            if (tableau[i][j].force != 0) { // Check if a card is present
                afficherCarte(tableau[i][j]);
            } else {
                printf("[Empty] ");
            }
        }
        printf("\n");
    }

    printf("\nPlayer 1's Hand:\n");
    for (int i = 0; i < tailleMainJ1; i++) {
        afficherCarte(mainJoueur1[i]);
    }

    printf("\nPlayer 2's Hand:\n");
    for (int i = 0; i < tailleMainJ2; i++) {
        afficherCarte(mainJoueur2[i]);
    }
}

int main() {
    // Initialize an empty game board
    Carte tableau[LIGNES][COLONNES] = {{{0}}};

    // Initialize players' hands with sample cards
    Carte mainJoueur1[] = {{NIVEAU_1, ROUGE, FORCE_3}, {NIVEAU_2, BLEU, FORCE_5}};
    Carte mainJoueur2[] = {{NIVEAU_1, NOIR, FORCE_4}, {NIVEAU_3, VERT, FORCE_10}};

    // Display the initial state of the game
    afficherEtatPartie(tableau, mainJoueur1, 2, mainJoueur2, 2);

    return 0;
}
