/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2018
** File description:
** my shell main
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "mysh.h"

static int exit_shell(char **expr, char *entry, char *cwd, int id)
{
    my_putstr("exit\n");
    free(entry);
    free(cwd);
    if (!id) {
        free_arr(expr);
    }
    return (SUCCESS);
}

static int main_exec(char **expr, memory_t *memory, bool colors)
{
    int n = 0;
    int id = 0;
    char **command = NULL;

    while (n != -1) {
        command = get_nth_command(expr, n);
        id = (command == NULL) ? 0 : command_called(command[0]);
        if (id > 1 && id < 8) {
            memory->last_return = exec_program_made(command, id, memory);
            if (memory->last_return == CALL_EXIT)
                return (CALL_EXIT);
        } else
            memory->last_return = !command ? 1 : exec_program(command, colors);
        if (is_last_command(expr, n))
            n = -1;
        else
            n++;
    }
    free_arr(command);
    return (SUCCESS);
}

static int minishell(memory_t *memory, bool colors)
{
    size_t buff = 0;
    char **expr = NULL;
    char *cwd = malloc(sizeof(char) * 80);
    int ret_v = 0;
    char *entry = NULL;

    memory = memory;
    while (1) {
        print_prompt(cwd, colors);
        ret_v = getline(&entry, &buff, stdin);
        if (ret_v == ERROR)
            return (exit_shell(expr, entry, cwd, 1));
        add_history(entry, memory);
        expr = my_str_to_word_array(entry);
        ret_v = main_exec(expr, memory, colors);
        if (ret_v == CALL_EXIT)
            return (exit_shell(expr, entry, cwd, 0));
        free_arr(expr);
    }
}

int main(int ac, char **av)
{
    memory_t *memory = init_memory();
    int ret_v = SUCCESS;

    if (ac > 2)
        return (err_arguments());
    if (!memory)
        return (FAILURE);
    if (ac == 2 && my_str_isequal(av[1], "-C"))
        ret_v = minishell(memory, true);
    else
        ret_v = minishell(memory, false);
    free_memory(memory);
    return (ret_v);
}
