#include "carte.h"



Joueur *set_joueur() {
    Joueur *joueur = (Joueur*)malloc(sizeof(Joueur));
    if (joueur != NULL) {
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 5; col++) {
                Niveau niveau = (Niveau)(rand() % 3);  
                Couleur couleur = (Couleur)(rand() % 10);  
                int force = (rand() % 5 + 2) * ((niveau == Niveau_3) ? 2 : 1); 

                Carte *carte = set_carte(niveau, couleur, force);
                if (carte != NULL) {
                    joueur->cartes_j[row][col] = *carte;  
                    free(carte); 
                }
            }
        } 
        
    }
    joueur->score = 0;
    return joueur;
}


Joueur *give_cards(Joueur *joueur) {
    for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 5; col++) {
                Niveau niveau = (Niveau)(rand() % 3);  
                Couleur couleur = (Couleur)(rand() % 10);  
                int force = (rand() % 5 + 2) * ((niveau == Niveau_3) ? 2 : 1); 

                Carte *carte = set_carte(niveau, couleur, force);
                if (carte != NULL) {
                    joueur->cartes_j[row][col] = *carte;  
                    free(carte); 
                }
            }
        }
        joueur->score = 0;
    return joueur;
}

void free_joueur(Joueur *joueur) {
    if (joueur != NULL) {
        free(joueur);
    }
}