#include "string.h"
#include <string.h>
#include <stdlib.h>

String createString(const char *text) {
    String str;
    str.length = strlen(text);
    str.data = (char *)malloc((str.length + 1) * sizeof(char));
    if (str.data) {
        strcpy(str.data, text);
    }
    return str;
}

void freeString(String *str) {
    if (str->data) {
        free(str->data);
        str->data = NULL;
        str->length = 0;
    }
}
