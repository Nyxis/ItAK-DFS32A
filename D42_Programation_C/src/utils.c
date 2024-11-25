#include "utils.h"
#include <carte.h>



void melanger_cartes(Carte *cartes, int nb_cartes) {
srand(time(NULL));

    for (int i = nb_cartes - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        
        Carte temp = cartes[i];
        cartes[i] = cartes[j];
        cartes[j] = temp;
    }
}


int saisir_entier(const char *message) {
    int nombre;
    printf("%s", message);
    scanf("%d", &nombre);
    return nombre;
}
