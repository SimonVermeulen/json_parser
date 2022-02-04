/*
** EPITECH PROJECT, 2021
** linked_list
** File description:
** includes all the prototypes of my linked lists
*/

#ifndef LINKED_LIST_H_
    #define LINKED_LIST_H_

/*----------------LIST----------------*/

list_t *create_empty_list(void);

void delete_list(list_t *list);

/*---------------ELEMENT--------------*/

int push_element(list_t *list, node_t *data);

int unshift_element(list_t *list, node_t *data);

int pop_element(list_t *list);

int shift_element(list_t *list);

node_t *create_node(char *key, void *value, int id);

void delete_node(node_t *node);

/*---------------STRUCT---------------*/

typedef struct node_s {
    node_t *prev;
    node_t *next;
    char *key;
    void *value;
    int id;
} node_t;

typedef struct list_s {
    node_t *head;
    int nb_elements;
    char *name;
} list_t;

#endif
