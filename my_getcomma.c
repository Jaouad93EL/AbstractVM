#include "header.h"

int len_comma(char *str)
{
    int i = 0;

    while (str[i] != '.')
        i++;
    return (i);
}

char **split_by_comma(char *str)
{
    int i = 0;
    int k = 0;
    int comma = len_comma(str);
    char **tab = malloc(sizeof(char *) * 2);

    tab[0] = malloc(sizeof(char) * comma);
    tab[1] = malloc(sizeof(char) * my_strlen(str) - comma);
    if (tab == NULL)
        return (NULL);
    while (str[i] != '.') {
        tab[0][k++] = str[i];
        i++;
    }
    k = 0;
    while (str[++i] != '\0') {
        tab[1][k++] = str[i];
    }
    return (tab);
}

int get_mult(int len)
{
    int mult = 1;
    int i = 0;

    while (i < len) {
        mult *= 10;
        i++;
    }
    return (mult);
}

double my_getcomma(char *str)
{
    char **tab = split_by_comma(str);
    int before = my_getnbr(tab[0]);
    double after = (double) my_getnbr(tab[1]) / get_mult(my_strlen(tab[1]));

    return (before + after);
}
