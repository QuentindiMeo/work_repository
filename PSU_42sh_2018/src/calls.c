/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2018
** File description:
** my shell calls detection
*/

#include <stdlib.h>
#include "my.h"
#include "mysh.h"

static int free_struct(call *is_called)
{
    char ret_v = ERROR;

    if (is_called->unsetenv == TRUE)
        ret_v = CALL_UNSETENV;
    if (is_called->setenv == TRUE)
        ret_v = CALL_SETENV;
    if (is_called->env == TRUE)
        ret_v = CALL_ENV;
    if (is_called->cd == TRUE)
        ret_v = CALL_CD;
    if (is_called->exit == TRUE)
        ret_v = CALL_EXIT;
    if (is_called->nl == TRUE)
        ret_v = CALL_NL;
    free(is_called);
    if (ret_v == ERROR)
        return (COMMAND_NOT_FOUND);
    return (ret_v);
}

static call *init_struct(void)
{
    call *structure = malloc(sizeof(call));

    structure->exit = FALSE;
    structure->cd = FALSE;
    structure->env = FALSE;
    structure->setenv = FALSE;
    structure->unsetenv = FALSE;
    structure->nl = FALSE;
    return (structure);
}

int command_called(char *com)
{
    call *is_called = NULL;

    if (!com)
        return (CALL_NL);
    is_called = init_struct();
    if (my_str_isequal(com, "exit"))
        is_called->exit = TRUE;
    if (my_str_isequal(com, "cd") || my_str_isequal(com, "chdir"))
        is_called->cd = TRUE;
    if (my_str_isequal(com, "env"))
        is_called->env = TRUE;
    if (my_str_isequal(com, "setenv"))
        is_called->setenv = TRUE;
    if (my_str_isequal(com, "unsetenv"))
        is_called->unsetenv = TRUE;
    if (com && com[0] && com[0] == '\n')
        is_called->nl = TRUE;
    return (free_struct(is_called));
}
