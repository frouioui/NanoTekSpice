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

Test(simulation, simulation_display_prompt)
{
    Simulation::Simulation simu;

    cr_redirect_stdout();
    simu.DisplayPrompt();
    std::cout << std::endl;
    cr_assert_stdout_eq_str(">\n");
}