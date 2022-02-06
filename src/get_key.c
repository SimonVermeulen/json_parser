/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** Gets the key of a given line
*/

#include <stdlib.h>
#include <unistd.h>
#include "json_parser.h"
#include "linked_list.h"
#include "my.h"

//gets the key
char *get_key(const char *start)
{
    char *key = NULL;
    int len = 1;

    for (; start[len] && start[len] != '"'; len++);
    key = malloc(sizeof(char) * (len));
    if (!key)
        return (NULL);
    for (int i = 1; start[i] && start[i] != '"'; i++)
        key[i - 1] = start[i];
    key[len - 1] = '\0';
    return (key);
}

//gets and sets the key of a given line
int set_key(const char *line, node_t *new_node, int line_index)
{
    int return_value = 0;
    int ind = 0;

    for (; line[ind] && (line[ind] == ' ' || line[ind] == '\t'); ind++);
    if (line[ind] == '"') {
        new_node->key = get_key(&line[ind]);
        return_value = ind + my_strlen(new_node->key) + 4;
    } else {
        return_value = -1;
        new_node->key = NULL;
    }
    if (!new_node->key) {
        my_printf(2, "Error at line: %d\n", line_index + 1);
    }
    return (return_value);
}

//CHANGER POUR FAIRE L'ATTRIBUTION DIRECTEMENT AU MOMENT DU GET_KEY
