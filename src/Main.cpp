/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Main file of the nanotekspice project
*/

#include <istream>
#include "Parser.hpp"

int main(int argc, char **argv)
{
    std::ifstream file("./tests/assets/parser/test_file_get_link_big");

    Parser::Parser::GetLinks(file);
    return 0;
}