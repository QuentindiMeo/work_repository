/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2018
** File description:
** my shell execute cd chdir builtin
*/

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "my.h"
#include "mysh.h"

static void stock_last(memory_t *memory)
{
    memory->old_path = getcwd(memory->old_path, 79);
}

static int cd_minus(memory_t *memory)
{
    char *temp = NULL;

    if (memory->old_path[0] == '\0') {
        my_puterr(": No such file or directory.\n");
        return (1);
    }
    temp = my_strdup(memory->old_path);
    stock_last(memory);
    if (chdir(temp) == ERROR) {
        my_puterr(temp);
        my_puterr(": ");
        my_puterr(strerror(errno));
        my_puterr(".\n");
        free(temp);
        return (1);
    }
    free(temp);
    return (SUCCESS);
}

static char *get_home(char **env)
{
    char *home = malloc(sizeof(char) * HOME_BUFF);
    char *buff = NULL;

    for (uint i = 0; i < 64; i++)
        home[i] = 0;
    for (uint i = 0; env[i]; i++)
        if (env[i][0] == 'H' && env[i][1] == 'O' && env[i][2] == 'M' &&
            env[i][3] == 'E' && env[i][4] == '=') {
            buff = env[i];
            break;
        }
    for (uint i = 5; buff[i]; i++)
        my_charcat(home, buff[i]);
    return (home);
}

int execute_cd(char **command, memory_t *memory)
{
    char *home = NULL;

    if (command[2])
        return (too_many_args_cd());
    if (command[1] && my_str_isequal(command[1], "-"))
        return (cd_minus(memory));
    stock_last(memory);
    if (!command[1] || (command[1] && my_str_isequal(command[1], "~"))) {
        home = get_home(__environ);
        chdir(home);
        free(home);
    } else if (chdir(command[1]) == ERROR) {
        my_puterr(command[1]);
        my_puterr(": ");
        my_puterr(strerror(errno));
        my_puterr(".\n");
        return (1);
    }
    return (SUCCESS);
}
