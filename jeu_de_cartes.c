#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARDS 15
#define HAND_SIZE 5

// Enum pour le niveau
typedef enum {
    NIVEAU_1 = 1,
    NIVEAU_2,
    NIVEAU_3
} Niveau;

// Enum pour la couleur
typedef enum {
    BLANC,
    GRIS,
    NOIR,
    BLEU,
    ORANGE,
    ROUGE,
    VIOLET,
    ROSE,
    JAUNE,
    VERT,
    COULEUR_NOMBRE // Pour obtenir la taille de l'énum
} Couleur;

// Enum pour la force
typedef enum {
    FORCE_2 = 2,
    FORCE_3,
    FORCE_4,
    FORCE_5,
    FORCE_6,
    FORCE_10,
    FORCE_NOMBRE // Pour obtenir la taille de l'énum
} Force;

// Structure représentant une carte
typedef struct {
    Niveau niveau;
    Couleur couleur;
    Force force;
} Carte;

// Structure représentant un joueur
typedef struct {
    Carte main[HAND_SIZE];
    int nombreCartes;
    Carte tableau[MAX_CARDS]; // 3 lignes x 5 colonnes
    int tableauOccupé[3][5];  // Indique si la case est occupée
} Joueur;

// Prototypes de fonctions
void initJoueur(Joueur* joueur);
void afficherEtat(Joueur* joueur1, Joueur* joueur2);
int jouerCarte(Joueur* joueur, int indexCarte);
void piocherCarte(Joueur* joueur);
int cartePeutEtreJouée(Carte carte, Joueur* joueur);
void afficherCarte(Carte carte);
void afficherTableau(Joueur* joueur);
int calculerForce(Joueur* joueur);
void afficherNomCouleur(Couleur couleur);
void afficherNomForce(Force force);

int main() {
    Joueur joueur1, joueur2;
    int tour = 0;
    int joueurActuel = 0; // 0 pour joueur1, 1 pour joueur2

    initJoueur(&joueur1);
    initJoueur(&joueur2);

    while (1) {
        Joueur* joueur = (joueurActuel == 0) ? &joueur1 : &joueur2;
        printf("\n--- Tour %d (Joueur %d) ---\n", tour + 1, joueurActuel + 1);
        piocherCarte(joueur);
        afficherEtat(&joueur1, &joueur2);

        int indexCarte = -1;
        printf("Choisissez une carte à jouer (0 à %d) ou entrez -1 pour passer: ", joueur->nombreCartes - 1);
        scanf("%d", &indexCarte);

        if (indexCarte == -1) {
            // Si le joueur passe
            printf("Le joueur %d passe son tour.\n", joueurActuel + 1);
        } else if (indexCarte >= 0 && indexCarte < joueur->nombreCartes) {
            // Si le joueur essaie de jouer une carte
            if (jouerCarte(joueur, indexCarte)) {
                printf("Carte jouee avec succes.\n");
            } else {
                printf("Impossible de jouer cette carte.\n");
            }
        } else {
            printf("Entree invalide, veuillez reessayer.\n");
        }

        // Changer de joueur
        joueurActuel = (joueurActuel + 1) % 2;
        tour++;

        // Fin du jeu si un joueur ne peut plus jouer
        if (tour >= 3 && joueurActuel == 0) {
            break;
        }
    }

    // Calcul et affichage des scores
    int scoreJoueur1 = calculerForce(&joueur1);
    int scoreJoueur2 = calculerForce(&joueur2);
    printf("\n--- Fin du jeu ---\n");
    printf("Score Joueur 1: %d\n", scoreJoueur1);
    printf("Score Joueur 2: %d\n", scoreJoueur2);

    if (scoreJoueur1 > scoreJoueur2) {
        printf("Le Joueur 1 gagne !\n");
    } else if (scoreJoueur1 < scoreJoueur2) {
        printf("Le Joueur 2 gagne !\n");
    } else {
        printf("Match nul !\n");
    }

    return 0;
}

void initJoueur(Joueur* joueur) {
    joueur->nombreCartes = 0;
    memset(joueur->tableauOccupé, 0, sizeof(joueur->tableauOccupé));
}

