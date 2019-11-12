#include "header.h"

void my_double(double number, int position)
{
    long nb = 0;

    if (number < 0) {
        my_putchar('-');
        number = number * -1;
    }
    nb = number;
    my_putnbr_long(nb);
    if (position > 0) {
        my_putchar('.');
    }
    while (position > 0) {
        number = (number - nb) * 10;
        nb = number;
        my_putchar(nb + 48);
        position--;
    }
}

void my_putnbr_long(long n)
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
        my_putnbr_long(n / 10);
        my_putnbr_long(n % 10);
    }
    else
        my_putchar(n + 48);
}
