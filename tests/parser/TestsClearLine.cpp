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
    std::string ref = "hello word";
    std::string line = Parser::Parser::ClearLine(ref);

    cr_assert_eq(line.compare("hello word"), 0);
}

Test(Parser, clear_line_check_space_line)
{
    std::string ref = "hello    word toto";
    std::string line = Parser::Parser::ClearLine(ref);

    cr_assert_eq(line.compare("hello word toto"), 0);
}

Test(Parser, clear_line_check_tab_line)
{
    std::string ref = "hello\t\tword";
    std::string line = Parser::Parser::ClearLine(ref);

    cr_assert_eq(line.compare("hello\tword"), 0);
}

Test(Parser, clear_line_check_space_and_tab_line)
{
    std::string ref = "hello word \t  \t toto";
    std::string line = Parser::Parser::ClearLine(ref);

    cr_assert_eq(line.compare("hello word toto"), 0);
}

Test(Parser, clear_line_check_space_end_of_line)
{
    std::string ref = "hello word toto   ";
    std::string line = Parser::Parser::ClearLine(ref);

    cr_assert_eq(line.compare("hello word toto"), 0);
}