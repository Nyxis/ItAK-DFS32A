#include <stdio.h>
#include <stdlib.h>  // pour rand(), srand() et atoi()
#include <time.h>    // pour time()#include <stdbool.h> // pour utiliser bool, true, et false
#include <stdbool.h> // pour utiliser bool, true, et false


#define LIGNES 3
#define COLONNES 5
#define NB_CARTES_MAIN 2  // Nombre de cartes par main

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

void afficherTableau(Carte tableau[LIGNES][COLONNES]) {
    printf("\nÉtat actuel du tableau :\n");
    for (int i = 0; i < LIGNES; i++) {
        for (int j = 0; j < COLONNES; j++) {
            if (tableau[i][j].force != 0) { // Si une carte est présente
                printf("N%d-F%d ", tableau[i][j].niveau, tableau[i][j].force);
            } else {
                printf("[Empty] ");
            }
        }
        printf("\n");
    }
    printf("\n");
}
// Fonction pour générer une carte aléatoire
Carte genererCarteAleatoire() {
    Carte carte;
    carte.niveau = (Niveau)(rand() % 3 + 1);            // Niveaux 1, 2 ou 3
    carte.couleur = (Couleur)(rand() % 10);             // Couleurs 0 à 9 (correspondant aux couleurs définies)
    carte.force = (Force)((rand() % 5) * 2 + 2);        // Force parmi {2, 4, 6, 8, 10}
    return carte;
}

// Générer les mains des joueurs avec des cartes aléatoires
void genererMain(Carte main[], int tailleMain) {
    for (int i = 0; i < tailleMain; i++) {
        main[i] = genererCarteAleatoire();
    }
}
int peutJouer(Carte main[], int tailleMain, Carte tableau[LIGNES][COLONNES]) {
    for (int i = 0; i < tailleMain; i++) {
        for (int ligne = 0; ligne < LIGNES; ligne++) {
            for (int colonne = 0; colonne < COLONNES; colonne++) {
                if (peutPlacerCarte(tableau, ligne, colonne, main[i].niveau)) {
                    return 1; // Le joueur peut jouer cette carte
                }
            }
        }
    }
    return 0; // Aucune carte jouable
}

int main() {
    srand(time(NULL));  // Initialiser le générateur aléatoire

    Carte tableau[LIGNES][COLONNES] = {{{0}}};
    Carte mainJoueur1[NB_CARTES_MAIN];
    Carte mainJoueur2[NB_CARTES_MAIN];

    genererMain(mainJoueur1, NB_CARTES_MAIN);
    genererMain(mainJoueur2, NB_CARTES_MAIN);

    int tailleMainJ1 = NB_CARTES_MAIN, tailleMainJ2 = NB_CARTES_MAIN;
    int toursRestantsJoueur2 = 3;

    bool jeuEnCours = true;
    int joueurActuel = 1;

    while (jeuEnCours) {
        afficherTableau(tableau); // Affiche l’état du tableau au début de chaque tour

        // Vérifie si au moins un des deux joueurs peut jouer
        if (!peutJouer(mainJoueur1, tailleMainJ1, tableau) && !peutJouer(mainJoueur2, tailleMainJ2, tableau)) {
            printf("Aucun joueur ne peut plus jouer. Fin de la partie.\n");
            break;
        }

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

    afficherTableau(tableau); // Affiche l’état final du tableau
    int scoreJoueur1 = calculerScore(tableau);
    int scoreJoueur2 = calculerScore(tableau);

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
