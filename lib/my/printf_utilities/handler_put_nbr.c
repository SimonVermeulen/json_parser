/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** handles all the putnbr
*/

#include <stdarg.h>
#include <stdlib.h>
#include "../my.h"

int handler_put_nbr_decimal(va_list ap, char *arguments, int std)
{
    if (ap && (arguments == NULL || arguments[0] == '#')) {
        my_put_nbr_base(va_arg(ap, int), "0123456789", std);
        return (1);
    } else {
        return (0);
    }
}

int handler_put_nbr_long(va_list ap, char *arguments, int std)
{
    if (ap && (arguments == NULL || arguments[0] == '#')) {
        my_putstr("0x", std);
        my_put_nbr_base_long(va_arg(ap, long long), "0123456789abcdef", std);
        return (1);
    } else {
        return (0);
    }
}

int handler_put_unsigned_nbr(va_list ap, char *arguments, int std)
{
    if (ap && (arguments == NULL || arguments[0] == '#')) {
        my_put_unsigned_nbr(va_arg(ap, unsigned int), std);
        return (1);
    } else {
        return (0);
    }
}
