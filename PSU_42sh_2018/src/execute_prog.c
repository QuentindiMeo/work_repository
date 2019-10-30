/*
** EPITECH PROJECT, 2018
** PSU_minishell1_2018
** File description:
** my shell execute program
*/

#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdio.h>
#include "my.h"
#include "mysh.h"

int exec_program_made(char **command, int id, memory_t *memory)
{
    switch (id) {
    case CALL_EXIT:
        return (CALL_EXIT);
    case CALL_CD:
        return (execute_cd(command, memory));
    case CALL_ENV:
        return (execute_env(command));
    case CALL_SETENV:
        return (execute_setenv(command));
    case CALL_UNSETENV:
        return (execute_unsetenv(command));
    case CALL_NL:
        return (SUCCESS);
    }
    return (FAILURE);
}

static char *access_check(char *command, const char *env_path)
{
    uint i = 5;
    int rv = 0;
    char *buff = malloc(sizeof(char) * my_strlen(env_path));

    for (char check = FALSE; check != TRUE;) {
        i = get_next_path(buff, env_path, i);
        my_strcat(buff, command);
        rv = access(buff, X_OK);
        if (!env_path[i] && rv == ERROR) {
            free(buff);
            return (NULL);
        }
        if (rv == SUCCESS)
            check = TRUE;
    }
    return (buff);
}

static char *get_binary(char **command, char **env)
{
    uint path = 0;

    for (uint i = 0; env[i]; i++) {
        if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T' &&
            env[i][3] == 'H' && env[i][4] == '=')
            break;
        path++;
    }
    if (!env[path])
        return (access_check(command[0], DEFAULT_PATH));
    return (access_check(command[0], env[path]));
}

static int redirect_treatment(char ***command)
{
    if (is_there_simple_right_redirect(*command))
        return (redirect_output_towards_file(command));
    if (is_there_simple_left_redirect(*command))
        return (redirect_file_towards_input(command));
    if (is_there_double_left_redirect(*command))
        return (redirect_file_towards_input_via_heredoc(command));
    if (is_there_double_right_redirect(*command))
        return (redirect_output_towards_end_of_file(command));
    return (-1);
}

int exec_program(char **command, bool colors)
{
    char *bin = NULL;
    pid_t pid;
    int ret_ex = 0;

    if (!strchr(command[0], '/'))
        bin = get_binary(command, __environ);
    else
        bin = strdup(command[0]);
    if (!bin || !is_runnable(bin))
        return (err_command_not_found(command[0]));
    pid = fork();
    if (!pid) {
        redirect_treatment(&command);
        exec_program2(bin, command, colors);
        exit(84);
    }
    pid = wait(&ret_ex);
    kill(pid, SIGKILL);
    free(bin);
    return (analyse_ret(ret_ex));
}
