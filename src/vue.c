#include <stdio.h>
#include "vue.h"
#include "carte.h"

void afficher_carte(Carte carte) {
    if (carte.niveau == 0) {
        printf("[Vide]\t");
    } else {
        printf("[%s-%s-%d]\t", obtenir_niveau_carte(carte.niveau), obtenir_couleur_carte(carte.couleur), carte.force);
    }
}

void afficher_main(Joueur* joueur) {
    printf("\nMain de %s :\n", joueur->nom);
    for (int i = 0; i < joueur->nombre_cartes_main; i++) {
        printf("  [%d] ", i);
        afficher_carte(joueur->main[i]);
        printf("\n");
    }
    if (joueur->nombre_cartes_main == 0) {
        printf("  [Vide]\n");
    }
}

void afficher_tableau(Joueur* joueur) {
    printf("Tableau de %s :\n", joueur->nom);
    for (int i = 0; i < LIGNES; i++) {
        printf("  Ligne %d: ", i + 1);
        for (int j = 0; j < COLONNES; j++) {
            afficher_carte(joueur->tableau[i][j]);
        }
        printf("\n");
    }
}

void afficher_etat_jeu(Joueur* joueur) {
    afficher_main(joueur);
    afficher_tableau(joueur);
    printf("\n");
}