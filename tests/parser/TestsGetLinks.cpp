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

    cr_assert_eq(links.at(0).OriginName.compare("a"), 0);
    cr_assert_eq(links.at(0).DestinationName.compare("gate"), 0);
    cr_assert_eq(links.at(0).OriginPin, 1);
    cr_assert_eq(links.at(0).DestinationPin, 1);

    cr_assert_eq(links.at(1).OriginName.compare("b"), 0);
    cr_assert_eq(links.at(1).DestinationName.compare("gate"), 0);
    cr_assert_eq(links.at(1).OriginPin, 1);
    cr_assert_eq(links.at(1).DestinationPin, 2);
}

Test(Parser, get_link_bigger_file)
{
    std::ifstream file("./tests/assets/parser/test_file_get_link_big");
    std::vector<Component::Link> links = Parser::Parser::GetLinks(file);

    cr_assert_eq(links.at(0).OriginName.compare("a"), 0);
    cr_assert_eq(links.at(0).DestinationName.compare("gate"), 0);
    cr_assert_eq(links.at(0).OriginPin, 1);
    cr_assert_eq(links.at(0).DestinationPin, 1);

    cr_assert_eq(links.at(1).OriginName.compare("b"), 0);
    cr_assert_eq(links.at(1).DestinationName.compare("fofo"), 0);
    cr_assert_eq(links.at(1).OriginPin, 1);
    cr_assert_eq(links.at(1).DestinationPin, 2);

    cr_assert_eq(links.at(2).OriginName.compare("c"), 0);
    cr_assert_eq(links.at(2).DestinationName.compare("gate"), 0);
    cr_assert_eq(links.at(2).OriginPin, 1);
    cr_assert_eq(links.at(2).DestinationPin, 6);

    cr_assert_eq(links.at(3).OriginName.compare("DU"), 0);
    cr_assert_eq(links.at(3).DestinationName.compare("c"), 0);
    cr_assert_eq(links.at(3).OriginPin, 1);
    cr_assert_eq(links.at(3).DestinationPin, 2);

    cr_assert_eq(links.at(4).OriginName.compare("e"), 0);
    cr_assert_eq(links.at(4).DestinationName.compare("gate"), 0);
    cr_assert_eq(links.at(4).OriginPin, 1);
    cr_assert_eq(links.at(4).DestinationPin, 1);

    cr_assert_eq(links.at(5).OriginName.compare("fofo"), 0);
    cr_assert_eq(links.at(5).DestinationName.compare("gate"), 0);
    cr_assert_eq(links.at(5).OriginPin, 1);
    cr_assert_eq(links.at(5).DestinationPin, 2);

    cr_assert_eq(links.at(6).OriginName.compare("EOW"), 0);
    cr_assert_eq(links.at(6).DestinationName.compare("gate"), 0);
    cr_assert_eq(links.at(6).OriginPin, 1);
    cr_assert_eq(links.at(6).DestinationPin, 1);

    cr_assert_eq(links.at(7).OriginName.compare("DU"), 0);
    cr_assert_eq(links.at(7).DestinationName.compare("c"), 0);
    cr_assert_eq(links.at(7).OriginPin, 1);
    cr_assert_eq(links.at(7).DestinationPin, 2);
}