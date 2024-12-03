#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

typedef enum {
    NIVEAU_1,
    NIVEAU_2,
    NIVEAU_3
} Niveau;

typedef enum {
    FORCE_2,
    FORCE_3,
    FORCE_4,
    FORCE_5,
    FORCE_6,
    FORCE_10
} Force;

typedef struct {
    Niveau niveau;
    Couleur couleur;
    Force force;
    void (*action)(void);
} Carte;

typedef struct {
    Carte cartes[15];
    int nbCartes;
} Tableau;

typedef struct {
    Carte main[10];
    int nbCartesMain;
    Tableau tableau;
} Joueur;

const char* couleurToString(Couleur couleur) {
    const char* couleurs[] = {"blanc", "gris", "noir", "bleu", "orange", "rouge", "violet", "rose", "jaune", "vert"};
    return couleurs[couleur];
}

const char* niveauToString(Niveau niveau) {
    const char* niveaux[] = {"1", "2", "3"};
    return niveaux[niveau];
}

const char* forceToString(Force force) {
    const char* forces[] = {"2", "3", "4", "5", "6", "10"};
    return forces[force];
}

void afficherCarte(Carte carte) {
    printf("%s-%s-%s", niveauToString(carte.niveau), couleurToString(carte.couleur), forceToString(carte.force));
}

void afficherTableau(Tableau tableau) {
    for (int i = 0; i < 15; i++) {
        if (i % 5 == 0) printf("\n");
        if (tableau.cartes[i].niveau == -1) {
            printf("---- ");
        } else {
            afficherCarte(tableau.cartes[i]);
            printf(" ");
        }
    }
    printf("\n");
}

void afficherMain(Joueur joueur) {
    printf("Main du joueur:\n");
    for (int i = 0; i < joueur.nbCartesMain; i++) {
        afficherCarte(joueur.main[i]);
        printf(" ");
    }
    printf("\n");
}

void afficherEtatPartie(Joueur joueur1, Joueur joueur2) {
    printf("Tableau du joueur 1:\n");
    afficherTableau(joueur1.tableau);
    printf("Tableau du joueur 2:\n");
    afficherTableau(joueur2.tableau);
    afficherMain(joueur1);
    afficherMain(joueur2);
}

int peutJouerCarte(Tableau tableau, Carte carte, int position) {
    if (carte.niveau == NIVEAU_1 && position >= 0 && position < 5) {
        return 1;
    } else if (carte.niveau == NIVEAU_2 && position >= 5 && position < 10) {
        return tableau.cartes[position - 5].niveau == NIVEAU_1;
    } else if (carte.niveau == NIVEAU_3 && position >= 10 && position < 15) {
        return tableau.cartes[position - 5].niveau == NIVEAU_2;
    }
    return 0;
}

void jouerCarte(Joueur* joueur, int indexCarte, int position) {
    Carte carte = joueur->main[indexCarte];
    if (peutJouerCarte(joueur->tableau, carte, position)) {
        joueur->tableau.cartes[position] = carte;
        joueur->tableau.nbCartes++;
        for (int i = indexCarte; i < joueur->nbCartesMain - 1; i++) {
            joueur->main[i] = joueur->main[i + 1];
        }
        joueur->nbCartesMain--;
        if (carte.action) {
            carte.action();
        }
    } else {
        printf("Carte ne peut pas être jouée à cette position.\n");
    }
}

void initialiserCarte(Carte* carte, Niveau niveau, Couleur couleur, Force force, void (*action)(void)) {
    carte->niveau = niveau;
    carte->couleur = couleur;
    carte->force = force;
    carte->action = action;
}

void initialiserTableau(Tableau* tableau) {
    tableau->nbCartes = 0;
    for (int i = 0; i < 15; i++) {
        tableau->cartes[i].niveau = -1;
    }
}

void initialiserJoueur(Joueur* joueur) {
    joueur->nbCartesMain = 0;
    initialiserTableau(&joueur->tableau);
}

void piocherCarte(Joueur* joueur, Carte carte) {
    joueur->main[joueur->nbCartesMain++] = carte;
}

void actionCarte(void) {
    printf("Action de la carte exécutée.\n");
}

int main() {
    srand(time(NULL));

    Joueur joueur1, joueur2;
    initialiserJoueur(&joueur1);
    initialiserJoueur(&joueur2);

    Carte cartes[20];
    for (int i = 0; i < 20; i++) {
        initialiserCarte(&cartes[i], rand() % 3, rand() % 10, rand() % 6, actionCarte);
    }

    for (int i = 0; i < 10; i++) {
        piocherCarte(&joueur1, cartes[i]);
        piocherCarte(&joueur2, cartes[i + 10]);
    }

    int tour = 0;
    Joueur* joueurCourant = &joueur1;

    while (1) {
        afficherEtatPartie(joueur1, joueur2);
        int indexCarte, position;
        printf("Joueur %d, choisissez une carte à jouer (-1 pour passer): ", tour % 2 + 1);
        scanf("%d", &indexCarte);
        if (indexCarte == -1) {
            joueurCourant = (joueurCourant == &joueur1) ? &joueur2 : &joueur1;
            tour++;
            continue;
        }
        printf("Choisissez la position (0-14): ");
        scanf("%d", &position);
        jouerCarte(joueurCourant, indexCarte, position);
        joueurCourant = (joueurCourant == &joueur1) ? &joueur2 : &joueur1;
        tour++;
    }

    return 0;
}
