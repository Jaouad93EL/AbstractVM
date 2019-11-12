#include "header.h"
#include "list.h"

int contain_exit_cmd(abstractvm_t *abs)
{
    int i = 0;

    while (i < abs->size) {
        if (my_cmp(abs->array[i].cmd, "exit") == 0)
            return (1);
        i++;
    }
    my_putstr("Error : Missing exit command in program\n");
    return (-1);
}

int execute_abstractvm(abstractvm_t *abs, char *str)
{
    int return_value;

    init_struct(abs);
    parse_instruction(abs, str);
    return_value = find_error_instruction(abs);
    if (return_value == -1)
        return (-1);
    return (contain_exit_cmd(abs));
}

int main(int argc, char **argv)
{
    int file = open(argv[1], O_RDONLY);
    char *str = read_file(file);
    abstractvm_t abs;
    list_t li;
    int return_value;

    if (str == NULL || argc != 2) {
        my_putstr("Error : File not found.\n");
        return (-1);
    }
    if (execute_abstractvm(&abs, str) == -1)
        return (-1);
    list_init(&li);
    return_value = run_machine(&abs, &li);
    if (return_value == -1)
        return (-1);
    return (0);
}
