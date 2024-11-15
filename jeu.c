#include "jeu.h"
#include "interface.h"  // pour afficherRegles, attendreDemarrage, choisirCarte, etc.
#include "carte.h"      // pour créer les cartes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Initializes the random number generator
void initialiserAleatoire() {
    srand(time(NULL));
}

// Generates a hand of random cards for a player
void genererMain(Carte main[], int tailleMain) {
    for (int i = 0; i < tailleMain; i++) {
        main[i] = createCarte(
            (Niveau)(rand() % 3 + 1),              // Levels 1, 2 or 3
            (Couleur)(rand() % 10),                // Colors 0 to 9
            (Force)((rand() % 5) * 2 + 2),         // Forces among {2, 4, 6, 8, 10}
            "Carte aléatoire",
            effetCarte                             // Function to call when the card is played
        );
    }
}

// Initialize the game by generating hands and resetting the board
void initialiserPartie(Carte mainJoueur1[], Carte mainJoueur2[], Carte tableau[LIGNES][COLONNES]) {
    initialiserAleatoire();
    afficherRegles();
    attendreDemarrage();

    genererMain(mainJoueur1, NB_CARTES_MAIN);
    genererMain(mainJoueur2, NB_CARTES_MAIN);

    // Réinitialiser le tableau
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            tableau[i][j].force = 0;
            tableau[i][j].joueur = 0;  // Added: initialize the player field
        }
    }
}

// Manage a player's turn, including card selection and placement
bool tourDeJoueur(Carte main[], int *tailleMain, Carte tableau[LIGNES][COLONNES], int joueurNum, int *passesTurnCount) {
    printf("Joueur %d, votre tour.\n", joueurNum);
    int choixCarte = choisirCarte(main, *tailleMain);

    if (choixCarte == -1) {
        printf("Joueur %d a passé son tour.\n", joueurNum);
        (*passesTurnCount)++;
        return false;
    }

    int ligne, colonne;
    choisirEmplacement(&ligne, &colonne);

    if (peutPlacerCarte(tableau, ligne, colonne, main[choixCarte].niveau)) {
        tableau[ligne][colonne] = main[choixCarte];
        tableau[ligne][colonne].joueur = joueurNum;  // Match the card to the player
        jouerCarte(&main[choixCarte]);

        // Remove card from hand and reduce hand size
        for (int i = choixCarte; i < *tailleMain - 1; i++) {
            main[i] = main[i + 1];
        }
        (*tailleMain)--;
        *passesTurnCount = 0;  // Reset the pass turn counter for this player
        return true;
    } else {
        printf("Placement invalide. Veuillez réessayer.\n");
        return tourDeJoueur(main, tailleMain, tableau, joueurNum, passesTurnCount);
    }
}


// Check if the game is over
bool verifierFinPartie(int passesTurnCountJ1, int passesTurnCountJ2, Carte mainJoueur1[], int tailleMainJ1, Carte mainJoueur2[], int tailleMainJ2, Carte tableau[LIGNES][COLONNES]) {
    if (passesTurnCountJ1 >= 1 && passesTurnCountJ2 >= 1) {
        printf("Les deux joueurs ont passé leur tour consécutivement. Fin de la partie.\n");
        return true;
    }
    if (!peutJouer(mainJoueur1, tailleMainJ1, tableau) && !peutJouer(mainJoueur2, tailleMainJ2, tableau)) {
        printf("Aucun joueur ne peut plus jouer. Fin de la partie.\n");
        return true;
    }
    return false;
}

// Calculates the score for a specific player by adding the strength of the cards he played
int calculerScoreJoueur(Carte tableau[LIGNES][COLONNES], int joueurNum) {
    int score = 0;
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            if (tableau[i][j].joueur == joueurNum) {
                score += tableau[i][j].force;
            }
        }
    }
    return score;
}

// Shows final results and determines winner
void afficherResultats(Carte tableau[LIGNES][COLONNES]) {
    int scoreJoueur1 = calculerScoreJoueur(tableau, 1);
    int scoreJoueur2 = calculerScoreJoueur(tableau, 2);
    printf("Fin de la partie !\n");
    printf("Score Joueur 1 : %d\n", scoreJoueur1);
    printf("Score Joueur 2 : %d\n", scoreJoueur2);

    if (scoreJoueur1 > scoreJoueur2) {
        printf("Le Joueur 1 gagne !\n");
    } else if (scoreJoueur1 < scoreJoueur2) {
        printf("Le Joueur 2 gagne !\n");
    } else {
        printf("Égalité !\n");
    }
}

// Checks if a card can be placed on the board according to the rules of the game
int peutPlacerCarte(Carte tableau[LIGNES][COLONNES], int ligne, int colonne, Niveau niveau) {
    if (ligne < 0 || ligne >= LIGNES || colonne < 0 || colonne >= COLONNES) return 0;
    if (tableau[ligne][colonne].force != 0) return 0;  // Case déjà occupée

    // Checks the level required to place the card
    if (niveau == NIVEAU_1) return (ligne == 0);
    if (niveau == NIVEAU_2) return (ligne == 1 && tableau[ligne - 1][colonne].niveau == NIVEAU_1);
    if (niveau == NIVEAU_3) return (ligne == 2 && tableau[ligne - 1][colonne].niveau == NIVEAU_2);
    return 0;
}

// Checks if a player can still play a card in their hand on the board
int peutJouer(Carte main[], int tailleMain, Carte tableau[LIGNES][COLONNES]) {
    for (int i = 0; i < tailleMain; i++) {
        for (int ligne = 0; ligne < LIGNES; ligne++) {
            for (int colonne = 0; colonne < COLONNES; colonne++) {
                if (peutPlacerCarte(tableau, ligne, colonne, main[i].niveau)) {
                    return 1;  // Valid placement is possible
                }
            }
        }
    }
    return 0;  // No valid placement possible
}
