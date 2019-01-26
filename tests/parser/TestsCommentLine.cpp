/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Test file of the clear line function
*/

#include <criterion/criterion.h>
#include <string>
#include <iostream>
#include "Parser.hpp"

Test(Parser, comment_line_comment)
{
    cr_assert_eq(Parser::Parser::IsLineComment("# toto"), 1);
    cr_assert_eq(Parser::Parser::IsLineComment("  # toto"), 1);
    cr_assert_eq(Parser::Parser::IsLineComment(" \t \t   #"), 1);
}

Test(Parser, comment_line_not_comment)
{
    cr_assert_eq(Parser::Parser::IsLineComment(" toto"), 0);
    cr_assert_eq(Parser::Parser::IsLineComment("   toto"), 0);
    cr_assert_eq(Parser::Parser::IsLineComment("  feff "), 0);
}

Test(Parser, comment_line_remove_comment_commented_line)
{
    std::string line1 = "input toto #toto";
    std::string line2 = " \t output toto2    \t #toto3 oeoe";

    cr_assert_eq(Parser::Parser::RemoveComment(line1).compare("input toto "), 0);
    cr_assert_eq(Parser::Parser::RemoveComment(line2).compare(" \t output toto2    \t "), 0);
}

Test(Parser, comment_line_remove_comment_not_commented_line)
{
    std::string line1 = "input toto ";
    std::string line2 = " \t output toto2    \t ";

    cr_assert_eq(Parser::Parser::RemoveComment(line1).compare("input toto "), 0);
    cr_assert_eq(Parser::Parser::RemoveComment(line2).compare(" \t output toto2    \t "), 0);
}