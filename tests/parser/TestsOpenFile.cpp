/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Test file of the open file function
*/

#include <criterion/criterion.h>
#include <fstream>
#include "Parser.hpp"

Test(Parser, open_file_check_file_open)
{
    std::ifstream file = Parser::Parser::openFile("./tests/assets/parser/test_file_open_file_check_file_open");

    cr_assert_eq(file.is_open(), 1);
}

Test(Parser, open_file_check_file_doest_exist)
{
    std::ifstream file = Parser::Parser::openFile("bad file");

    cr_assert_eq(file.is_open(), 0);
}

Test(Parser, open_file_check_content)
{
    std::ifstream file = Parser::Parser::openFile("./tests/assets/parser/test_file_open_file_check_content");
    char c = 0;
    int compare = 0;
    std::string content;

    while (file.get(c)) {
        content.push_back(c);
    }
    compare = content.compare("# this if the content of the file\n\nthis is also an other line\n\nend of the file here");
    cr_assert_eq(compare, 0);
}