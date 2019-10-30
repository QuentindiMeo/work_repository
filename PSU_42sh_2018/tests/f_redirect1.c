/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** f_redirect1
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>

Test(redirect, simple_to_file, .init=cr_redirect_stdout)
{
    FILE *tmp;

    system("echo 'echo hello > tmp1' | ./42sh");
    tmp = fopen("tmp1", "r");
    if (!tmp)
        cr_assert_fail("Cannot open tmp1 file\n");
    cr_assert_file_contents_eq_str(tmp, "hello\n");
    if (remove("tmp1") != 0)
        cr_log_warn("Cannot remove tmp1 file\n");
}

Test(redirect, simple_end_of_file, .init=cr_redirect_stdout)
{
    FILE *tmp;

    system("echo 'echo hello > tmp2\necho world >> tmp2' | ./42sh");
    tmp = fopen("tmp2", "r");
    if (!tmp)
        cr_assert_fail("Cannot open tmp2 file\n");
    cr_assert_file_contents_eq_str(tmp, "hello\nworld\n");
    if (remove("tmp2") != 0)
        cr_log_warn("Cannot remove tmp2 file\n");
}

Test(redirect, to_file_and_from_file, .init=cr_redirect_stdout)
{
    system("echo 'echo hello > tmp3\ncat < tmp3' | ./42sh");
    cr_assert_stdout_eq_str(
        "[PSU_42sh_2018]$ [PSU_42sh_2018]$ hello\n[PSU_42sh_2018]$ exit\n");
    if (remove("tmp3") != 0)
        cr_log_warn("Cannot remove tmp3 file\n");
}