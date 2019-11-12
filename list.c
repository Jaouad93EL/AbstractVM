#include "header.h"

void list_init(list_t * list)
{
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
}

void list_destroy(list_t *list)
{
    elmt_t *old;

    while (list->size > 0) {
        old = list_pop(list);
        free(old);
    }
}

int list_push(list_t * list, enum type_value t_p, void *value)
{
    elmt_t *new_element = (elmt_t *) malloc(sizeof(elmt_t));

    if (new_element == NULL)
        return (-1);
    new_element->data = (data_t *) malloc(sizeof(data_t));
    new_element->data->t_p = t_p;
    if (t_p == FLOAT || t_p == DOUBLE)
        new_element->data->value.d = *(double *) value;
    else
        new_element->data->value.i = (int) *(double *) value;
    if (list->size == 0)
        list->tail = new_element;
    new_element->next = list->head;
    list->head = new_element;
    list->size++;
    return (0);
}

elmt_t *list_pop(list_t *list)
{
    elmt_t *old_element;

    if (list->size == 0)
        return (NULL);
    old_element = list->head;
    list->head = list->head->next;
    if (list->size == 1)
        list->tail = NULL;
    list->size--;
    return (old_element);
}

void list_display(list_t *list)
{
    elmt_t *aff_element = list->head;

    for (int i = 0; i < list->size; ++i) {
        if (aff_element->data->t_p == FLOAT || aff_element->data->t_p == DOUBLE) {
            double d = aff_element->data->value.d;
            my_double(d, 2);
        } else {
            int i = aff_element->data->value.i;
            my_putnbr(i);
        }
        my_putchar('\n');
        aff_element = aff_element->next;
    }
}
