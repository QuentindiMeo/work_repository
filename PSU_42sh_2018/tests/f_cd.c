/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** f_cd
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include "criterion_util.h"

Test(cd, cd_src, .init=cr_redirect_stdout)
{
    system("echo 'cd src\ncd ..' | ./42sh");
    cr_assert_stdout_eq_str(
        "[PSU_42sh_2018]$ [src]$ [PSU_42sh_2018]$ exit\n");
}

Test(cd, cd_lib_my, .init=cr_redirect_stdout)
{
    system("echo 'cd lib/my\ncd ../..' | ./42sh");
    cr_assert_stdout_eq_str("[PSU_42sh_2018]$ [my]$ [PSU_42sh_2018]$ exit\n");
}

Test(cd, cd_inexistant, .init=redirect_all_stdout)
{
    system("echo 'cd oijio' | ./42sh");
    cr_assert_stderr_eq_str("oijio: No such file or directory.\n");
    cr_assert_stdout_eq_str("[PSU_42sh_2018]$ [PSU_42sh_2018]$ exit\n");
}