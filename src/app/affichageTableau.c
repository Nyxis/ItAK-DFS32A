#include <stdio.h>

void affichageTableau(int longueur, char *tableau[], int depart)
{

    for (int i = depart; i < longueur; i++)
    {
        printf("Hello world j'ai %s ans ! \n", tableau[i]);
    }
}