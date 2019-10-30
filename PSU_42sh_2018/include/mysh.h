/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** my shell headers
*/

#ifndef SHELL_H_
#define SHELL_H_
#include <stdbool.h>

#define DEFAULT_PATH "/usr/local/bin:/usr/bsd:/bin:/usr/bin"
#define HISTORY_NAME ".mysh_history"

#define SIGNALED_LAMBDA "Terminated\n"
#define EXIT_SIGNALED_LAMBDA 143

#define WITH_COREDUMP " (core dumped)"

typedef enum {
    CALL_EXIT = 2,
    CALL_CD = 3,
    CALL_ENV = 4,
    CALL_SETENV = 5,
    CALL_UNSETENV = 6,
    CALL_NL = 7,
} calls_t;

typedef enum {
    COMMAND_NOT_FOUND = 1,
    SEGFAULT = 139,
} return_values_shell_t;

struct call {
    char exit;
    char cd;
    char env;
    char setenv;
    char unsetenv;
    char nl;
};
typedef struct call call;

typedef struct memory_s {
    char *old_path;
    int last_return;
    int fd_history;
} memory_t;

typedef enum {
    HOME_BUFF = 64,
} buffer_sizes_t;

int execute_unsetenv(char **command);
int execute_setenv(char **command);
int execute_env(char **command);
int execute_cd(char **command, memory_t *memory);
int execute_echo(char **command, memory_t *memory);

int exec_program_made(char **command,
                        int builtin_id, memory_t *memory);
int exec_program(char **command, bool colors);
void exec_program2(char *bin, char **command, bool colors);
int analyse_ret(int ret);
bool is_runnable(const char *bin);

int command_called(char *command);
char **history(char **command);
char **get_nth_command(char **full_expr, int nth_command);

memory_t *init_memory(void);
void free_memory(memory_t *memory);

bool add_history(char *cmd, memory_t *memory);

int redirect_output_towards_file(char ***expr);
int redirect_file_towards_input(char ***expr);
int redirect_file_towards_input_via_heredoc(char ***expr);
int redirect_output_towards_end_of_file(char ***expr);

int is_there_double_right_redirect(char **expr);
int is_there_double_left_redirect(char **expr);
int is_there_simple_right_redirect(char **expr);
int is_there_simple_left_redirect(char **expr);
int get_next_path(char *buffer, const char *env_path, unsigned int int_buffer);
int is_last_command(char **, int);

void print_prompt(char *current_working_directory, bool colors);
void free_arr(char **array_to_be_freed);
int freer(char **command_array, char *getline_entry, char *get_cwd);

int too_many_args_cd(void);
int err_invalid_args_unsetenv(void);
int err_invalid_args_setenv(void);
int err_command_not_found(char *command_not_found);
int err_arguments(void);

#endif
