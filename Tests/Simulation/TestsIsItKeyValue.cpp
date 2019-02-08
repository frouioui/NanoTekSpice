/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Test file of the clear line function
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string>
#include <iostream>
#include "Simulation.hpp"
#include "ArgumentParser.hpp"

Test(simulation, simulation_is_key_value_false)
{
    Simulation::Simulation simu;
    bool isExit = false;

    simu.SetLine("no exit");
    cr_assert_eq(simu.IsItKeyValue(), false);
}

Test(simulation, simulation_is_key_value_false_2)
{
    Simulation::Simulation simu;
    bool isExit = false;

    simu.SetLine("no exit wifn eofe mf je je");
    cr_assert_eq(simu.IsItKeyValue(), false);
}

Test(simulation, simulation_is_key_value_true)
{
    Simulation::Simulation simu;
    bool isExit = false;

    simu.SetLine("toto=toto");
    cr_assert_eq(simu.IsItKeyValue(), true);
}

Test(simulation, simulation_is_key_value_true_2)
{
    Simulation::Simulation simu;
    bool isExit = false;

    simu.SetLine("q=3");
    cr_assert_eq(simu.IsItKeyValue(), true);
}