/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** match stick artificial intelligence
*/

#include "../include/my.h"
#include "../include/matchstick.h"
#include <stdio.h>

static void play(data *game, int lines)
{
    uint i = 2 * lines - 1;
    uint k = 0;

    for (; game->board[game->played_line][i] != '|'; i--);
    for (uint j = game->played_matches; j > 0; j--) {
        game->board[game->played_line][i] = ' ';
        i--;
    }
    my_putstr("AI removed ");
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

static int is_last_line(data *game, int lines)
{
    uint ctr = 0;

    for (uint i = 0; i < lines; i++)
        if (game->matches[i] > 0)
            ctr++;
    if (ctr > 1)
        return (NO);
    return (YES);
}

static void smart_pick2(data *game)
{
    if (0 < game->matches[game->played_line - 1] - game->max_matches - 2) {
        game->played_matches = game->matches[game->played_line - 1];
        game->played_matches = game->played_matches - game->max_matches - 2;
    } else
        game->played_matches = 1;
}

static void smart_pick(data *game)
{
    if (game->matches[game->played_line - 1] == 1) {
        game->played_matches = 1;
        return;
    }
    if (game->matches[game->played_line - 1] == game->max_matches + 1)
        game->played_matches = game->max_matches;
    else if (game->matches[game->played_line - 1] == game->max_matches)
        game->played_matches = game->max_matches - 1;
    if (game->matches[game->played_line - 1] < game->max_matches)
        game->played_matches = game->matches[game->played_line - 1] - 1;
    else if (game->matches[game->played_line - 1] > game->max_matches * 2)
        game->played_matches = game->max_matches;
    else
        smart_pick2(game);
}

void ai_play(data *game, int lines)
{
    uint highest = 0;

    my_putstr("\n\nAI's turn...\n");
    for (uint i = 0; i <= lines; i++)
        if (highest < game->matches[i]) {
            highest = game->matches[i];
            game->played_line = i + 1;
        }
    if (!is_last_line(game, lines)) {
        if (game->matches[game->played_line - 1] >= game->max_matches)
            game->played_matches = game->max_matches;
        else
            game->played_matches = game->matches[game->played_line - 1];
    } else
        smart_pick(game);
    play(game, lines);
    update_array(game, lines);
}
