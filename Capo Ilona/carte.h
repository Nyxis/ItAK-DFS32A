#ifndef TP_CARTES
    #define TP_CARTES
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    typedef enum {Niveau_1 = 1, Niveau_2, Niveau_3} Niveau;
    typedef enum {Force_2 = 2, Force_3, Force_4, Force_5, Force_6, Force_10} Force;
    typedef enum {blanc, gris, noir, bleu, orange, rouge, violet, rose, jaune, vert} Couleur;

    typedef void (*Fct)(void);

    typedef struct Carte {
        Niveau niveau;
        Couleur couleur;
        Force force;
        Fct fct;
    } Carte;

    typedef struct Joueur {
        Carte cartes_j[3][5];
        Carte carte_j[5];
        int score;
    } Joueur;

void show_tab(Joueur *joueur);
void show_carte(const Carte *carte);
void show_carte_played(Joueur *joueur);
Carte *set_carte(Niveau niveau, Couleur couleur, Force force);
Joueur *set_joueur();
Joueur *give_cards(Joueur *joueur);
void free_joueur(Joueur *joueur);
int can_play(const Joueur *joueur, const Carte *carte, int row, int col);
void play_time(Joueur *joueur, int index, Carte map[3][5]);
void tourJoueur(Joueur *joueur, Carte map[3][5]);



#endif /* !TP_CARTES */
