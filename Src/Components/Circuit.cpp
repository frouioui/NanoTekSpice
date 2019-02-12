    /*
** EPITECH PROJECT, 2019
** OOP_Nanotekspice
** File description:
** Circuit methods
*/

#include "Circuit.hpp"
#include "Factory.hpp"
#include "Error.hpp"
#include <iostream>

Circuit::Circuit() :
Component::MyComponent(nts::CIRCUIT)
{
}

Circuit::~Circuit()
{
}

void Circuit::linkAllComponents(const std::vector<Component::ComponentSetting> &settings)
{
    Factory fact;

    fact.linkAllComponents(_allComponents, settings);
}

void Circuit::createAllComponents(const Parser::container_setting_t &settings)
{
    Factory fact;

    for (auto it  = settings.begin(); it != settings.end(); ++it) {
        _allComponents[it->name] = fact.createComponent(it->type, it->value);
        _allComponents[it->name]->setName(it->name);
    }

    linkAllComponents(settings);
}

nts::Tristate Circuit::compute(std::size_t)
{
    nts::Tristate state = nts::UNDEFINED;

    for (auto it = _allComponents.begin(); it != _allComponents.end(); ++it) {
        if (it->second->getType() == nts::OUTPUT) {
            try {
                state = it->second->compute();
            } catch (Error::Component::ComputeError e) {
                std::cerr << e.what() << " " << e.where() << std::endl;
                throw;
            }
        }
    }
    return state;
}

void Circuit::dump() const noexcept
{
    for (auto it = _allComponents.begin(); it != _allComponents.end(); ++it) {
        it->second->dump();
    }
}

void Circuit::displayState(std::size_t) const noexcept
{
    for (auto it = _allComponents.begin(); it != _allComponents.end(); ++it) {
        if (it->second->getType() == nts::OUTPUT) {
            it->second->displayState(1);
        }
    }
}

void Circuit::setState(const std::string &name, const std::string &state)
{
    bool found = false;
    for (auto it = _allComponents.begin(); it != _allComponents.end(); ++it) {
        if (name == it->first) {
            found = true;
            if (it->second->getType() != nts::INPUT)
                throw Error::Component::StateError("Can't change value for this type", "Circuit::setState");
            try {
                it->second->setState(state);
            } catch (Error::Component::StateError e) {
                std::cerr << e.what() << std::endl;
            }
        }
    }
    if (found == false)
        throw Error::Component::StateError("Unknown chipset", "Circuit::setState");
}