#include "carte.h"
#include <stdio.h>
#include <stdlib.h>


void afficherCarte(Carte carte) {
    const char *couleurs[] = {"Blanc", "Gris", "Noir", "Bleu", "Orange", "Rouge", "Violet", "Rose", "Jaune", "Vert"};
    printf("Niveau: %d, Couleur: %s, Force: %d\n", carte.niveau, couleurs[carte.couleur], carte.force);
}

void jouerCarte(Carte *carte) {
    if (carte->onPlay) {
        carte->onPlay(carte);
    }
}

void effetCarte(Carte *carte) {
    printf("La carte %s de niveau %d est jouée avec force %d.\n", carte->name.data, carte->niveau, carte->force);
}

Carte createCarte(Niveau niveau, Couleur couleur, Force force, const char *name, void (*onPlay)(Carte *)) {
    Carte carte;
    carte.niveau = niveau;
    carte.couleur = couleur;
    carte.force = force;
    carte.name = createString(name);
    carte.onPlay = onPlay;
    return carte;
}
