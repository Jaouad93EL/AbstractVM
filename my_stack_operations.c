#include "header.h"

enum result push(list_t *li, instruction_t *inst, enum type_value t_v)
{
    void *val = NULL;

    if (my_cmp(inst->type, "float") == 0 || my_cmp(inst->type, "double") == 0) {
        double d = my_getcomma(inst->value);
        val = &d;
    }
    else {
        double i = (double) my_getnbr(inst->value);
        val = &i;
    }
    list_push(li, t_v, val);
    return (OK);
}

enum result pop(list_t *li)
{
    if (li->size == 0)
        return (NO_ELMT);
    elmt_t *elmt = list_pop(li);

    free(elmt);
    return (OK);
}

enum result dump(list_t *li)
{
    my_putstr("Dump:\n");
    list_display(li);
    return (OK);
}

enum result print(list_t *li)
{
    if (li->head->data->t_p == INT_8)
        return (-1);
    my_putchar(li->head->data->value.i);
    return (OK);
}

enum result quit(list_t *li)
{
    list_destroy(li);
    return (QUIT);
}
