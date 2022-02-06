/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** gets an int from the given line
*/

#include <stdlib.h>
#include <math.h>
#include "linked_list.h"
#include "my.h"

//Gets an int from line and sets it to new_node
void get_int(const char *line, node_t *new_node)
{
    int *result = NULL;

    result = malloc(sizeof(int));
    if (!result) {
        new_node->value = NULL;
        return;
    }
    *result = atof(line);
    new_node->value = result;
}
