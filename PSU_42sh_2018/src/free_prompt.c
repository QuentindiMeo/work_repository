/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2018
** File description:
** my shell freeing and prompt functions
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "mysh.h"

static void cutcwd(char *wd)
{
    uint i = 0;
    uint max;
    char *new = NULL;

    for (; wd[i]; i++);
    for (max = i; wd[i] != '/'; i--);
    i++;
    new = malloc(sizeof(char) * (max - i + 1));
    new[0] = '\0';
    for (; i < max; i++)
        my_charcat(new, wd[i]);
    my_strcpy(wd, new);
    free(new);
}

void print_prompt(char *wd, bool colors)
{
    getcwd(wd, 79);
    cutcwd(wd);
    my_putstr(colors ? "[\033[32m" : "[");
    my_putstr(wd);
    my_putstr(colors ? "\033[0m]$ " : "]$ ");
}

void free_arr(char **array)
{
    if (array) {
        for (uint i = 0; array[i]; i++)
            free(array[i]);
        free(array);
    }
}

int freer(char **command, char *entry, char *cwd)
{
    if (command) {
        for (uint i = 0; command[i]; i++)
            free(command[i]);
        free(command);
    }
    free(entry);
    free(cwd);
    return (SUCCESS);
}
