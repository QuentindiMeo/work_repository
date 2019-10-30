/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** matchstick headers
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

struct data {
    char **board;
    int *matches;
    int max_matches;
    int played_line;
    int played_matches;
};
typedef struct data data;

typedef enum {
    USER = 1,
    AI = 2,
    W_USER = 1,
    W_AI = 2,
    EOF = -1,
} return_values_matchstick_t;

void ai_play(data *, int);
int game_loop(data *, int);

int switch_turn(int);
int played_matches_invalid(data *, int, char *);
int line_is_out_of_range(int, int, char *);
void update_array(data *, int);
int is_there_any_match_left(data *, int);

void fill_matches_array(data *, int, int);
void fill_board(data *, int);

void freer(data *, int);
data *mallocator(int);

int err_not_enough_matches(void);
int err_positive_matches(void);
int err_positive_expected(int);
int err_out_of_range(void);
int err_arguments(void);

#endif
