/*
** EPITECH PROJECT, 2021
** C Pool Day 09
** File description:
** includes all the prototypes of libmy
*/

#include <stdarg.h>

#ifndef MY_H_
    #define MY_H_

    #define is_number(c) (c >= '0' && c <= '9') ? 1 : 0

    #define is_printable(c) (c > 32 && c < 127) ? 1 : 0

void my_putchar(char c, int std);

char *my_itos(int nb);

int my_put_unsigned_nbr(unsigned int nb, int std);

int my_put_nbr_base(int nb, char *base, int std);

int my_put_nbr_base_long(long long nb, char *base, int std);

int my_putstr(char const *str, int std);

int my_strlen(char const *str);

int my_getnbr(char const *str);

char *my_strcpy(char *dest, char const *src);

char *my_strncpy(char *dest, char const *src, int n);

char *my_revstr(char *str);

char *my_strstr(char *str, char const *to_find);

int my_strcmp(char const *s1, char const *s2);

int my_strncmp(char const *s1, char const *s2, int n);

char *my_strcat(char *dest, char const *src);

char *my_allocated_strcat(const char *src1, const char *src2);

char *my_strncat(char *dest, char const *src, int nb);

char **my_str_to_word_array(char const *str, char const *delim);

char *my_strdup(const char *s);

char *my_convert_base(int nb, char *base);

int my_printf(int std, const char *format, ...);

int my_atoi(char const *str);

int my_get_index(char converted_char, char *str);

int my_compute_power_rec(int nb, int p);

//----------------------MY_PRINTF-----------------------------

int handler_put_nbr_decimal(va_list ap, char *arguments, int std);

int handler_put_unsigned_nbr(va_list ap, char *arguments, int std);

int handler_put_nbr_long(va_list ap, char *arguments, int std);

int handler_convert_base_binary(va_list ap, char *argument, int std);

int handler_convert_base_octal(va_list ap, char *argument, int std);

int handler_convert_base_hexa(va_list ap, char *argument, int std);

int handler_convert_base_maj_hexa(va_list ap, char *argument, int std);

int handler_putchar_basic(va_list ap, char *arguments, int std);

int handler_putchar_percentage(va_list ap, char *arguments, int std);

int handler_putstr(va_list ap, char *arguments, int std);

int handler_showstr(va_list ap, char *arguments, int std);

#endif
