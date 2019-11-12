#include "header.h"

enum result add(list_t *li)
{
    if (li->size < 2)
        return (BELOW_TWO);
    elmt_t *first = list_pop(li);
    elmt_t *second = list_pop(li);
    double fd = get_value_union(first);
    double sd = get_value_union(second);
    double result = fd + sd;

    list_push(li, get_big_type_str(first->data->t_p, second->data->t_p), &result);
    free(first);
    free(second);
    return (OK);
}

enum result sub(list_t *li)
{
    if (li->size < 2)
        return (BELOW_TWO);
    elmt_t *first = list_pop(li);
    elmt_t *second = list_pop(li);
    double fd = get_value_union(first);
    double sd = get_value_union(second);
    double result = fd - sd;

    list_push(li, get_big_type_str(first->data->t_p, second->data->t_p), &result);
    free(first);
    free(second);
    return (OK);
}

enum result mul(list_t *li)
{
    if (li->size < 2)
        return (BELOW_TWO);
    elmt_t *first = list_pop(li);
    elmt_t *second = list_pop(li);
    double result = get_value_union(first) * get_value_union(second);

    list_push(li, get_big_type_str(first->data->t_p, second->data->t_p), &result);
    free(first);
    free(second);
    return (OK);
}

enum result divi(list_t *li)
{
    if (li->size < 2)
        return (BELOW_TWO);
    elmt_t *first = list_pop(li);
    elmt_t *second = list_pop(li);
    double fd = get_value_union(first);
    double sd = get_value_union(second);
    double result;

    if (get_value_union(second) == 0.0)
        return (DIV_BY_ZERO);
    result = fd / sd;
    list_push(li, get_big_type_str(first->data->t_p, second->data->t_p), &result);
    free(first);
    free(second);
    return (OK);
}

enum result mod(list_t *li)
{
    if (li->size < 2)
        return (BELOW_TWO);
    elmt_t *first = list_pop(li);
    elmt_t *second = list_pop(li);
    long fd = get_value_union(first);
    long sd = get_value_union(second);
    double result;

    if (get_value_union(second) == 0.0)
        return (MOD_BY_ZERO);
    result = fd % sd;
    list_push(li, get_big_type_str(first->data->t_p, second->data->t_p), &result);
    free(first);
    free(second);
    return (OK);
}
