#include "header.h"

enum result assert(list_t *li, instruction_t *inst, enum type_value t_v)
{
    elmt_t *head = li->head;

    if (li->size < 1)
        return (NO_ELMT);
    if (head->data->t_p == t_v && verif_asser_value(head, inst) == 0)
        return (OK);
    return (NOT_EQUAL);
}

int verif_asser_value(elmt_t *head, instruction_t *in)
{
    if (my_cmp(in->type, "float") == 0 || my_cmp(in->type, "double") == 0)
        return (verif_assert_double(head->data->value.d, my_getcomma(in->value)));
    return (verif_assert_int(head->data->value.i, my_getnbr(in->value)));
}

int verif_assert_int(int head_value, int value)
{
    if (head_value == value)
        return (0);
    return (-1);
}

int verif_assert_double(double head_value, double value)
{
    if (head_value == value)
        return (0);
    return (-1);
}
