#ifndef CARTE_H
#define CARTE_H

typedef enum {
    NIVEAU_1 = 1,
    NIVEAU_2,
    NIVEAU_3
} NiveauCarte;

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
    NOMBRE_COULEURS
} CouleurCarte;

typedef enum {
    FORCE_2 = 2,
    FORCE_3,
    FORCE_4,
    FORCE_5,
    FORCE_6,
    FORCE_10 = 10
} ForceCarte;

typedef struct {
    NiveauCarte niveau;
    CouleurCarte couleur;
    ForceCarte force;
} Carte;

void initialiser_carte(Carte* carte, NiveauCarte niveau, CouleurCarte couleur, ForceCarte force);
void generer_carte_aleatoire(Carte* carte);
const char* obtenir_couleur_carte(CouleurCarte couleur);
const char* obtenir_niveau_carte(NiveauCarte niveau);

#endif
