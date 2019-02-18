/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Unit tests on component 4008 compute
*/

#include <criterion/criterion.h>
#include <string>
#include <iostream>
#include "Circuit.hpp"
#include "Parser.hpp"
#include "ArgumentParser.hpp"
#include "Error.hpp"
#include "Factory.hpp"

Test(C4008, UndefinedOutput)
{
    Parser::container_setting_t settings;
    Factory fact;
    std::map<std::string, nts::ptrIComponent_t> allComponents;

    settings = Parser::Parser("./Tests/assets/exemple/public/basics/adder.nts").Parse();

    for (auto it  = settings.begin(); it != settings.end(); ++it) {
        allComponents[it->name] = fact.createComponent(it->type, it->value);
        allComponents[it->name]->setName(it->name);
    }
    fact.linkAllComponents(allComponents, settings);
    allComponents["cin"]->setState("0");
    allComponents["a0"]->setState("0");
    allComponents["b0"]->setState("0");
    allComponents["a1"]->setState("1");
    allComponents["b1"]->setState("0");
    allComponents["a2"]->setState("0");
    allComponents["b2"]->setState("1");
    allComponents["a3"]->setState("1");
    allComponents["b3"]->setState("1");
    cr_assert_eq(allComponents["adder"]->compute(10), nts::FALSE);
    cr_assert_eq(allComponents["adder"]->compute(11), nts::TRUE);
    cr_assert_eq(allComponents["adder"]->compute(12), nts::TRUE);
    cr_assert_eq(allComponents["adder"]->compute(13), nts::FALSE);
    allComponents["adder"]->dump();
    cr_assert_eq(allComponents["adder"]->compute(14), nts::TRUE);
}