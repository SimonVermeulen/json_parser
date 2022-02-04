/*
** EPITECH PROJECT, 2021
** C Pool Day 07
** File description:
** my_strcat
*/

#include <stdlib.h>
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0')
        i++;
    while (src[j] != '\0') {
        dest[i + j] = src[j];
        j++;
    }
    dest[i + j] = '\0';
    return (dest);
}

char *my_allocated_strcat(const char *src1, const char *src2)
{
    char *result = NULL;
    int i = 0;
    int j = 0;

    result = malloc(sizeof(char) * (my_strlen(src1) + my_strlen(src2) + 2));
    if (!result)
        return (NULL);
    for (; src1[i]; i++)
        result[i] = src1[i];
    if (result[i - 1] != '/')
        result[i++] = '/';
    for (; src2[j]; j++)
        result[i + j] = src2[j];
    result[i + j] = '\0';
    return (result);
}
