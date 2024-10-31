#include <stdio.h>
#include <stdlib.h>
#include "joueur.h"
#include "carte.h"

Carte creerCarte(Niveau niveau, Couleur couleur, int force) {
    Carte carte;
    carte.niveau = niveau;
    carte.couleur = couleur;
    carte.force = force;
    return carte;
}

void afficherInstructions() {
    printf("Instructions:\n");
    printf("1. Choisissez une carte à jouer en entrant son index.\n");
    printf("2. Entrez -1 pour passer votre tour.\n");
    printf("3. Les cartes jouées doivent respecter les règles de placement.\n");
}

int main() {
    Joueur joueur1 = { .nombreCartes = 0 };
    Joueur joueur2 = { .nombreCartes = 0 };

    // Exemples de cartes à piocher
    Carte deck[] = {
        creerCarte(NIVEAU_1, ROUGE, 2),
        creerCarte(NIVEAU_1, BLEU, 3),
        creerCarte(NIVEAU_2, NOIR, 4),
        creerCarte(NIVEAU_3, VERT, 5),
        creerCarte(NIVEAU_2, JAUNE, 6),
        creerCarte(NIVEAU_1, GRIS, 10),
        creerCarte(NIVEAU_3, ORANGE, 3),
        creerCarte(NIVEAU_1, VIOLET, 4),
        creerCarte(NIVEAU_2, ROSE, 5),
        creerCarte(NIVEAU_3, BLANC, 6)
    };

    int tour = 0;
    afficherInstructions();
    while (1) {
        Joueur* joueurActuel = (tour % 2 == 0) ? &joueur1 : &joueur2;
        printf("Tour du Joueur %d\n", (tour % 2) + 1);
        
        // Afficher l'état actuel
        afficherEtat(&joueur1, &joueur2);
        
        // Piocher une carte (pour simplifier, on utilise un deck prédéfini)
        if (joueurActuel->nombreCartes < MAX_CARTES) {
            piocherCarte(joueurActuel, deck[tour % (sizeof(deck) / sizeof(deck[0]))]);
        }
        
        // Demander à l'utilisateur de jouer une carte
        int choix;
        printf("Choisissez une carte (index de 0 à %d) ou entrez -1 pour passer: ", joueurActuel->nombreCartes - 1);
        scanf("%d", &choix);
        
        if (choix == -1) {
            printf("Le joueur passe son tour.\n");
        } else if (choix >= 0 && choix < joueurActuel->nombreCartes) {
            Carte carteChoisie = joueurActuel->cartes[choix];
            if (cartePeutEtreJouee(carteChoisie, joueurActuel->tableau)) {
                int ligne = carteChoisie.niveau - 1;
                for (int j = 0; j < 5; j++) {
                    if (joueurActuel->tableau[ligne][j].niveau == 0) {
                        ajouterCarteAuTableau(carteChoisie, joueurActuel->tableau, ligne, j);
                        printf("Carte jouee: ");
                        afficherCarte(carteChoisie);
                        printf("\n");
                        break;
                    }
                }
            } else {
                printf("La carte ne peut pas etre jouee.\n");
            }
        } else {
            printf("Choix invalide.\n");
        }

        tour++;

        // Logique pour terminer le jeu (ici, on arrête après 10 tours pour l'exemple)
        if (tour >= 10) {
            break;
        }
    }

    printf("Fin du jeu.\n");
    return 0;
}
