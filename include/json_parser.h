/*
** EPITECH PROJECT, 2021
** JSONPARSER
** File description:
** json include file
*/

#include "linked_list.h"

#ifndef JSON_PARSER_H_
    #define JSON_PARSER_H_

    #define is_number(c) (c >= '0' && c <= '9') ? 1 : 0

    char *get_buffer(char *path);

    int stringify(char **buffer);

    list_t *get_data(char *buffer);

    /*----------TYPE_CHECKERS-----------*/

    void check_type(const char *line, node_t *tmp);

    int check_array(const char *line);

    int check_object(const char *line);

    int check_double(const char *line);

    int check_int(const char *line);

    int check_string(const char *line);

    /*----------VALUE_GETTERS-----------*/

    int get_value(const char *buffer, int index, node_t *tmp);

    int get_key(const char *buffer, int index, node_t *tmp);

    int get_array(const char *line, node_t *new_node, int nb_elements);

    int get_object(const char *line, node_t *new_node, int nb_elements);

    int get_double(const char *line, node_t *new_node, int nb_elements);

    int get_int(const char *line, node_t *new_node, int nb_elements);

    int get_string(const char *line, node_t *new_node, int nb_elements);

#endif
