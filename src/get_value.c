/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** gets the value of a given line
*/

#include <stdlib.h>
#include <unistd.h>
#include "json_parser.h"
#include "linked_list.h"
#include "my.h"

//Choose between float and int
static void get_number_type(const char *line, int len, node_t *new_node,
    int line_index)
{
    for (; line[len] && line[len] != ','; len++) {
        if ((is_invalidchar(line[len]) && !is_number(line[len]))) {
            my_printf(2, "Error: unexpected char line: %d\n", line_index);
            return;
        } else if (line[len] == '.') {
            new_node->type = 3;
        }
    }
    new_node->type = (new_node->type == -1) ? 2 : new_node->type;
}

//Gets the type of value of the given line
static void get_type(const char *line, node_t *new_node, int line_index)
{
    int len = 0;

    new_node->type = -1;
    if (line[0] == '"') {
        for (len = 1; line[len] && line[len] != '"'; len++);
        new_node->type = (len == 2) ? 0 : 1;
    } else if (is_number(line[0]) || line[0] == '-') {
        get_number_type(line, len, new_node, line_index);
    }
}

//Sets the value in the new_node
int set_value(const char *line, node_t *new_node, int line_index)
{
    get_type(line, new_node, line_index);
    switch (new_node->type)
    {
    case 0:
        get_singlechar(line, new_node);
        break;
    case 1:
        get_string(line, new_node);
        break;
    case 2:
        get_int(line, new_node);
        break;
    case 3:
        get_float(line, new_node);
        break;
    }
    return (0);
}
