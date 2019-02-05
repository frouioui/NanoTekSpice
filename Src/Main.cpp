/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Main file of the nanotekspice project
*/

#include <iostream>
#include "Parser.hpp"
#include "ArgumentParser.hpp"
#include "Simulation.hpp"
#include "Error.hpp"

int main(int argc, char **argv)
{
    Simulation::Simulation simulator;
    Argument::ArgumentParser argParser(argc, argv);
    Argument::Argument args;

    try {
        args = argParser.GetArgument();
    } catch (Error::Error e) {
        std::cout << e.what() << std::endl;
        return (84);
    }

    simulator.Run();
    return 0;
}