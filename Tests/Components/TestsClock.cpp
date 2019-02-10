/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Unit tests on component 4081 compute with a clock component
*/

#include <criterion/criterion.h>
#include <string>
#include <iostream>
#include "Circuit.hpp"
#include "Parser.hpp"
#include "ArgumentParser.hpp"
#include "Error.hpp"

Test(Clock, UndefinedOutput)
{
    Circuit circuit;
    Parser::container_setting_t settings;

    settings = Parser::Parser("./Tests/assets/exemple/public/basics/clock.nts").Parse();
    circuit.createAllComponents(settings);
    circuit.compute(1);
    cr_assert_eq(circuit.compute(1), nts::UNDEFINED);
}

Test(Clock, FalseOutput)
{
    Circuit circuit;
    Parser::container_setting_t settings;

    settings = Parser::Parser("./Tests/assets/exemple/public/basics/clock.nts").Parse();
    circuit.createAllComponents(settings);
    cr_assert_eq(circuit.compute(1), nts::FALSE);
    circuit.setState("b", "0");
    cr_assert_eq(circuit.compute(1), nts::FALSE);
    cr_assert_eq(circuit.compute(1), nts::FALSE);
}

Test(Clock, TrueOutput)
{
    Circuit circuit;
    Parser::container_setting_t settings;

    settings = Parser::Parser("./Tests/assets/exemple/public/basics/clock.nts").Parse();
    circuit.createAllComponents(settings);
    circuit.setState("b", "1");
    circuit.compute(1);
    cr_assert_eq(circuit.compute(1), nts::TRUE);
    circuit.compute(1);
    cr_assert_eq(circuit.compute(1), nts::TRUE);
}