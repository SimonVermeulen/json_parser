/*
** EPITECH PROJECT, 2021
** CPool day03
** File description:
** prints a given number
*/

#include <unistd.h>
#include "my.h"

int my_put_nbr_base(int nb, char *base, int std)
{
    int base_len = my_strlen(base);
    long new_nb = nb;

    if (new_nb < 0) {
        my_putchar('-', std);
        new_nb = -new_nb;
    }
    if (new_nb >= base_len)
        my_put_nbr_base(new_nb / base_len, base, std);
    my_putchar(base[new_nb % base_len], std);
    return (0);
}

int my_put_nbr_base_long(long long nb, char *base, int std)
{
    int base_len = my_strlen(base);

    if (nb < 0)
        nb = -nb;
    if (nb >= base_len)
        my_put_nbr_base_long(nb / base_len, base, std);
    my_putchar(base[nb % base_len], std);
    return (0);
}

int my_put_unsigned_nbr(unsigned int nb, int std)
{
    long int new_nb = nb;

    if (new_nb < 0) {
        my_putstr("4294967295", std);
        return (1);
    }
    if (new_nb > 9) {
        my_put_nbr_base(new_nb / 10, "0123456789", std);
    }
    my_putchar(new_nb % 10 + 48, std);
    return (0);
}
