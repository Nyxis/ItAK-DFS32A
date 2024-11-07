#ifndef CARTE_H
#define CARTE_H

typedef struct
{
    int level;
    int force;
    char *color;
} Card;

Card cardGenerator();

#endif