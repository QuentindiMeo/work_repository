/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** my shell binary runability checker
*/

#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>

bool is_runnable(const char *bin)
{
    struct stat statbuff;

    if (access(bin, X_OK | F_OK) != 0 || stat(bin, &statbuff) != 0)
        return (false);
    if ((statbuff.st_mode & __S_IFMT) == __S_IFREG)
        return (true);
    return (false);
}
