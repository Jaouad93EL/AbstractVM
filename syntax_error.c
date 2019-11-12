#include "header.h"

int print_error(int line, char *message, char *name)
{
    my_putstr("Error at line ");
    my_putnbr(line + 1);
    my_putstr(" : ");
    my_putstr(message);
    my_putstr(" \'");
    my_putstr(name);
    my_putstr("\'\n");
    return (-1);
}

int is_correct_arithmetic(abstractvm_t *abs, char *command)
{
    int i = 0;

    while (i < 9) {
        if (my_cmp(abs->cmd[i], command) == 0) {
            return (1);
        }
        i++;
    }
    return (0);
}

int is_correct_command(abstractvm_t *abs, char *command)
{
    int i = 5;

    while (i < 11) {
        if (my_cmp(abs->cmd[i], command) == 0)
            return (1);
        i++;
    }
    return (0);
}

int is_correct_type(abstractvm_t *abs, char *type)
{
    int i = 0;

    while (i < 5) {
        if (my_cmp(abs->type[i], type) == 0)
            return (1);
        i++;
    }
    return (0);
}

int find_error_instruction(abstractvm_t *abs)
{
    int error = 1;
    char first_char;

    for (int i = 0; i < abs->size; i++) {
        first_char = abs->array[i].cmd[0];
        if ((first_char == '\0' || first_char == '\n') ||
            is_correct_arithmetic(abs, abs->array[i].cmd))
            continue;
        if (!is_correct_command(abs, abs->array[i].cmd))
            error = print_error(i, "Unknow command name", abs->array[i].cmd);
        if (!is_correct_type(abs, abs->array[i].type)) {
            error = print_error(i, "Unknow type name", abs->array[i].type);
            continue;
        }
        if (is_correct_value(abs->array[i].type, abs->array[i].value) == 0)
            error = print_error(i, "Incorrect value", abs->array[i].value);
    }
    return (error);
}