/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** match stick setup functions 2
*/

#include "../include/my.h"
#include "../include/matchstick.h"

static int is_a_match(char const c)
{
    if (c == '|')
        return (TRUE);
    return (FALSE);
}

void fill_matches_array(data *game, int lines, int max)
{
    uint length = 2 * lines;
    uint matches = 0;

    game->max_matches = max;
    for (uint i = 1; i <= lines; i++) {
        for (uint j = 1; j < length; j++)
            matches += is_a_match(game->board[i][j]);
        game->matches[i - 1] = matches;
        matches = 0;
    }
}
