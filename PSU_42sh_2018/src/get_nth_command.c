/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2018
** File description:
** my shell get n-th command
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "mysh.h"

static int get_crsr(char **expr, int n)
{
    int crsr = 0;
    int k = 0;

    for (crsr = 0; expr[crsr] && k != n; crsr ++)
        if (expr[crsr][0] == ';')
            k++;
    return (crsr);
}

char **get_nth_command(char **expr, int n)
{
    char **command = NULL;
    int crsr = 0;
    int crsr2;

    if (!n)
        for (uint i = 0; expr[i] && expr[i][0] != ';'; i++)
            crsr++;
    else {
        crsr = get_crsr(expr, n);
        for (crsr2 = crsr; expr[crsr2] && expr[crsr2][0] != ';'; crsr2 += 1);
    }
    if (!n)
        command = my_cut_word_array(expr, 1, crsr);
    else
        command = my_cut_word_array(expr, crsr + 1, crsr2);
    if (command[0] && command[0][0] == '!')
        command = history(command);
    return (command);
}
