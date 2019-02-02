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

Test(Parser, clear_line_check_simple_line)
{
    Parser::LineParser lineParser("hello world");
    lineParser.ClearLine();

    cr_assert_eq(lineParser.GetLine().compare("hello world"), 0);
}

Test(Parser, clear_line_check_space_line)
{
    Parser::LineParser lineParser("hello    word toto");
    lineParser.ClearLine();

    cr_assert_eq(lineParser.GetLine().compare("hello word toto"), 0);
}

Test(Parser, clear_line_check_tab_line)
{
    Parser::LineParser lineParser("hello\t\tword");
    lineParser.ClearLine();

    cr_assert_eq(lineParser.GetLine().compare("hello\tword"), 0);
}

Test(Parser, clear_line_check_space_and_tab_line)
{
    Parser::LineParser lineParser("hello word \t  \t toto");
    lineParser.ClearLine();

    cr_assert_eq(lineParser.GetLine().compare("hello word toto"), 0);
}

Test(Parser, clear_line_check_space_end_of_line)
{
    Parser::LineParser lineParser("hello word toto   ");
    lineParser.ClearLine();

    cr_assert_eq(lineParser.GetLine().compare("hello word toto"), 0);
}