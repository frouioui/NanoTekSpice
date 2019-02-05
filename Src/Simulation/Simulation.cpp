/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Source file of the simulation class
*/

#include <iostream>
#include "Simulation.hpp"

Simulation::Simulation::Simulation()
{
}

Simulation::Simulation::~Simulation()
{
}

void Simulation::Simulation::DisplayPrompt() const
{
    std::cout << ">";
}

void Simulation::Simulation::Run()
{
    std::string line;

    Simulation::DisplayPrompt();
    while (std::getline(std::cin, line)) {
        Simulation::DisplayPrompt();
    }
}
