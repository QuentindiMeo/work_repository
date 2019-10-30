/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2018
** File description:
** my shell redirect file towards input via heredoc
*/

#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "my.h"
#include "mysh.h"

static char *read_input_loop(char *input, char *key)
{
    ssize_t read = 1;
    size_t n = 0;
    char *buff = NULL;

    while ((read = getline(&buff, &n, stdin)) > 0) {
        if (strncmp(buff, key, strlen(key) - 1) == 0)
            break;
        input = realloc(input, sizeof(char) * (strlen(input) + read + 1));
        if (!input)
            return (NULL);
        strcat(input, buff);
        strcat(input, "\0");
        write(1, "? ", 2);
    }
    return ("o");
}

char *read_input(char *key)
{
    char *input = malloc(sizeof(char));
    ssize_t read;

    if (!input)
        return (NULL);
    input[0] = '\0';
    write(1, "? ", 2);
    if (read_input_loop(input, key) == NULL) {
        free(input);
        return (NULL);
    }
    read = strlen(input);
    input = realloc(input, sizeof(char) * (read + 1));
    input[read] = '\0';
    return (input);
}

static void write_dup(int fd, char *input, char eof)
{
    write(fd, input, strlen(input));
    write(fd, &eof, 1);
    dup2(fd, 0);
}

int redirect_file_towards_input_via_heredoc(char ***command)
{
    int i = 0;
    int fd = 0;
    char *key = NULL;
    char *input = NULL;
    char eof = 0;

    for (; strcmp((*command)[i], "<<") != 0; i++);
    if (!(*command)[i + 1])
        return (FAILURE);
    key = (*command)[i + 1];
    input = read_input(key);
    fd = dup(0);
    if (fd < 0 || !input)
        return (FAILURE);
    free((*command)[i]);
    free((*command)[i + 1]);
    (*command)[i] = NULL;
    (*command)[i + 1] = NULL;
    write_dup(fd, input, eof);
    return (SUCCESS);
}
