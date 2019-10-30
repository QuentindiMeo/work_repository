/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** criterion_util
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void)
{
        cr_redirect_stdout();
        cr_redirect_stderr();
}