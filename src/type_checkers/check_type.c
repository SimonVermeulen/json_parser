/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** checks the type of the next value
*/

#include "json_parser.h"

void check_type(const char *line, node_t *tmp)
{
    int (*checkers[5])(const char *) = {&check_double, &check_int, &check_string,
        &check_object};
    
    for (int i = 0; i < 5; i++) {
        if (checkers[i](line) > 0) {
            tmp->type = i;
            return;
        }
    }
    tmp->type = -1;
}
