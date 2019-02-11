/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Unit tests on component 4069 compute
*/

#include <criterion/criterion.h>
#include <string>
#include <iostream>
#include "Circuit.hpp"
#include "Parser.hpp"
#include "ArgumentParser.hpp"
#include "Error.hpp"

Test(C4069, UndefinedOutput)
{
    Circuit circuit;
    Parser::container_setting_t settings;

    settings = Parser::Parser("./Tests/assets/exemple/public/basics/not.nts").Parse();
    circuit.createAllComponents(settings);
    cr_assert_eq(circuit.compute(1), nts::UNDEFINED);
}

Test(C4069, FalseOutput)
{
    Circuit circuit;
    Parser::container_setting_t settings;

    settings = Parser::Parser("./Tests/assets/exemple/public/basics/not.nts").Parse();
    circuit.createAllComponents(settings);
    circuit.setState("i0", "1");
    circuit.setState("i1", "1");
    circuit.setState("i2", "1");
    circuit.setState("i3", "1");
    circuit.setState("i4", "1");
    circuit.setState("i5", "1");
    cr_assert_eq(circuit.compute(1), nts::FALSE);
}

Test(C4069, TrueOutput)
{
    Circuit circuit;
    Parser::container_setting_t settings;

    settings = Parser::Parser("./Tests/assets/exemple/public/basics/not.nts").Parse();
    circuit.createAllComponents(settings);
    circuit.setState("i5", "0");
    cr_assert_eq(circuit.compute(1), nts::TRUE);
}

Test(C4069, SelfLink)
{
    Circuit circuit;
    Parser::container_setting_t settings;

    settings = Parser::Parser("./Tests/assets/exemple/errored/self_not.nts").Parse();
    circuit.createAllComponents(settings);
    circuit.setState("i5", "0");
    cr_assert_eq(circuit.compute(1), nts::TRUE);
}

Test(C4069, WrongLink)
{
    Circuit circuit;
    Parser::container_setting_t settings;

    settings = Parser::Parser("./Tests/assets/exemple/errored/false_not.nts").Parse();
    try {
        circuit.createAllComponents(settings);
    } catch (Error::Component::LinkError e) {
        cr_assert_str_eq(e.what(), "Door linked to itself");
    }
}