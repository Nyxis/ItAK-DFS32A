#include <stdio.h>
#include <stdlib.h>

#define LIGNES 3
#define COLONNES 5

// Définition des niveaux, couleurs et forces
typedef enum { NIVEAU_1 = 1, NIVEAU_2, NIVEAU_3 } Niveau;
typedef enum { BLANC, GRIS, NOIR, BLEU, ORANGE, ROUGE, VIOLET, ROSE, JAUNE, VERT } Couleur;
typedef enum { FORCE_2 = 2, FORCE_3, FORCE_4, FORCE_5, FORCE_6, FORCE_10 } Force;

typedef struct {
    Niveau niveau;
    Couleur couleur;
    Force force;
} Carte;

// Affiche une carte
void afficherCarte(Carte carte) {
    const char *couleurs[] = {"Blanc", "Gris", "Noir", "Bleu", "Orange", "Rouge", "Violet", "Rose", "Jaune", "Vert"};
    printf("Niveau: %d, Couleur: %s, Force: %d\n", carte.niveau, couleurs[carte.couleur], carte.force);
}

// Affiche la main d'un joueur
int choisirCarte(Carte main[], int tailleMain) {
    char input[10];
    int choix = -1;

    printf("Votre main actuelle :\n");
    for (int i = 0; i < tailleMain; i++) {
        printf("%d: ", i + 1); // Affichage de l’index à partir de 1
        afficherCarte(main[i]);
    }

    printf("Choisissez une carte dans votre main (1 à %d) ou -1 pour passer : ", tailleMain);
    if (fgets(input, sizeof(input), stdin) != NULL) {
        choix = atoi(input);
    }

    if (choix >= 1 && choix <= tailleMain) {
        return choix - 1; // Convertit en index de tableau
    } else {
        return -1;
    }
}

// Choix de niveau et colonne
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

int main() {
    Carte tableau[LIGNES][COLONNES] = {{{0}}};
    Carte mainJoueur1[] = {{NIVEAU_1, ROUGE, FORCE_3}, {NIVEAU_2, BLEU, FORCE_5}};
    int tailleMainJ1 = 2;

    int choixCarte = choisirCarte(mainJoueur1, tailleMainJ1);
    if (choixCarte != -1) {
        int ligne, colonne;
        choisirEmplacement(&ligne, &colonne);
        printf("Vous avez choisi la carte %d et l'emplacement niveaux %d colonne %d\n", choixCarte + 1, ligne + 1, colonne + 1);
    } else {
        printf("Tour passé.\n");
    }

    return 0;
}