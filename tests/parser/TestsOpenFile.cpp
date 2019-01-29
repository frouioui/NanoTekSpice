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
    std::ifstream file = Parser::Parser::OpenFile("./tests/assets/parser/test_file_open_file_check_file_open");

    cr_assert_eq(file.is_open(), 1);
}

Test(Parser, open_file_check_file_does_not_exist_throw)
{
    cr_assert_throw(Parser::Parser::OpenFile("bad file"), Parser::FileError);
}

Test(Parser, open_file_check_file_does_not_exist_what_where)
{
    try {
        Parser::Parser::OpenFile("bad file");
    } catch (Parser::FileError &error) {
        cr_assert_eq(error.where().compare("OpenFile"), 0);
        cr_assert_str_eq(error.what(), "The file cannot be opened");
    }
}

Test(Parser, open_file_check_content)
{
    std::ifstream file = Parser::Parser::OpenFile("./tests/assets/parser/test_file_open_file_check_content");
    char c = 0;
    int compare = 0;
    std::string content;

    while (file.get(c)) {
        content.push_back(c);
    }
    compare = content.compare("# this if the content of the file\n\nthis is also an other line\n\nend of the file here");
    cr_assert_eq(compare, 0);
}