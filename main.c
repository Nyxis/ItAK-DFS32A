#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // pour utiliser bool, true, et false


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
int peutPlacerCarte(Carte tableau[LIGNES][COLONNES], int ligne, int colonne, Niveau niveau) {
    // Vérifie les limites du tableau pour éviter tout dépassement d'indice
    if (ligne < 0 || ligne >= LIGNES || colonne < 0 || colonne >= COLONNES) {
        return 0; // Emplacement hors du tableau
    }

    // Vérifie si l'emplacement est déjà occupé
    if (tableau[ligne][colonne].force != 0) {
        return 0; // Emplacement occupé
    }

    // Règles spécifiques selon le niveau de la carte
    if (niveau == NIVEAU_1) {
        // Niveau 1 : Doit être placé sur la première ligne
        if (ligne == 0) {
            return 1;
        } else {
            return 0;
        }
    } else if (niveau == NIVEAU_2) {
        // Niveau 2 : Doit être placé sur la deuxième ligne et nécessite une carte de Niveau 1 juste en dessous
        if (ligne == 1 && tableau[ligne - 1][colonne].niveau == NIVEAU_1) {
            return 1;
        } else {
            return 0;
        }
    } else if (niveau == NIVEAU_3) {
        // Niveau 3 : Doit être placé sur la troisième ligne et nécessite une carte de Niveau 2 juste en dessous
        if (ligne == 2 && tableau[ligne - 1][colonne].niveau == NIVEAU_2) {
            return 1;
        } else {
            return 0;
        }
    }

    return 0; // Par défaut, placement invalide
}
int calculerScore(Carte tableau[LIGNES][COLONNES]) {
    int score = 0;
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            score += tableau[i][j].force; // Additionne la force des cartes présentes
        }
    }
    return score;
}


int main() {
    Carte tableau[LIGNES][COLONNES] = {{{0}}};
    Carte mainJoueur1[] = {{NIVEAU_1, ROUGE, FORCE_3}, {NIVEAU_2, BLEU, FORCE_5}};
    Carte mainJoueur2[] = {{NIVEAU_1, NOIR, FORCE_4}, {NIVEAU_3, VERT, FORCE_10}};
    int tailleMainJ1 = 2, tailleMainJ2 = 2;
    int toursRestantsJoueur2 = 3; // Compteur pour les 3 tours supplémentaires du deuxième joueur

    bool jeuEnCours = true;
    int joueurActuel = 1;

    while (jeuEnCours) {
        if (joueurActuel == 1 && tailleMainJ1 > 0) {
            printf("Joueur 1, votre tour.\n");
            int choixCarte = choisirCarte(mainJoueur1, tailleMainJ1);
            if (choixCarte != -1) {
                int ligne, colonne;
                choisirEmplacement(&ligne, &colonne);

                if (peutPlacerCarte(tableau, ligne, colonne, mainJoueur1[choixCarte].niveau)) {
                    tableau[ligne][colonne] = mainJoueur1[choixCarte];
                    printf("Carte placée avec succès.\n");

                    // Supprime la carte de la main du joueur
                    for (int i = choixCarte; i < tailleMainJ1 - 1; i++) {
                        mainJoueur1[i] = mainJoueur1[i + 1];
                    }
                    tailleMainJ1--;
                } else {
                    printf("Placement invalide. Veuillez essayer à nouveau.\n");
                    continue;
                }
            } else {
                printf("Joueur 1 a passé son tour.\n");
                jeuEnCours = false; // Fin du tour si le joueur ne peut plus jouer
                continue;
            }
            joueurActuel = 2;
        } else if (joueurActuel == 2 && toursRestantsJoueur2 > 0 && tailleMainJ2 > 0) {
            printf("Joueur 2, votre tour (%d tours restants).\n", toursRestantsJoueur2);
            int choixCarte = choisirCarte(mainJoueur2, tailleMainJ2);
            if (choixCarte != -1) {
                int ligne, colonne;
                choisirEmplacement(&ligne, &colonne);

                if (peutPlacerCarte(tableau, ligne, colonne, mainJoueur2[choixCarte].niveau)) {
                    tableau[ligne][colonne] = mainJoueur2[choixCarte];
                    printf("Carte placée avec succès.\n");

                    // Supprime la carte de la main du joueur
                    for (int i = choixCarte; i < tailleMainJ2 - 1; i++) {
                        mainJoueur2[i] = mainJoueur2[i + 1];
                    }
                    tailleMainJ2--;
                } else {
                    printf("Placement invalide. Veuillez essayer à nouveau.\n");
                    continue;
                }
            } else {
                printf("Joueur 2 a passé son tour.\n");
            }
            toursRestantsJoueur2--;
            joueurActuel = 1;
        } else {
            jeuEnCours = false;
        }
    }

    // Calcul des scores et annonce du gagnant
    int scoreJoueur1 = calculerScore(tableau);
    int scoreJoueur2 = calculerScore(tableau); // On pourrait ici calculer en séparant par joueur

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

    return 0;
}

