/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Test the IsUseless function
*/

#include "criterion/criterion.h"
#include "Parser.hpp"

Test(Parser, checker_line_comment)
{
    cr_assert_eq(Parser::Checker("# toto").IsUseless(), 1);
    cr_assert_eq(Parser::Checker("  # toto").IsUseless(), 1);
    cr_assert_eq(Parser::Checker(" \t \t   #").IsUseless(), 1);
}

Test(Parser, checker_line_not_comment)
{
    cr_assert_eq(Parser::Checker(" toto").IsUseless(), 0);
    cr_assert_eq(Parser::Checker("   toto").IsUseless(), 0);
    cr_assert_eq(Parser::Checker("  feff ").IsUseless(), 0);
}

Test(Parser, checker_line_empty)
{
    cr_assert_eq(Parser::Checker(" ").IsUseless(), 1);
    cr_assert_eq(Parser::Checker("  \t ").IsUseless(), 1);
    cr_assert_eq(Parser::Checker("").IsUseless(), 1);
}
