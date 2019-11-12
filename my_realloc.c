#include "header.h"

char *my_realloc(char *file, int size)
{
    int i = 0;
    char *str = malloc(sizeof(char) * size);

    if (str == NULL)
        return NULL;
    while (file[i] != '\0') {
        str[i] = file[i];
        i++;
    }
    str[i] = '\0';
    free(file);
    return (str);
}
