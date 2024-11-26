#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jeu.h"
#include "vue.h"

void initialiser_jeu(Jeu* jeu) {
    initialiser_joueur(&jeu->joueur1, "Joueur 1");
    initialiser_joueur(&jeu->joueur2, "Joueur 2");
    jeu->indice_pioche = 0;

    for (int i = 0; i < TAILLE_PIOCHE; i++) {
        generer_carte_aleatoire(&jeu->pioche[i]);
    }
    melanger_pioche(jeu->pioche, TAILLE_PIOCHE);
}

void melanger_pioche(Carte* pioche, int taille) {
    for (int i = taille - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Carte temp = pioche[i];
        pioche[i] = pioche[j];
        pioche[j] = temp;
    }
}

void jouer_jeu(Jeu* jeu) {
    srand(time(NULL));
    int tour = 1;
    Joueur* joueur_actuel = &jeu->joueur1;
    Joueur* autre_joueur = &jeu->joueur2;
    int fin_partie = 0;

    while (!fin_partie) {
        printf("=== Tour %d - %s ===\n", tour, joueur_actuel->nom);

        // Piocher une carte
        piocher_carte(joueur_actuel, jeu->pioche, &jeu->indice_pioche);

        // Afficher l'état du jeu
        afficher_etat_jeu(joueur_actuel);

        // Vérifier si le joueur peut jouer
        if (!peut_jouer_carte(joueur_actuel)) {
            printf("%s ne peut plus jouer de cartes.\n", joueur_actuel->nom);
            if (joueur_actuel == &jeu->joueur1) {
                // Passer au deuxième joueur pour 3 tours
                joueur_actuel = &jeu->joueur2;
                autre_joueur = &jeu->joueur1;
            } else {
                // Si le deuxième joueur ne peut pas jouer, terminer le jeu
                fin_partie = 1;
            }
            tour++;
            continue;
        }

        // Demander au joueur de jouer une carte
        int indice_carte_main, ligne, colonne;
        while (1) {
            printf("Entrez l'indice de la carte à jouer (-1 pour passer) : ");
            if (scanf("%d", &indice_carte_main) != 1) {
                // Gestion des entrées invalides
                printf("Entrée invalide. Veuillez entrer un nombre.\n");
                // Vider le buffer d'entrée
                while (getchar() != '\n');
                continue;
            }

            if (indice_carte_main == -1) {
                break;
            }

            printf("Entrez la ligne (1-%d) : ", LIGNES);
            if (scanf("%d", &ligne) != 1 || ligne < 1 || ligne > LIGNES) {
                printf("Entrée invalide pour la ligne.\n");
                while (getchar() != '\n');
                continue;
            }

            printf("Entrez la colonne (1-%d) : ", COLONNES);
            if (scanf("%d", &colonne) != 1 || colonne < 1 || colonne > COLONNES) {
                printf("Entrée invalide pour la colonne.\n");
                while (getchar() != '\n');
                continue;
            }

            // Convertir en indices 0-based
            int ligne_idx = ligne - 1;
            int colonne_idx = colonne - 1;

            if (ajouter_carte_tableau(joueur_actuel, indice_carte_main, ligne_idx, colonne_idx)) {
                printf("Carte jouée avec succès.\n");
                break;
            } else {
                printf("Impossible de jouer cette carte à cet emplacement. Réessayez.\n");
            }
        }

        // Afficher l'état du jeu après le tour
        afficher_etat_jeu(joueur_actuel);

        // Changer de joueur
        Joueur* temp = joueur_actuel;
        joueur_actuel = autre_joueur;
        autre_joueur = temp;
        tour++;

        // Vérifier si la pioche est épuisée
        if (jeu->indice_pioche >= TAILLE_PIOCHE && joueur_actuel->nombre_cartes_main == 0 && autre_joueur->nombre_cartes_main == 0) {
            fin_partie = 1;
        }

        // Gestion des tours restants pour le deuxième joueur
        if (joueur_actuel == &jeu->joueur2 && !peut_jouer_carte(joueur_actuel)) {
            if (joueur_actuel->tours_restants > 0) {
                joueur_actuel->tours_restants--;
                printf("%s ne peut plus jouer de cartes. Tours restants : %d\n", joueur_actuel->nom, joueur_actuel->tours_restants);
                if (joueur_actuel->tours_restants == 0) {
                    fin_partie = 1;
                }
            } else {
                fin_partie = 1;
            }
        }
    }

    // Calculer la force totale
    int force_joueur1 = calculer_force_totale(&jeu->joueur1);
    int force_joueur2 = calculer_force_totale(&jeu->joueur2);

    printf("\n=== Résultat de la Partie ===\n");
    printf("Force totale de %s : %d\n", jeu->joueur1.nom, force_joueur1);
    printf("Force totale de %s : %d\n", jeu->joueur2.nom, force_joueur2);

    if (force_joueur1 > force_joueur2) {
        printf("%s remporte la partie !\n", jeu->joueur1.nom);
    } else if (force_joueur2 > force_joueur1) {
        printf("%s remporte la partie !\n", jeu->joueur2.nom);
    } else {
        printf("La partie est une égalité !\n");
    }
}
