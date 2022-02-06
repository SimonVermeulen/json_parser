/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** handles the case where the value is a single char
*/

#include <stdlib.h>
#include "linked_list.h"

//Gets the single char from line and set its to new_node
void get_singlechar(const char *line, node_t *new_node)
{
    char *c = NULL;

    c = malloc(sizeof(char));
    if (!c) {
        new_node->value = NULL;
        return;
    }
    *c = line[1];
    new_node->value = c;
}
