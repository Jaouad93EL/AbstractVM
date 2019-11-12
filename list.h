#ifndef LIST_H
#define LIST_H

enum type_value {
    INT_8,
    INT_16,
    INT_32,
    FLOAT,
    DOUBLE
};

enum result {
    OK,
    QUIT,
    NO_ELMT,
    BELOW_TWO,
    DIV_BY_ZERO,
    MOD_BY_ZERO,
    NOT_INT_8,
    NOT_EQUAL
};

typedef struct instruction_s {
    char *cmd;
    char *type;
    char *value;
} instruction_t;

typedef struct abstractvm_s {
    instruction_t *array;
    int size;
    char *cmd[11];
    char *type[5];
    int (*fun_type_tab[5])();
    enum result (*f[11])();
} abstractvm_t;

typedef struct data_s {
    enum type_value t_p;
    union {
        int i;
        double d;
    } value;
} data_t;

typedef struct elmt_s {
    data_t *data;
    struct elmt_s *next;
} elmt_t;

typedef struct list_s {
    int size;
    elmt_t *head;
    elmt_t *tail;
} list_t;

#endif
