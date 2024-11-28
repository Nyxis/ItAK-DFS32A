#include <stdio.h>
#include "../../includes/app/affichageTableau.h"

void affichageTableau(TableauProp entreesUser)
{
    char **tableauAge = entreesUser.tableau;

    for (int i = entreesUser.depart; i < entreesUser.longueur; i++)
    {
        printf("Hello world j'ai %s ans ! \n", tableauAge[i]);
    }
}