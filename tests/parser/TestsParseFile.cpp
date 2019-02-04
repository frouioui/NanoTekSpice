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

Test(Parser, parse_file_easy_correct_file)
{
    std::vector<Component::ComponentSetting> settings = Parser::Parser("./tests/assets/exemple/public/primitives/5input_and.nts").Parse();

    cr_assert_eq(settings.at(0).type, Component::INPUT);
    cr_assert_eq(settings.at(0).value.compare("a"), 0);
    cr_assert_eq(settings.at(0).links.at(0).originName.compare("a"), 0);
    cr_assert_eq(settings.at(0).links.at(0).originPin, 1);
    cr_assert_eq(settings.at(0).links.at(0).destinationName.compare("gate"), 0);
    cr_assert_eq(settings.at(0).links.at(0).destinationPin, 1);
}

Test(Parser, parse_file_easy_correct_file_2)
{
    std::vector<Component::ComponentSetting> settings = Parser::Parser("./tests/assets/exemple/public/primitives/5input_and.nts").Parse();

    cr_assert_eq(settings.at(4).type, Component::INPUT);
    cr_assert_eq(settings.at(4).value.compare("e"), 0);
    cr_assert_eq(settings.at(4).links.at(0).originName.compare("e"), 0);
    cr_assert_eq(settings.at(4).links.at(0).originPin, 1);
    cr_assert_eq(settings.at(4).links.at(0).destinationName.compare("gate"), 0);
    cr_assert_eq(settings.at(4).links.at(0).destinationPin, 8);
}