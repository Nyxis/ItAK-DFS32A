// main.c
#include <stdio.h>
#include <stdlib.h>
#include "../include/string_array.h"

int main() {
    StringArray sa;
    sa.size = 3;
    sa.array = malloc(sa.size * sizeof(char*));
    
    sa.array[0] = "Hello";
    sa.array[1] = "World";
    sa.array[2] = "!";
    
    for (int i = 0; i < sa.size; i++) {
        printf("%s ", sa.array[i]);
    }
    printf("\n");
    
    free(sa.array);
    return 0;
}