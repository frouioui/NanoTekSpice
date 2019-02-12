/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Source file of the simulation class
*/

#include <iostream>
#include "Simulation.hpp"
#include "Factory.hpp"
#include "ArgumentParser.hpp"
#include "Error.hpp"

Simulation::Simulation::Simulation()
{
}

Simulation::Simulation::~Simulation()
{
}

bool Simulation::Simulation::IsItKeyValue() const
{
    size_t pos = 0;

    pos = _line.find('=', 0);
    if (pos == std::string::npos) {
        return false;
    }
    return true;
}

bool Simulation::Simulation::IsExitProg() const
{
    return _action == EXIT;
}

void Simulation::Simulation::DisplayPrompt() const
{
    std::cout << "> ";
}

void Simulation::Simulation::GetAction()
{
    for (unsigned int i = 0; i < NUMBER_OF_ACTION; i++) {
        if (_line.compare(KEYWORD_ACTION[i]) == 0) {
            if (i == 0)
                _action = EXIT;
            else if (i == 1)
                _action = SIMULATE;
            else if (i == 2)
                _action = DISPLAY;
            else if (i == 3)
                _action = LOOP;
            else if (i == 4)
                _action = DUMP;
            else
                _action = NOTHING;
        } else if (IsItKeyValue() == true) {
            _action = SET_VALUE;
        }
    }
}

void Simulation::Simulation::dump() const noexcept
{
    _circuit->dump();
}

void Simulation::Simulation::display() const noexcept
{
    _circuit->displayState(1);
}

void Simulation::Simulation::simulate()
{
    _circuit->compute(1);
}

void Simulation::Simulation::setStates(const std::map<std::string, std::string> &inputValues)
{
    for (auto it = inputValues.begin(); it != inputValues.end(); ++it) {
        _circuit->setState(it->first, it->second);
    }
}

void Simulation::Simulation::createCircuit(const Parser::container_setting_t &settings)
{
    Factory factory;

    _circuit = factory.createComponent(nts::CIRCUIT, "");
    _circuit->createAllComponents(settings);
}

void Simulation::Simulation::AnalyseAction()
{
    std::map<std::string, std::string> setValue;

    if (_action == DUMP)
        dump();
    if (_action == SET_VALUE) {
        Argument::ArgumentParser argParser;
        setValue = argParser.GetInputValue(_line);
        try {
            setStates(setValue);
        } catch (Error::Component::StateError e) {
            std::cerr << e.what() << std::endl;
        }
    }
    if (_action == SIMULATE)
        simulate();
}

void Simulation::Simulation::Run()
{
    bool exitProg = false;

    // Run single simulation
    simulate();

    // Display the prompt for the first line
    Simulation::DisplayPrompt();

    while (exitProg == false && std::getline(std::cin, _line)) {
        // Examine the user's line and redirect to the right function
        GetAction();
        if (IsExitProg() == true)
            return;

        // Display a new prompt
        Simulation::DisplayPrompt();
    }
}