#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "list.h"

#define MIN_INT8 -128
#define MAX_INT8 127
#define MIN_INT16 -32768
#define MAX_INT16 32767
#define MIN_INT32 -2147483648
#define MAX_INT32 2147483647

//syntax_error.c
int is_commentary(char *str);
int print_error(int line, char *message, char *name);
int is_correct_command(abstractvm_t *abs, char *command);
int is_correct_type(abstractvm_t *abs, char *type);
int find_error_instruction(abstractvm_t *abs);

//my_function.c
int my_cmp(char *s1, char *s2);
int my_strlen(char *str);
char *my_strcpy(char *dest, char *src);
char *my_strcat(char *dest, char *src);
char *my_strdup(char *arr);

//my_cast_function.c
enum type_value get_big_type_str(enum type_value ft_v, enum type_value st_v);
char *get_type_str(enum type_value tv);
enum type_value get_typev(abstractvm_t *abs, char *type);
double get_value_union(elmt_t *elmt);
int run_machine(abstractvm_t *abs, list_t *li);

//is_correct_type.c
int is_in_range_integer(long long nb, int nb_bytes);
int is_integer(char *str, int nb_bytes);
int is_float(char *str);
int is_correct_value(char *type, char *str);

//my_putstr.c
void my_putchar(char c);
void my_putstr(char *str);

//my_str_to_wordtab.c
int count_line(char *str);
char **my_str_to_wordtab(char *str);

//my_getnbr.c
int my_getnbr(char *str);

//my_getcomma.c
int len_comma(char *str);
char **split_by_comma(char *str);
int get_mult(int len);
double my_getcomma(char *str);

//display_comma.c
void my_double(double number, int posi);
void my_putnbr_long(long n);
void my_putnbr(int n);

//read_file.c
char *read_file(int fd);

//my_realloc.c
char *my_realloc(char *file, int size);

//my_abstract_vm.c
void init_struct(abstractvm_t *abs);
void init_cmd(abstractvm_t *abs);
void init_type(abstractvm_t *abs);
void init_type_fun(abstractvm_t *abs);
void init_cmd_fun(abstractvm_t *abs);

//parse_instruction.c
char *get_instruction(char *str, char delimiter, int *indice);
void parse_instruction(abstractvm_t *abs, char *str);
char *parse_result(enum result r);

//my_stack_operations.c
enum result push(list_t *li, instruction_t *inst, enum type_value t_v);
enum result pop(list_t *li);
enum result dump(list_t *li);
enum result print(list_t *li);
enum result quit(list_t *li);

//my_assert.c
enum result assert(list_t *li, instruction_t *inst, enum type_value t_v);
int verif_asser_value(elmt_t *head, instruction_t *in);
int verif_assert_int(int head_value, int value);
int verif_assert_double(double head_value, double value);

//my_arithmetic.c
enum result add(list_t *li);
enum result sub(list_t *li);
enum result mul(list_t *li);
enum result divi(list_t *li);
enum result mod(list_t *li);

//list.c
void list_init(list_t *list);
void list_destroy(list_t *list);
int list_push(list_t * list, enum type_value t_p, void *value);
elmt_t *list_pop(list_t *list);
void list_display(list_t *list);

//main.c
int contain_exit_cmd(abstractvm_t *abs);
int contain_exit_cmd(abstractvm_t *abs);

#endif
