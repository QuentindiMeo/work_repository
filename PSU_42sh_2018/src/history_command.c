/*
** EPITECH PROJECT, 2018
** PSU_42sh_2018
** File description:
** my shell history command
*/

#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "mysh.h"

static char **event_not_found(char *command)
{
    char *new = NULL;

    if (command[0] == '!') {
        new = my_cut_str(command, 1, my_strlen(command));
        my_puterr(new);
        my_puterr(": Event not found.\n");
        free(new);
        return (NULL);
    }
    my_puterr(command);
    my_puterr(": Event not found.\n");
    return (NULL);
}

static void print_hist(char **command)
{
    if (command == NULL)
        return;
    for (int i = 0; command[i]; i++) {
        if (!command[i + 1]) {
            my_putstr(command[i]);
            my_putchar('\n');
            break;
        }
        my_putstr(command[i]);
        my_putchar(' ');
    }
}

static char **replace_history(char *gtl, char **command)
{
    char **entry = my_str_to_word_array(gtl);
    int size = 0;
    int enlarge = 0;
    char *first = my_cut_str(command[0], 1, my_strlen(command[0]));
    int j = 1;

    strcpy(command[0], first);
    for (; command[size]; size++);
    for (; entry[enlarge]; enlarge++);
    command = realloc(command, sizeof(char *) * (size + enlarge));
    for (int i = size + enlarge - 2; command[j]; i++) {
        command[i] = command[j];
        j++;
    }
    for (j = 0; entry[j]; j++)
        command[j] = strdup(entry[j]);
    free(first);
    return (command);
}

char **history(char **command)
{
    FILE *history_file = fopen(HISTORY_NAME, "r");
    char *entry = NULL;
    size_t buf = 0;
    struct stat sb;
    static int exc = 0;

    stat(HISTORY_NAME, &sb);
    if (history_file == NULL || sb.st_size == 0)
        return (event_not_found(command[0]));
    for (ssize_t read = 1; read > 0;) {
        read = getline(&entry, &buf, history_file);
        if (read > 1 && my_array_startswith(entry, command)) {
            command = replace_history(entry, command);
            exc++;
        }
    }
    print_hist(!exc ? NULL : command);
    return (!exc ? event_not_found(command[0]) : command);
}
