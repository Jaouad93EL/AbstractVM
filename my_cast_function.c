#include "header.h"

char *get_type_str(enum type_value tv)
{
    switch (tv) {
        case INT_8:
            return ("int8");
        case INT_16:
            return ("int16");
        case INT_32:
            return ("int32");
        case FLOAT:
            return ("float");
        case DOUBLE:
            return ("double");
        default:
            return (NULL);
    }
}

enum type_value get_big_type_str(enum type_value ft_v, enum type_value st_v)
{
    if (ft_v > st_v)
        return (ft_v);
    return (st_v);
}

enum type_value get_typev(abstractvm_t *abs, char *type)
{
    for (int i = 0; i < 5; ++i) {
        if (my_cmp(type, abs->type[i]) == 0)
            return (i);
    }
    return (-1);
}

double get_value_union(elmt_t *elmt)
{
    if (elmt->data->t_p == FLOAT || elmt->data->t_p == DOUBLE)
        return (elmt->data->value.d);
    else
        return ((double) elmt->data->value.i);
}

int run_machine(abstractvm_t *abs, list_t *li)
{
    enum result r = OK;
    char *str = NULL;

    for (int i = 0; i < abs->size; ++i)
        for (int j = 0; j < 11; ++j)
            if (my_cmp(abs->array[i].cmd, abs->cmd[j]) == 0) {
                if (my_cmp(abs->cmd[j], "push") == 0 || my_cmp(abs->cmd[j], "assert") == 0)
                    r = abs->f[j](li, &abs->array[i], get_typev(abs, abs->array[i].type));
                else
                    r = abs->f[j](li);
                str = parse_result(r);
                if (str != NULL) {
                    print_error(i, str, abs->array[i].cmd);
                    return (-1);
                } else if (r == QUIT)
                    return (0);
                break;
            }
    return (0);
}
