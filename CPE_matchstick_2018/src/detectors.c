/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** match stick detectors
*/

#include "../include/my.h"
#include "../include/matchstick.h"
#include <stdio.h>

static int is_a_match(char const c)
{
    if (c == '|')
        return (TRUE);
    return (FALSE);
}

static int count_matches(char *line, int length)
{
    int matches = 0;

    for (uint i = 1; i < length; i++)
        if (is_a_match(line[i]))
            matches++;
    return (matches);
}

void update_array(data *game, int lines)
{
    int length = 2 * lines;

    for (uint i = 1; i <= lines; i++)
        game->matches[i - 1] = count_matches(game->board[i], length);
}

int is_there_any_match_left(data *game, int lines)
{
    uint matches = 0;

    for (uint x = 1; x <= lines; x++)
        for (uint y = 1; game->board[x][y] != '*'; y++)
            matches += is_a_match(game->board[x][y]);
    if (matches)
        return (YES);
    return (NO);
}

int switch_turn(int id)
{
    int save = id;

    if (save == USER)
        id = AI;
    if (save == AI)
        id = USER;
    return (id);
}
