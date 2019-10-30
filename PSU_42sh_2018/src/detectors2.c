/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2018
** File description:
** my shell redirect detectors
*/

#include "my.h"
#include "mysh.h"

int is_there_double_right_redirect(char **command)
{
    for (uint i = 0; command[i]; i++)
        if (my_str_isequal(command[i], ">>"))
            return (TRUE);
    return (FALSE);
}

int is_there_simple_right_redirect(char **command)
{
    for (uint i = 0; command[i]; i++)
        if (my_str_isequal(command[i], ">"))
            return (TRUE);
    return (FALSE);
}

int is_there_double_left_redirect(char **command)
{
    for (uint i = 0; command[i]; i++)
        if (command[i][0] && command[i][1] &&
            command[i][0] == '<' && command[i][1] == '<')
            return (TRUE);
    return (FALSE);
}

int is_there_simple_left_redirect(char **command)
{
    for (uint i = 0; command[i]; i++)
        if (my_str_isequal(command[i], "<"))
            return (TRUE);
    return (FALSE);
}
