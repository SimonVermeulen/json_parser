/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** handles all the putstr and putchar
*/

#include <stdarg.h>
#include <stdlib.h>
#include "../my.h"

int handler_putchar_basic(va_list ap, char *arguments, int std)
{
    if (ap && (arguments == NULL || arguments[0] == '#')) {
        my_putchar(va_arg(ap, int), std);
        return (1);
    } else {
        return (0);
    }
}

int handler_putchar_percentage(va_list ap, char *arguments, int std)
{
    if (ap && (arguments == NULL || arguments[0] == '#')) {
        my_putchar('%', std);
        return (1);
    } else {
        return (0);
    }
}

int handler_putstr(va_list ap, char *arguments, int std)
{
    if (ap && (arguments == NULL || arguments[0] == '#')) {
        my_putstr(va_arg(ap, char *), std);
        return (1);
    } else {
        return (0);
    }
}
