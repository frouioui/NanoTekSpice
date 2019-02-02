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
    std::vector<Component::ComponentSetting> settings = Parser::Parser("./tests/assets/exemple/public/primitives/5input_and.nts").Parse();

    for (unsigned int i = 0; i < settings.size(); i++) {
        std::cout << settings[i].type << " " << settings[i].value << std::endl;
    }
    return 0;
}