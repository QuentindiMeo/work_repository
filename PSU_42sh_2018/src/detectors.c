/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2018
** File description:
** my shell getbin and command id detectors
*/

#include "my.h"

int get_next_path(char *buff, const char *env_path, uint i)
{
    buff[0] = '\0';
    for (; env_path[i] && env_path[i] != ':'; i++)
        my_charcat(buff, env_path[i]);
    my_charcat(buff, '/');
    return (i + 1);
}

int is_last_command(char **expr, int n)
{
    int semicolons = 0;

    for (uint i = 0; expr[i]; i++)
        if (expr[i][0] == ';')
            semicolons++;
    if (n == semicolons)
        return (TRUE);
    return (FALSE);
}
