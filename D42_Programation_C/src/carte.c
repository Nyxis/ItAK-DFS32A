#include "carte.h"

void afficher_carte(Carte carte) {
    const char *niveaux[] = {"1", "2", "3"};
    const char *couleurs[] = {"blanc", "gris", "noir", "bleu", "orange", "rouge", "violet", "rose", "jaune", "vert"};
    const char *forces[] = {"2", "3", "4", "5", "6", "10"};

    printf("%s-%s-%s", niveaux[carte.niveau], couleurs[carte.couleur], forces[carte.force]);
}
