#include "carte.h"

Carte *set_carte(Niveau niveau, Couleur couleur, Force force) {
    Carte *carte = (Carte*)malloc(sizeof(Carte) + 1);
    if (carte != NULL) {
        carte->niveau = niveau;
        carte->couleur = couleur;
        carte->force = force;
    }
    return carte;
}

