/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** checks if the current line contains an object
*/

int check_object(const char *line)
{
    if (line[0] && line[0] == '{')
        return (1);
    return (0);
}
