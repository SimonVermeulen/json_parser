/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** check if the current line contains an int
*/

#include "json_parser.h"

int check_int(const char *line)
{
    int i = 0;
    int len = 0;

    if (line[0] && line[0] == '-')
        i++;
    for (; line[i] && (line[i] != ',' && line[i] != '\n'); i++) {
        if (!is_number(line[i]))
            return (-1);
        else
            len++;
    }
    if (len == 0)
        return (-1);
    return (1);
}
