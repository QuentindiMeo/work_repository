/*
** EPITECH PROJECT, 2019
** PSU_minishell2_2018
** File description:
** fonctionnel
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include "criterion_util.h"

Test(command, bin_echo_hello, .init=cr_redirect_stdout)
{
    system("echo '/bin/echo hello' | ./42sh");
    cr_assert_stdout_eq_str(
        "[PSU_42sh_2018]$ hello\n[PSU_42sh_2018]$ exit\n");
}

Test(command, echo_hello, .init=cr_redirect_stdout)
{
    system("echo 'echo hello' | ./42sh");
    cr_assert_stdout_eq_str(
        "[PSU_42sh_2018]$ hello\n[PSU_42sh_2018]$ exit\n");
}

Test(command, empty, .init=cr_redirect_stdout)
{
    system("echo ' ' | ./42sh");
    cr_assert_stdout_eq_str("[PSU_42sh_2018]$ [PSU_42sh_2018]$ exit\n");
}

Test(command, inexistant, .init=redirect_all_stdout)
{
    system("echo 'ojoijo' | ./42sh");
    cr_assert_stderr_eq_str("ojoijo: Command not found.\n");
    cr_assert_stdout_eq_str("[PSU_42sh_2018]$ [PSU_42sh_2018]$ exit\n");
}

Test(command, semicolon, .init=cr_redirect_stdout)
{
    system(
    "echo 'echo hello ; echo hello ; echo hello ; echo hello' | ./42sh");
    cr_assert_stdout_eq_str(
    "[PSU_42sh_2018]$ hello\nhello\nhello\nhello\n[PSU_42sh_2018]$ exit\n");
}