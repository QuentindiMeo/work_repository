/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2018
** File description:
** my shell redirect file towards input
*/

#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include "my.h"
#include "mysh.h"

int redirect_file_towards_input(char ***command)
{
    int i;
    int fd;

    for (i = 0; strcmp((*command)[i], "<") != 0; i++);
    if (!(*command)[i + 1])
        return (FAILURE);
    fd = open((*command)[i + 1], O_RDONLY);
    if (fd < 0)
        return (FAILURE);
    free((*command)[i]);
    free((*command)[i + 1]);
    (*command)[i] = NULL;
    (*command)[i + 1] = NULL;
    dup2(fd, 0);
    return (SUCCESS);
}
