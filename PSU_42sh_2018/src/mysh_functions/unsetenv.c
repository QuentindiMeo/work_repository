/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2018
** File description:
** my shell execute unsetenv builtin
*/

#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "my.h"
#include "mysh.h"

static int is_alphanum(char *s)
{
    for (int i = 0; s[i]; i++)
        if (!(s[i] >= 'a' && s[i] <= 'z') &&
            !(s[i] >= 'A' && s[i] <= 'Z') &&
            !(s[i] >= '0' && s[i] <= '9') &&
            s[i] != '_')
            return (FALSE);
    return (TRUE);
}

static int do_unsetenv(char *var)
{
    if (!is_alphanum(var)) {
        my_puterr("unsetenv: ");
        my_puterr("Variable name must contain alphanumeric characters.\n");
        return (1);
    }
    unsetenv(var);
    return (0);
}

int execute_unsetenv(char **command)
{
    if (!(command[1] && command[1][0]))
        return (err_invalid_args_unsetenv());
    for (int i = 1; command[i] && command[i][0]; i++)
        do_unsetenv(command[i]);
    return (SUCCESS);
}
