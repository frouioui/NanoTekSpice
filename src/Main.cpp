/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Main file of the nanotekspice project
*/

#include <iostream>
#include "Parser.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
        return 1;
    std::vector<Component::ComponentSetting> settings = Parser::Parser(argv[1]).Parse();
    return 0;
}