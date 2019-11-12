#include "header.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}

void my_putnbr(int n)
{
    if (n < 0) {
        if (n == -2147483648) {
            my_putstr("-2147483648");
            return;
        }
        my_putchar('-');
        n *= -1;
    }
    if (n > 9) {
        my_putnbr(n / 10);
        my_putnbr(n % 10);
    } else
        my_putchar(n + 48);
}
