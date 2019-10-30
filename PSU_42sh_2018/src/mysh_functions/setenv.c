/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2018
** File description:
** my shell execute setenv builtin
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

static int do_setenv(char *var, char *value)
{
    if (!is_alphanum(var) || !is_alphanum(value)) {
        my_puterr("setenv: ");
        my_puterr("Variable name must contain alphanumeric characters.\n");
        return (1);
    }
    setenv(var, value, 1);
    return (0);
}

int execute_setenv(char **command)
{
    int ret_v = 0;
    char *generic[] = {"env\0", NULL};

    if (!command[1]) {
        execute_env(generic);
        return (SUCCESS);
    } else if (command[2] && command[3])
        return (err_invalid_args_setenv());
    if (!command[2])
        ret_v = do_setenv(command[1], "");
    else
        ret_v = do_setenv(command[1], command[2]);
    if (ret_v == ERROR) {
        my_puterr(command[0]);
        my_puterr(": ");
        my_puterr(strerror(errno));
        my_puterr(".\n");
    }
    return (ret_v);
}
