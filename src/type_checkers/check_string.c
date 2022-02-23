/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** check if the current line contains a string
*/

int check_string(const char *line)
{
    int is_quote = 0;
    int len = 0;

    for (; line[len] && (line[len] != ',' && line[len] != '\n'); len++) {
        if (line[len] == '"')
            is_quote++;
    }
    if (is_quote == 2)
        return (1);
    return (-1);
}
