#include "header.h"

int get_size(char *str, int i, char c)
{
    int size = 0;
    while (str[i] != c && str[i] != '\0') {
        i++;
        size++;
    }
    return (size);
}

char *get_instruction(char *str, char delimiter, int *indice)
{
    int i = 0;
    int size = get_size(str, *indice, delimiter);
    char *instruction = malloc(sizeof(char) * size + 1);

    if (instruction == NULL)
        return (NULL);
    while (str[*indice] != delimiter && str[*indice] != '\0' && str[*indice] != ';') {
        instruction[i] = str[*indice];
        *indice += 1;
        i++;
    }
    instruction[i] = '\0';
    return (instruction);
}

void parse_instruction(abstractvm_t *abs, char *str)
{
    int i = 0;
    int j = 0;
    char **tab = my_str_to_wordtab(str);

    abs->size = count_line(str);
    abs->array = malloc(sizeof(instruction_t) * abs->size);
    while (i < abs->size) {
        j = 0;
        abs->array[i].cmd = get_instruction(tab[i], ' ', &j);
        while (tab[i][j] == ' ')
            j++;
        abs->array[i].type = get_instruction(tab[i], '(', &j);
        while (tab[i][j] == '(')
            j++;
        abs->array[i].value = get_instruction(tab[i], ')', &j);
        i++;
    }
}

char *parse_result(enum result r)
{
    switch (r) {
        case OK:
            return (NULL);
        case NO_ELMT:
            return ("NO_ELMT");
        case BELOW_TWO:
            return ("BELOW_2");
        case DIV_BY_ZERO:
            return ("DIV_BY_0");
        case MOD_BY_ZERO:
            return ("MOD_BY_0");
        case NOT_INT_8:
            return ("NOT_INT_8");
        case NOT_EQUAL:
            return ("NOT_EQUAL");
        default:
            return (NULL);
    }
}
