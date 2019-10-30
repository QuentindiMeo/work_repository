/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2018
** File description:
** my shell error functions
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

int too_many_args_cd(void)
{
    my_puterr("cd: Too many arguments.\n");
    return (FAILURE);
}

int err_invalid_args_unsetenv(void)
{
    my_puterr("error: invalid number of arguments passed to command "
            "‘unsetenv’\n");
    return (FAILURE);
}

int err_invalid_args_setenv(void)
{
    my_puterr("error: invalid number of arguments passed to command "
            "‘setenv’\n");
    return (FAILURE);
}

int err_command_not_found(char *command)
{
    my_puterr(command);
    my_puterr(": Command not found.\n");
    return (COMMAND_NOT_FOUND);
}

int err_arguments(void)
{
    my_puterr("mysh: too arguments\n");
    return (FAILURE);
}
