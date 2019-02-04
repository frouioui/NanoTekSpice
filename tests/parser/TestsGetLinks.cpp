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

Test(Parser, get_link_simple_file)
{
    std::ifstream file("./tests/assets/parser/test_file_get_link_simple");
    std::vector<Component::Link> links = Parser::Parser::GetLinks(file);

    cr_assert_eq(links.at(0).originName.compare("a"), 0);
    cr_assert_eq(links.at(0).destinationName.compare("gate"), 0);
    cr_assert_eq(links.at(0).originPin, 1);
    cr_assert_eq(links.at(0).destinationPin, 1);

    cr_assert_eq(links.at(1).originName.compare("b"), 0);
    cr_assert_eq(links.at(1).destinationName.compare("gate"), 0);
    cr_assert_eq(links.at(1).originPin, 1);
    cr_assert_eq(links.at(1).destinationPin, 2);
}

Test(Parser, get_link_bigger_file)
{
    std::ifstream file("./tests/assets/parser/test_file_get_link_big");
    std::vector<Component::Link> links = Parser::Parser::GetLinks(file);

    cr_assert_eq(links.at(0).originName.compare("a"), 0);
    cr_assert_eq(links.at(0).destinationName.compare("gate"), 0);
    cr_assert_eq(links.at(0).originPin, 1);
    cr_assert_eq(links.at(0).destinationPin, 1);

    cr_assert_eq(links.at(1).originName.compare("b"), 0);
    cr_assert_eq(links.at(1).destinationName.compare("fofo"), 0);
    cr_assert_eq(links.at(1).originPin, 1);
    cr_assert_eq(links.at(1).destinationPin, 2);

    cr_assert_eq(links.at(2).originName.compare("c"), 0);
    cr_assert_eq(links.at(2).destinationName.compare("gate"), 0);
    cr_assert_eq(links.at(2).originPin, 1);
    cr_assert_eq(links.at(2).destinationPin, 6);

    cr_assert_eq(links.at(3).originName.compare("DU"), 0);
    cr_assert_eq(links.at(3).destinationName.compare("c"), 0);
    cr_assert_eq(links.at(3).originPin, 1);
    cr_assert_eq(links.at(3).destinationPin, 2);

    cr_assert_eq(links.at(4).originName.compare("e"), 0);
    cr_assert_eq(links.at(4).destinationName.compare("gate"), 0);
    cr_assert_eq(links.at(4).originPin, 1);
    cr_assert_eq(links.at(4).destinationPin, 1);

    cr_assert_eq(links.at(5).originName.compare("fofo"), 0);
    cr_assert_eq(links.at(5).destinationName.compare("gate"), 0);
    cr_assert_eq(links.at(5).originPin, 1);
    cr_assert_eq(links.at(5).destinationPin, 2);

    cr_assert_eq(links.at(6).originName.compare("EOW"), 0);
    cr_assert_eq(links.at(6).destinationName.compare("gate"), 0);
    cr_assert_eq(links.at(6).originPin, 1);
    cr_assert_eq(links.at(6).destinationPin, 1);

    cr_assert_eq(links.at(7).originName.compare("DU"), 0);
    cr_assert_eq(links.at(7).destinationName.compare("c"), 0);
    cr_assert_eq(links.at(7).originPin, 1);
    cr_assert_eq(links.at(7).destinationPin, 2);
}