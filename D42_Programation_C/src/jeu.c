#include "jeu.h"
#include "utils.h"

void initialiser_joueur(Joueur *joueur) {

    for (int i = 0; i < NB_CARTES_MAIN; i++) {
        joueur->main[i].niveau = NIVEAU_1;
        joueur->main[i].couleur = BLANC;
        joueur->main[i].force = FORCE_2;
    }

    for (int i = 0; i < NB_CARTES_TABLEAU; i++) {
        joueur->tableau[i].niveau = NIVEAU_1;
        joueur->tableau[i].couleur = BLANC;
        joueur->tableau[i].force = FORCE_2;
    }

    joueur->score = 0;
}

void afficher_etat_partie(Joueur joueur1, Joueur joueur2) {

    printf("Joueur 1:\n");
    printf("Main: ");

        for (int i = 0; i < NB_CARTES_MAIN; i++) {
            afficher_carte(joueur1.main[i]);
            printf(" ");

        }
    printf("\nTableau:\n");

        for (int i = 0; i < NB_CARTES_TABLEAU; i++) {
            afficher_carte(joueur1.tableau[i]);
            printf(" ");
            if ((i + 1) % 5 == 0) printf("\n");
        }
    printf("Score: %d\n", joueur1.score);


    printf("\nJoueur 2:\n");
  

    printf("Main: ");
        for (int i = 0; i < NB_CARTES_MAIN; i++) {
            afficher_carte(joueur2.main[i]);
            printf(" ");
        }


    printf("\nTableau:\n");
        for (int i = 0; i < NB_CARTES_TABLEAU; i++) {
            afficher_carte(joueur2.tableau[i]);
            printf(" ");
            if ((i + 1) % 5 == 0) printf("\n");
        }


    printf("Score: %d\n", joueur2.score);
}


int jouer_carte(Joueur *joueur, int index_carte) {

    if (index_carte < 0 || index_carte >= NB_CARTES_MAIN) {
        return 0; 
    }


    Carte carte = joueur->main[index_carte];
    int ligne = carte.niveau;
    int colonne = saisir_entier("Entrez la colonne où jouer la carte: ");


    if (colonne < 0 || colonne >= 5) {
        return 0; 
    }


    int index_tableau = ligne * 5 + colonne;
    if (joueur->tableau[index_tableau].niveau != NIVEAU_1) {
        return 0; 
    }


    if (ligne > 0 && joueur->tableau[index_tableau - 5].niveau != ligne - 1) {
        return 0; 
    }

    joueur->tableau[index_tableau] = carte;

    joueur->main[index_carte] = joueur->main[NB_CARTES_MAIN - 1];
    joueur->main[NB_CARTES_MAIN - 1].niveau = NIVEAU_1;
    joueur->main[NB_CARTES_MAIN - 1].couleur = BLANC;
    joueur->main[NB_CARTES_MAIN - 1].force = FORCE_2;

    return 1;
}



void calculer_score(Joueur *joueur) {
    joueur->score = 0;
    for (int i = 0; i < NB_CARTES_TABLEAU; i++) {
        joueur->score += joueur->tableau[i].force + 2;
    }
}

void piocher_carte(Joueur *joueur, Carte *pioche, int *index_pioche) {
    if (*index_pioche < 0) return;
    joueur->main[NB_CARTES_MAIN - 1] = pioche[*index_pioche];
    (*index_pioche)--;
}
