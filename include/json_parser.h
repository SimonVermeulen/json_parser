/*
** EPITECH PROJECT, 2021
** JSONPARSER
** File description:
** json include file
*/

#ifndef JSON_PARSER_H_
    #define JSON_PARSER_H_

    char *get_buffer(char *path);

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
