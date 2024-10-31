#ifndef CARTE_H
#define CARTE_H

typedef enum {
    NIVEAU_1 = 1,
    NIVEAU_2,
    NIVEAU_3
} Niveau;

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
    VERT
} Couleur;

typedef struct {
    Niveau niveau;
    Couleur couleur;
    int force;
} Carte;

void afficherCarte(Carte carte); // Déclaration de la fonction

#endif // CARTE_H
