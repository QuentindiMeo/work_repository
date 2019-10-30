/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** match stick game loop
*/

#include "../include/my.h"
#include "../include/matchstick.h"
#include <stdio.h>
#include <stdlib.h>

static void play(data *game, int lines)
{
    uint i = 2 * lines - 1;
    uint k = 0;

    for (; game->board[game->played_line][i] != '|'; i--);
    for (uint j = game->played_matches; j > 0; j--) {
        game->board[game->played_line][i] = ' ';
        i--;
    }
    my_putstr("Player removed ");
    my_put_nbr(game->played_matches);
    my_putstr(" match(es) from line ");
    my_put_nbr(game->played_line);
    my_putchar('\n');
    for (uint k = 0; k <= lines; k++) {
        my_putstr(game->board[k]);
        my_putchar('\n');
    }
    my_putstr(game->board[k]);
}

static int get_line(data *game, int lines)
{
    char *entry = NULL;
    size_t buff = 0;
    int ret_v;

    game->played_line = 0;
    my_putstr("Line: ");
    while (!game->played_line) {
        ret_v = getline(&entry, &buff, stdin);
        if (ret_v == ERROR)
            return (EOF);
        game->played_line = my_getnbr(entry);
        if (line_is_out_of_range(game->played_line, lines, entry))
            game->played_line = 0;
    }
    free(entry);
    return (SUCCESS);
}

static int get_matches(data *game, int lines)
{
    char *entry = NULL;
    size_t buff = 0;
    int ret_v;

    game->played_matches = 0;
    my_putstr("Matches: ");
    while (!game->played_matches) {
        ret_v = getline(&entry, &buff, stdin);
        if (ret_v == ERROR)
            return (EOF);
        game->played_matches = my_getnbr(entry);
        if (played_matches_invalid(game, lines, entry)) {
            get_line(game, lines);
            get_matches(game, lines);
            return (SUCCESS);
        }
    }
    free(entry);
    return (SUCCESS);
}

static int user_play(data *game, int lines)
{
    int ret_v;

    my_putstr("\n\nYour turn:\n");
    ret_v = get_line(game, lines);
    if (ret_v == EOF)
        return (EOF);
    ret_v = get_matches(game, lines);
    if (ret_v == EOF)
        return (EOF);
    play(game, lines);
    update_array(game, lines);
    return (SUCCESS);
}

int game_loop(data *game, int lines)
{
    uchar whose_turn = AI;
    int ret_v;

    for (uchar over = FALSE; over != TRUE;) {
        whose_turn = switch_turn(whose_turn);
        if (whose_turn == USER)
            ret_v = user_play(game, lines);
        else
            ai_play(game, lines);
        if (ret_v == EOF)
            return (EOF);
        if (is_there_any_match_left(game, lines) == NO)
            over = TRUE;
    }
    whose_turn = switch_turn(whose_turn);
    return (whose_turn);
}
