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

Test(Parser, error_handling_check_type)
{
    cr_assert_throw(Parser::Parser::ParseFile("./tests/assets/exemple/errored/false_check_type"), Parser::FormatError);
}

Test(Parser, error_handling_check_name)
{
    cr_assert_throw(Parser::Parser::ParseFile("./tests/assets/exemple/errored/false_check_name"), Parser::FormatError);
}

Test(Parser, error_handling_split_line)
{
    cr_assert_throw(Parser::Parser::SplitLineInTwo("oneLine"), Parser::FormatError);
}