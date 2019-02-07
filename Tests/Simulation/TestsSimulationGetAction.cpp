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

Test(simulation, get_action_exit)
{
    Simulation::Simulation simu;
    Simulation::Action action;

    simu.SetLine("exit");
    simu.GetAction();
    action = simu.GetActionVariable();
    cr_assert_eq(action, Simulation::EXIT);
}

Test(simulation, get_action_simulate)
{
    Simulation::Simulation simu;
    Simulation::Action action;

    simu.SetLine("simulate");
    simu.GetAction();
    action = simu.GetActionVariable();
    cr_assert_eq(action, Simulation::SIMULATE);
}

Test(simulation, get_action_display)
{
    Simulation::Simulation simu;
    Simulation::Action action;

    simu.SetLine("display");
    simu.GetAction();
    action = simu.GetActionVariable();
    cr_assert_eq(action, Simulation::DISPLAY);
}

Test(simulation, get_action_loop)
{
    Simulation::Simulation simu;
    Simulation::Action action;

    simu.SetLine("loop");
    simu.GetAction();
    action = simu.GetActionVariable();
    cr_assert_eq(action == Simulation::LOOP, true);
}

Test(simulation, get_action_dump)
{
    Simulation::Simulation simu;
    Simulation::Action action;

    simu.SetLine("dump");
    simu.GetAction();
    action = simu.GetActionVariable();
    cr_assert_eq(action, Simulation::DUMP);
}

Test(simulation, get_action_invalid)
{
    Simulation::Simulation simu;
    Simulation::Action action;

    simu.SetLine("ferferfe");
    simu.GetAction();
    action = simu.GetActionVariable();
    cr_assert_eq(action, Simulation::NOTHING);
}