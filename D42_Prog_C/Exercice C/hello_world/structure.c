#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    size_t size;
} String;

String init_string(const char *str) {
    String s;
    s.size = strlen(str);
    s.data = (char *)malloc(s.size + 1);
    strcpy(s.data, str);
    return s;
}

void print_string(String s) {
    printf("Data: %s\n", s.data);
    printf("Size: %zu\n", s.size);
}

void free_string(String s) {
    free(s.data);
}

int main() {
    String s = init_string("Hello, World!");
    print_string(s);
    free_string(s);
    return 0;
}
