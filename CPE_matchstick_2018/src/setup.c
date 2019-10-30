/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** match stick setup functions
*/

#include "../include/my.h"
#include "../include/matchstick.h"

static void put_borders(char **board, int lines)
{
    uint height = lines + 2;
    uint length = 2 * lines;

    for (uint i = 1; i < (height - 1); i++) {
        board[i][0] = '*';
        board[i][length] = '*';
    }
}

static void put_space_or_match(char **board, int x, int y)
{
    if (board[x + 1][y - 1] == '|' &&
        board[x + 1][y + 1] == '|')
        board[x][y] = '|';
    else
        board[x][y] = ' ';
}

static void put_matches(char **board, int height, int length)
{
    int h = height - 2;

    for (int i = 1; i < (length - 1); i++)
        board[h][i] = '|';
    for (h--; h > 0; h--)
        for (int i = 1; i < (length - 1); i++)
            put_space_or_match(board, h, i);
}

void fill_board(data *game, int lines)
{
    uint height = lines + 2;
    uint length = 2 * lines + 1;

    for (uint i = 0; i < length; i++)
        game->board[0][i] = '*';
    for (uint i = 0; i < length; i++)
        game->board[height - 1][i] = '*';
    put_matches(game->board, height, length);
    put_borders(game->board, lines);
}
