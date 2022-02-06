/*
** EPITECH PROJECT, 2022
** json_parser2.0
** File description:
** utils functions
*/

static int is_uselesschar(char c)
{
    char useless_char[9] = "{}[] \t,\n";

    for (int i = 0; useless_char[i]; i++) {
        if (useless_char[i] == c)
            return (1);
    }
    return (0);
}

int is_emptyline(char *line)
{    
    for (int i = 0; line[i]; i++) {
        if (!is_uselesschar(line[i]))
            return (1);
    }
    return (0);
}

int is_invalidchar(char c)
{
    char valid_char[4] = "-,.\n";

    for (int i = 0; valid_char[i]; i++) {
        if (c == valid_char[i])
            return (0);
    }
    return (1);
}

