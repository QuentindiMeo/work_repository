/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** 42sh return value analyzer
*/

#include <wait.h>
#include <string.h>
#include "my.h"
#include "mysh.h"

int analyse_ret(int ret)
{
    int sig = 0;

    if (WIFEXITED(ret))
        return (WEXITSTATUS(ret));
    if (WIFSIGNALED(ret)) {
        sig = WTERMSIG(ret);
        my_puterr(strsignal(sig));
        if (WCOREDUMP(ret))
            my_puterr(WITH_COREDUMP);
        my_puterr("\n");
        return (sig + 128);
    }
    return (84);
}
