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
    std::vector<Component::ComponentSetting> settings = Parser::Parser::ParseFile("./tests/assets/exemple/public/primitives/5input_and.nts");
    return 0;
}