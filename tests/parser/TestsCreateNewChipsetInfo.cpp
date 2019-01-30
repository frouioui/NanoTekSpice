/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Tests file of the ChipsetHandler
*/

#include <criterion/criterion.h>
#include "Parser.hpp"

Test(Parser, new_chipset_info_input)
{
    Component::ComponentSetting info;

    info = Parser::Parser::CreateNewChipsetInfo("input", "4");
    cr_assert_eq(info.value.compare("4"), 0);
    cr_assert_eq(info.type, Component::Type::INPUT);
}

Test(Parser, new_chipset_info_output)
{
    Component::ComponentSetting info;

    info = Parser::Parser::CreateNewChipsetInfo("output", "343");
    cr_assert_eq(info.value.compare("343"), 0);
    cr_assert_eq(info.type, Component::Type::OUTPUT);
}

Test(Parser, new_chipset_info_clock)
{
    Component::ComponentSetting info;

    info = Parser::Parser::CreateNewChipsetInfo("clock", "76");
    cr_assert_eq(info.value.compare("76"), 0);
    cr_assert_eq(info.type, Component::Type::CLOCK);
}

Test(Parser, new_chipset_info_set)
{
    Component::ComponentSetting info;

    cr_assert_throw(Parser::Parser::CreateNewChipsetInfo("ifeef", "902323"), Parser::FormatError);
}