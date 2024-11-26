#include <stdio.h>
#include <stdlib.h>
#include "carte.h"

void initialiser_carte(Carte* carte, NiveauCarte niveau, CouleurCarte couleur, ForceCarte force) {
    if (carte != NULL) {
        carte->niveau = niveau;
        carte->couleur = couleur;
        carte->force = force;
    }
}

void generer_carte_aleatoire(Carte* carte) {
    if (carte != NULL) {
        carte->niveau = (NiveauCarte)((rand() % 3) + 1); 
        carte->couleur = (CouleurCarte)(rand() % NOMBRE_COULEURS);
        int forces[] = {2, 3, 4, 5, 6, 10};
        carte->force = (ForceCarte)(forces[rand() % 6]);
    }
}

const char* obtenir_couleur_carte(CouleurCarte couleur) {
    switch (couleur) {
        case BLANC: return "Blanc";
        case GRIS: return "Gris";
        case NOIR: return "Noir";
        case BLEU: return "Bleu";
        case ORANGE: return "Orange";
        case ROUGE: return "Rouge";
        case VIOLET: return "Violet";
        case ROSE: return "Rose";
        case JAUNE: return "Jaune";
        case VERT: return "Vert";
        default: return "Inconnu";
    }
}

const char* obtenir_niveau_carte(NiveauCarte niveau) {
    switch (niveau) {
        case NIVEAU_1: return "1";
        case NIVEAU_2: return "2";
        case NIVEAU_3: return "3";
        default: return "Inconnu";
    }
}
