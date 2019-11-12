#include "header.h"

void init_struct(abstractvm_t *abs)
{
    init_cmd(abs);
    init_type(abs);
    init_type_fun(abs);
    init_cmd_fun(abs);
}

void init_cmd(abstractvm_t *abs)
{
    abs->cmd[0] = "add";
    abs->cmd[1] = "sub";
    abs->cmd[2] = "mul";
    abs->cmd[3] = "div";
    abs->cmd[4] = "mod";
    abs->cmd[5] = "pop";
    abs->cmd[6] = "dump";
    abs->cmd[7] = "print";
    abs->cmd[8] = "exit";
    abs->cmd[9] = "push";
    abs->cmd[10] = "assert";
}

void init_type(abstractvm_t *abs)
{
    abs->type[0] = "int8";
    abs->type[1] = "int16";
    abs->type[2] = "int32";
    abs->type[3] = "float";
    abs->type[4] = "double";
}

void init_type_fun(abstractvm_t *abs)
{
    abs->fun_type_tab[0] = is_integer;
    abs->fun_type_tab[1] = is_integer;
    abs->fun_type_tab[2] = is_integer;
    abs->fun_type_tab[3] = is_float;
    abs->fun_type_tab[4] = is_float;
}

void init_cmd_fun(abstractvm_t *abs)
{
    abs->f[0] = add;
    abs->f[1] = sub;
    abs->f[2] = mul;
    abs->f[3] = divi;
    abs->f[4] = mod;
    abs->f[5] = pop;
    abs->f[6] = dump;
    abs->f[7] = print;
    abs->f[8] = quit;
    abs->f[9] = push;
    abs->f[10] = assert;
}
