/*
** EPITECH PROJECT, 2022
** linked_list
** File description:
** inits a node
*/

#include <stdlib.h>
#include "linked_list.h"

//Creates an empty node
node_t *create_newnode(int id)
{
    node_t *new_node = NULL;

    new_node = malloc(sizeof(node_t));
    if (!new_node)
        return (NULL);
    new_node->id = id;
    new_node->type = -1;
    new_node->len = 0;
    new_node->value = NULL;
    new_node->key = NULL;
    new_node->next = NULL;
    new_node->prev = NULL;

    return (new_node);
}

//Frees the given node
void delete_node(node_t *node)
{
    if (node) {
        free(node->key);
        free(node->value);
        free(node);
    }
}
