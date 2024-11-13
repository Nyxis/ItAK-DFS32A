#include <stdio.h>
#include <stdbool.h>
#include "interface.h"
#include "jeu.h"
#include "carte.h"

int main() {
    Carte tableau[LIGNES][COLONNES];
    Carte mainJoueur1[NB_CARTES_MAIN];
    Carte mainJoueur2[NB_CARTES_MAIN];

    initialiserPartie(mainJoueur1, mainJoueur2, tableau);

    int tailleMainJ1 = NB_CARTES_MAIN, tailleMainJ2 = NB_CARTES_MAIN;
    int passesTurnCountJ1 = 0, passesTurnCountJ2 = 0;
    bool jeuEnCours = true;
    int joueurActuel = 1;

    while (jeuEnCours) {
        afficherTableau(tableau);

        if (joueurActuel == 1) {
            tourDeJoueur(mainJoueur1, &tailleMainJ1, tableau, 1, &passesTurnCountJ1);
            joueurActuel = 2;
        } else {
            tourDeJoueur(mainJoueur2, &tailleMainJ2, tableau, 2, &passesTurnCountJ2);
            joueurActuel = 1;
        }

        jeuEnCours = !verifierFinPartie(passesTurnCountJ1, passesTurnCountJ2, mainJoueur1, tailleMainJ1, mainJoueur2, tailleMainJ2, tableau);
    }

    afficherResultats(tableau);

    return 0;
}
