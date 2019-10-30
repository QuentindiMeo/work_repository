/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** f_miscellaneous
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(miscellaneous, default_path, .init=cr_redirect_stdout)
{
    system("echo 'echo hello' | env -i ./42sh");
    cr_assert_stdout_eq_str(
        "[PSU_42sh_2018]$ hello\n[PSU_42sh_2018]$ exit\n");
}