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
    // Argument manager
    Argument::ArgumentParser argParser(argc, argv);
    Argument::Argument args;

    // Container for all the components and their link
    Parser::container_setting_t components;

    // Simulation class
    Simulation::Simulation simulator;

    try {
        // Get args
        args = argParser.GetArgument();

        // Parse file
        components = Parser::Parser(args.filename).Parse();
    } catch (Error::Error e) {
        std::cout << e.what() << std::endl;
        return (84);
    }

    // TODO: Give something to the simulator (circuit, components ...)
    try {
        simulator.createCircuit(components);
    }
    catch (Error::Component::CreationError e) {
        std::cerr << e.what() << " " << e.where() << std::endl;
        return 84;
    }
    catch (Error::Parser::FileError e) {
        std::cerr << e.what() << " " << e.where() << std::endl;
        return 84;
    }
    catch (Error::Component::LinkError e) {
        std::cerr << e.what() << " " << e.where() << std::endl;
        return 84;
    }

    try {
        simulator.setStates(args.intputValues);
    } catch (Error::Component::StateError e) {
       std::cerr << e.what() << std::endl;
       return 84;
    }

    simulator.Run();
    return 0;
}