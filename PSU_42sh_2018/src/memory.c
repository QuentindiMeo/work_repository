/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** my shell memory structure manager
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "mysh.h"

memory_t *init_memory(void)
{
    memory_t *memory = malloc(sizeof(memory_t));

    if (!memory)
        return (NULL);
    memory->old_path = malloc(sizeof(char) * 80);
    memory->last_return = 0;
    memory->fd_history = open(HISTORY_NAME, O_RDWR | O_CREAT, 00600);
    if (memory->fd_history <= 0 || !memory->old_path)
        return (NULL);
    memory->old_path[0] = '\0';
    return (memory);
}

void free_memory(memory_t *memory)
{
    if (memory->old_path)
        free(memory->old_path);
    close(memory->fd_history);
    free(memory);
}
