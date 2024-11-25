#include "jeu.h"
#include "utils.h"

int main() {
    Joueur joueur1, joueur2;
    initialiser_joueur(&joueur1);
    initialiser_joueur(&joueur2);

    Carte pioche[30]; // Exemple de pioche avec 30 cartes
    int index_pioche = 29;

    // Initialisation de la pioche avec des cartes aléatoires
    for (int i = 0; i < 30; i++) {
        pioche[i].niveau = rand() % 3;
        pioche[i].couleur = rand() % 10;
        pioche[i].force = rand() % 6;
    }

    melanger_cartes(pioche, 30);

    int tour = 0;
    int joueur_actuel = 0;

    while (1) {
        Joueur *joueur = (joueur_actuel == 0) ? &joueur1 : &joueur2;
        afficher_etat_partie(joueur1, joueur2);

        piocher_carte(joueur, pioche, &index_pioche);

        int index_carte = saisir_entier("Entrez l'index de la carte à jouer (-1 pour passer): ");
        if (index_carte == -1) {
            joueur_actuel = 1 - joueur_actuel;
            tour++;
            if (tour >= 3) {
                break;
            }
            continue;
        }

        if (jouer_carte(joueur, index_carte)) {
            joueur_actuel = 1 - joueur_actuel;
            tour = 0;
        } else {
            printf("Carte invalide ou emplacement occupé. Réessayez.\n");
        }
    }

    calculer_score(&joueur1);
    calculer_score(&joueur2);

    afficher_etat_partie(joueur1, joueur2);

    if (joueur1.score > joueur2.score) {
        printf("Joueur 1 gagne!\n");
    } else if (joueur2.score > joueur1.score) {
        printf("Joueur 2 gagne!\n");
    } else {
        printf("Égalité!\n");
    }

    return 0;
}
