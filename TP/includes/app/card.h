#ifndef CREER_CARTE_H_
#define CREER_CARTE_H_

typedef struct
{
    int niveau;
    char *couleur;
    int force;
}Carte;

Carte creerCarte(void);

#endif