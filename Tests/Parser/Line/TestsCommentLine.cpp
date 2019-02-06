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

Test(Parser, comment_line_remove_comment_commented_line)
{
    Parser::LineParser line1("input toto #toto");
    Parser::LineParser line2(" \t output toto2    \t #toto3 oeoe");
    line1.RemoveComment();
    line2.RemoveComment();

    cr_assert_eq(line1.GetLine().compare("input toto "), 0);
    cr_assert_eq(line2.GetLine().compare(" \t output toto2    \t "), 0);
}

Test(Parser, comment_line_remove_comment_not_commented_line)
{
    Parser::LineParser line1("input toto ");
    Parser::LineParser line2(" \t output toto2    \t ");
    line1.RemoveComment();
    line2.RemoveComment();

    cr_assert_eq(line1.GetLine().compare("input toto "), 0);
    cr_assert_eq(line2.GetLine().compare(" \t output toto2    \t "), 0);
}