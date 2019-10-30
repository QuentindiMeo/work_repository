/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2018
** File description:
** my shell execute program 2
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"
#include "mysh.h"

void exec_program2(char *bin, char **command, bool colors)
{
    int i = 0;

    for (; command[i] != NULL; i++);
    if (my_str_isequal(command[0], "ls") && colors) {
        command = realloc(command, (sizeof(char *) * (i + 2)));
        command[i + 1] = NULL;
        for (int j = i; j > 1; j--)
            command[j] = command[j - 1];
        command[1] = strdup("--color");
    }
    execve(bin, command, __environ);
}