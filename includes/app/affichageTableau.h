#ifndef AFFICH_TABL_H
#define AFFICH_TABL_H

typedef struct
{
    int depart;
    int longueur;
    char **tableau;
} TableauProp;

void affichageTableau(TableauProp entreeUser);

#endif