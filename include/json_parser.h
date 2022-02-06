/*
** EPITECH PROJECT, 2021
** JSONPARSER
** File description:
** json include file
*/

#include "linked_list.h"

#ifndef JSON_PARSER_H_
    #define JSON_PARSER_H_

    char **get_line_array(char *path);

    list_t *get_data(char **buffer);

    /*----------SETTERS---------*/

    int set_key(const char *line, node_t *new_node, int line_index);

    int set_value(const char *line, node_t *new_node, int line_index);

    /*-------------UTILS---------*/

    int is_emptyline(char *line);
    
    int is_invalidchar(char c);

    /*----------VALUE_GETTERS-----------*/

    void get_float(const char *line, node_t *new_node);

    void get_int(const char *line, node_t *new_node);

    void get_singlechar(const char *line, node_t *new_node);

    void get_string(const char *line, node_t *new_node);

#endif