void afficherNomCouleur(Couleur couleur) {
    const char* nomsCouleur[] = {"Blanc", "Gris", "Noir", "Bleu", "Orange", "Rouge", "Violet", "Rose", "Jaune", "Vert"};
    printf("%s", nomsCouleur[couleur]);
}

void afficherNomForce(Force force) {
    printf("%d", force);
}

void afficherCarte(Carte carte) {
    afficherNomCouleur(carte.couleur);
    printf(" - Niveau %d - Force %d", carte.niveau, carte.force);
}

void afficherTableau(Joueur* joueur) {
    printf("\nTableau:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            if (joueur->tableauOccupé[i][j]) {
                afficherCarte(joueur->tableau[i * 5 + j]);
            } else {
                printf("Vide");
            }
            printf("\t");
        }
        printf("\n");
    }
}

void afficherEtat(Joueur* joueur1, Joueur* joueur2) {
    printf("\n--- État du jeu ---\n");
    printf("Joueur 1:\n");
    for (int i = 0; i < joueur1->nombreCartes; i++) {
        afficherCarte(joueur1->main[i]);
        printf("\n");
    }
    afficherTableau(joueur1);
    printf("\nJoueur 2:\n");
    for (int i = 0; i < joueur2->nombreCartes; i++) {
        afficherCarte(joueur2->main[i]);
        printf("\n");
    }
    afficherTableau(joueur2);
}

void piocherCarte(Joueur* joueur) {
    if (joueur->nombreCartes < HAND_SIZE) {
        // Création d'une nouvelle carte
        Carte nouvelleCarte;
        nouvelleCarte.niveau = rand() % 3 + 1; // Niveaux entre 1 et 3
        nouvelleCarte.couleur = rand() % COULEUR_NOMBRE; // Couleurs
        nouvelleCarte.force = (rand() % 5 + 1) * 2; // Forces entre 2, 3, 4, 5, 6, 10
        joueur->main[joueur->nombreCartes++] = nouvelleCarte;
    }
}

int cartePeutEtreJouée(Carte carte, Joueur* joueur) {
    int ligne = carte.niveau - 1;
    if (ligne >= 3) return 0; // Niveau invalide

    // Vérifier si la case est occupée
    if (joueur->tableauOccupé[ligne][0] || joueur->tableauOccupé[ligne][1] ||
        joueur->tableauOccupé[ligne][2] || joueur->tableauOccupé[ligne][3] ||
        joueur->tableauOccupé[ligne][4]) {
        return 1; // Une carte peut être jouée ici
    }

    // Vérifier si une carte du niveau inférieur est directement en dessous
    if (carte.niveau > 1) {
        if (joueur->tableauOccupé[ligne - 1][0] || joueur->tableauOccupé[ligne - 1][1] ||
            joueur->tableauOccupé[ligne - 1][2] || joueur->tableauOccupé[ligne - 1][3] ||
            joueur->tableauOccupé[ligne - 1][4]) {
            return 1;
        }
    }

    return 0; // Impossible de jouer
}

int jouerCarte(Joueur* joueur, int indexCarte) {
    Carte carte = joueur->main[indexCarte];
    if (cartePeutEtreJouée(carte, joueur)) {
        // Placer la carte dans le tableau
        for (int j = 0; j < 5; j++) {
            if (!joueur->tableauOccupé[carte.niveau - 1][j]) {
                joueur->tableau[carte.niveau - 1 * 5 + j] = carte;
                joueur->tableauOccupé[carte.niveau - 1][j] = 1;
                break;
            }
        }
        // Retirer la carte de la main
        for (int i = indexCarte; i < joueur->nombreCartes - 1; i++) {
            joueur->main[i] = joueur->main[i + 1];
        }
        joueur->nombreCartes--;
        return 1; // Carte jouée avec succès
    }
    return 0; // Impossible de jouer
}

int calculerForce(Joueur* joueur) {
    int forceTotale = 0;
    for (int i = 0; i < MAX_CARDS; i++) {
        if (joueur->tableau[i].niveau > 0) { // Si la carte est jouée
            forceTotale += joueur->tableau[i].force;
        }
    }
    return forceTotale;
}
