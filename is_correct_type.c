#include "header.h"

int is_in_range_integer(long long nb, int nb_bytes)
{
    switch (nb_bytes) {
        case 8:
            if (nb >= MIN_INT8 && nb <= MAX_INT8)
                return 1;
            break;
        case 16:
            if (nb >= MIN_INT16 && nb <= MAX_INT16)
                return 1;
            break;
        case 32:
            if (nb >= MIN_INT32 && nb <= MAX_INT32)
                return 1;
            break;
        default:
            break;
    }
    return 0;
}

int is_integer(char *str, int nb_bytes)
{
    int i = 0;
    long long nb = 0;

    if (str[i] == '-')
        i++;
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9')
            nb = nb * 10 + (str[i] - 48);
        else
            return 0;
        i++;
    }
    return is_in_range_integer(nb, nb_bytes);
}

int is_correct_decimal(char *str, int index)
{
    if (str[index] == '.')
        index++;
    if (!(str[index] >= '0' && str[index] <= '9'))
        return 0;
    while (str[index] != '\0') {
        if (!(str[index] >= '0' && str[index] <= '9'))
            return 0;
        index++;
    }
    return 1;
}

int is_float(char *str)
{
    int i = 0;
    int sign = 1;

    if (str[i] == '-') {
        i++;
        sign *= -1;
    }
    while (str[i] >= '0' && str[i] <= '9')
        i++;
    if (str[i] != '.')
        return 0;
    return is_correct_decimal(str, i);
}

int is_correct_value(char *type, char *str)
{
    if (my_cmp(type, "int8") == 0)
        return is_integer(str, 8);
    if (my_cmp(type, "int16") == 0)
        return is_integer(str, 16);
    if (my_cmp(type, "int32") == 0)
        return is_integer(str, 32);
    if (my_cmp(type, "float") == 0 || my_cmp(type, "double") == 0)
        return is_float(str);
    return 0;
}
