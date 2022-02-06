/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** gets a string from the given line
*/

#include <stdlib.h>
#include "linked_list.h"

//Gets the string from line and sets it to new_node
void get_string(const char *line, node_t *new_node)
{
    char *string = NULL;
    int len = 0;

    for (len = 1; line[len] && line[len] != '"'; len++);
    string = malloc(sizeof(char) * len);
    if (!string) {
        new_node->value = NULL;
        return;
    }
    for (int i = 1; i < len; i++)
        string[i - 1] = line[i];
    string[len - 1] = '\0';
    new_node->value = string;
}
