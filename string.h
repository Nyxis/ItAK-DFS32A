#ifndef STRING_H
#define STRING_H

typedef struct {
    char *data;
    int length;
} String;

String createString(const char *text);
#endif // STRING_H