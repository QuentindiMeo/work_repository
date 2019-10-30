/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2018
** File description:
** my shell redirect output towards file
*/

#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include "my.h"
#include "mysh.h"

int redirect_output_towards_file(char ***command)
{
    int i;
    int fd;

    for (i = 0; strcmp((*command)[i], ">") != 0; i++);
    if (!(*command)[i + 1])
        return (FAILURE);
    fd = open((*command)[i + 1],
        O_WRONLY | O_CREAT | O_TRUNC, S_IRWXG | S_IRWXO | S_IRWXU);
    if (fd < 0)
        return (FAILURE);
    free((*command)[i]);
    free((*command)[i + 1]);
    (*command)[i] = NULL;
    (*command)[i + 1] = NULL;
    dup2(fd, 1);
    return (SUCCESS);
}
