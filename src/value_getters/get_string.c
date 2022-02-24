/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** gets a string from the given line
*/

#include <stdlib.h>
#include <unistd.h>
#include "linked_list.h"

//Get a single string from a line
static int get_single_string(const char *line, node_t *new_node)
{
    char *word = NULL;
    int len = 1;

    if (line[0] && line[0] != '"') {
        write(2, "Error: expected a '\"'\n", 23);
        return (-1);
    }
    for (int i = 1; line[i] && line[i] != '"'; i++, len++);
    word = malloc(sizeof(char) * (len + 1));
    if (!word)
        return (-1);

    for (int i = 1; i < len; i++)
        word[i - 1] = line[i];
    word[len - 1] = '\0';

    new_node->value = word;
    return (len + 1);
}

//Gets an array of string from the line
static int get_string_array(const char *line, node_t *new_node,
    int nb_elements)
{
    char **word_array = NULL;
    int len = 0;

    word_array = malloc(sizeof(char *) * (nb_elements + 1));
    if (!word_array)
        return (-1);
    for (int i = 0; i < nb_elements; i++, len++) {
        len += get_single_string(&line[len], new_node);
        if (len < 0)
            return (-1);
        word_array[i] = (char *)new_node->value;
        if (line[len] && line[len] != ',' && i != nb_elements - 1) {
            write(2, "Error: expected a ','\n", 23);
            return (-1);
        }
    }
    word_array[nb_elements] = NULL;
    new_node->value = word_array;
    return (len);
}

int get_string(const char *line, node_t *new_node, int nb_elements)
{
    int len = 0;

    new_node->len = (nb_elements == 0) ? 1 : nb_elements;
    if (nb_elements == 0) {
        len = get_single_string(line, new_node);
    } else if (nb_elements > 1) {
        len = get_string_array(line, new_node, nb_elements);
    }
    if (len < 0) {
        new_node->value = NULL;
        return (-1);
    }
    return (len);
}
