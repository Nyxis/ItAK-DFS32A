#ifndef CARTE_H
#define CARTE_H

typedef struct
{
    int level;
    int force;
    char *color;
} Card;

extern char *colors[];

Card cardGenerator();

#endif