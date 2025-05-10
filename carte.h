#ifndef CARTE_H
#define CARTE_H

#include "string.h"

#define NB_CARTES_MAIN 5  // Number of cards per hand, added here

// Enums and definitions of structures
typedef enum { NIVEAU_1 = 1, NIVEAU_2, NIVEAU_3 } Niveau;
typedef enum { BLANC, GRIS, NOIR, BLEU, ORANGE, ROUGE, VIOLET, ROSE, JAUNE, VERT } Couleur;
typedef enum { FORCE_2 = 2, FORCE_3, FORCE_4, FORCE_5, FORCE_6, FORCE_10 } Force;

typedef struct Carte Carte;

struct Carte {
    Niveau niveau;
    Couleur couleur;
    Force force;
    String name;
    int joueur;  // New field to track which player played the card
    void (*onPlay)(Carte *carte); // Pointer to function called when card is played
};

// Fonctions liées aux cartes
void jouerCarte(Carte *carte);
void effetCarte(Carte *carte);
void afficherCarte(Carte carte);  // Statement added here
Carte createCarte(Niveau niveau, Couleur couleur, Force force, const char *name, void (*onPlay)(Carte *));

#endif // CARTE_H