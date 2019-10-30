/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** my shell history file manager
*/

#include <errno.h>
#include <string.h>
#include <unistd.h>
#include "my.h"
#include "mysh.h"

bool add_history(char *cmd, memory_t *memory)
{
    if (cmd[0] == '!' || cmd[0] == '\n')
        return (true);
    if (lseek(memory->fd_history, 0, SEEK_END) == -1) {
        my_puterr(strerror(errno));
        return (false);
    }
    if (write(memory->fd_history, cmd, strlen(cmd)) == -1) {
        my_puterr(strerror(errno));
        return (false);
    }
    return (true);
}
