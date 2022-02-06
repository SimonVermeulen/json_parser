/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** gets a float from the line
*/

#include <stdlib.h>
#include <math.h>
#include "linked_list.h"
#include "my.h"

//Gets a float from the line and sets it to new_node
void get_float(const char *line, node_t *new_node)
{
    double *result = NULL;

    result = malloc(sizeof(float));
    if (!result) {
        new_node->value = NULL;
        return;
    }
    *result = atof(line);
    new_node->value = result;
}

