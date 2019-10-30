/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2018
** File description:
** my shell execute env builtin
*/

#include <unistd.h>
#include "my.h"

int execute_env(char **command)
{
    if (command[1])
        return (SUCCESS);
    for (uint i = 0; __environ[i] && __environ[i][0]; i++) {
        my_putstr(__environ[i]);
        my_putchar('\n');
    }
    return (SUCCESS);
}
