#include "carte.h"

int main()
{
    srand(time(NULL));
    
    Joueur *joueur1 = set_joueur(joueur1), *joueur2 = set_joueur(joueur2);
    /*joueur1 = give_cards(joueur1);
    joueur2 = give_cards(joueur2);*/
    //Carte map[3][5];

    printf("Début de la partie !\n");

    int toursSansAction = 0, joueurActuel = 1;
    while (toursSansAction < 3) {
        printf("\nTour du Joueur %d\n", joueurActuel);
        show_tab(joueurActuel == 1 ? joueur1 : joueur2);
        
        if (joueurActuel == 1) {
            tourJoueur(joueur1, map);
            joueurActuel = 2;
        } else {
            tourJoueur(joueur2, map);
            joueurActuel = 1;
        }
        toursSansAction++;
    }

    printf("\nFin de la partie!\n");
    printf("Score Joueur 1: %d\n", joueur1->score);
    printf("Score Joueur 2: %d\n", joueur2->score);

    if (joueur1->score > joueur2->score) 
        printf("Joueur 1 gagne!\n");
    else if (joueur2->score > joueur1->score) 
        printf("Joueur 2 gagne!\n");
    else 
        printf("Égalité!\n");

    return 0;
}