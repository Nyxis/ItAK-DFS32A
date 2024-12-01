#ifndef TP_CARTES
    #define TP_CARTES
    #include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIGNES 3
#define COLONNES 5
#define MAIN_MAX 5

typedef enum {
    NIVEAU_1 = 1,
    NIVEAU_2,
    NIVEAU_3
} Niveau;

typedef enum {
    BLANC, GRIS, NOIR, BLEU, ORANGE, ROUGE, VIOLET, ROSE, JAUNE, VERT
} Couleur;

typedef enum {
    FORCE_2 = 2, FORCE_3, FORCE_4, FORCE_5, FORCE_6, FORCE_10 = 10
} Force;

typedef struct {
    Niveau niveau;
    Couleur couleur;
    Force force;
} Carte;


int can_be_played(Carte tableau[LIGNES][COLONNES], int row, int col);
int place_carte(Carte tableau[LIGNES][COLONNES], Carte carte);
int calcul_force(Carte tableau[LIGNES][COLONNES]);
void tour_joueur(Carte tableau[LIGNES][COLONNES], Carte main[], int* taille_main);
void show_hand(Carte main[], int taille);
void show_tab(Carte tableau[LIGNES][COLONNES]);
void show_carte(Carte carte);
void set_tab(Carte tableau[LIGNES][COLONNES]);
Carte set_carte();


#endif /* !TP_CARTES */
