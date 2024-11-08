#include <stdio.h>

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

//
// Viewing function for a cards
void afficherCarte(Carte carte) {
    const char *couleurs[] = {"Blanc", "Gris", "Noir", "Bleu", "Orange", "Rouge", "Violet", "Rose", "Jaune", "Vert"};
    printf("Niveau: %d, Couleur: %s, Force: %d\n", carte.niveau, couleurs[carte.couleur], carte.force);
}

int main() {
    // Creation of some maps to test
    Carte carte1 = {NIVEAU_1, ROUGE, FORCE_3};
    Carte carte2 = {NIVEAU_2, BLEU, FORCE_5};
    Carte carte3 = {NIVEAU_3, VERT, FORCE_10};

    // Viewing cards
    afficherCarte(carte1);
    afficherCarte(carte2);
    afficherCarte(carte3);

    return 0;
}