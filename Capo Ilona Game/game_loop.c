#include "game_header.h"

int main() {
    srand(time(NULL));
    Carte player1_board[LIGNES][COLONNES];
    Carte player_board[LIGNES][COLONNES];

    set_tab(player1_board);
    set_tab(player_board);

    Carte player1_hand[MAIN_MAX];
    Carte player2_hand[MAIN_MAX];
    int hand1_length = MAIN_MAX;
    int hand2_length = MAIN_MAX;

    for (int i = 0; i < MAIN_MAX; i++) {
        player1_hand[i] = set_carte();
        player2_hand[i] = set_carte();
    }

    int round = 5;
    for (int i = 0; i < round; i++) {
        printf("\n[Tour %d ]\n", i + 1);
        printf("\n- Joueur 1 -\n");
        tour_joueur(player1_board, player1_hand, &hand1_length);

        printf("\n- Joueur 2 -\n");
        tour_joueur(player_board, player2_hand, &hand2_length);
    }

    int force_joueur1 = calcul_force(player1_board);
    int force_joueur2 = calcul_force(player_board);

    if (force_joueur1 != force_joueur2) {
    printf("Le gagnant du jeu est le joueur n°%d", force_joueur1 > force_joueur2 ? 1 : 2 );
    } else {
        printf("Vous êtes à égalité!\n");
    }

    return 0;
}
