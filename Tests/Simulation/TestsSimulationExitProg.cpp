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

Test(simulation, no_exit_prog)
{
    Simulation::Simulation simu;
    bool isExit = false;

    simu.SetLine("no exit");
    simu.GetAction();
    isExit = simu.IsExitProg();
    cr_assert_eq(isExit, false);
}

Test(simulation, exit_prog)
{
    Simulation::Simulation simu;
    bool isExit = false;

    simu.SetLine("exit");
    simu.GetAction();
    isExit = simu.IsExitProg();
    cr_assert_eq(isExit, true);
}
