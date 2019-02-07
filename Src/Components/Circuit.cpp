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

Circuit::Circuit()
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

nts::Tristate Circuit::compute()
{
    nts::Tristate state = nts::UNDEFINED;

    for (auto it = _allComponents.begin(); it != _allComponents.end(); ++it) {
        if (it->second->getType() == nts::OUTPUT) {
            state = it->second->compute();
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

void Circuit::setState(const std::string &name, const std::string &state)
{
    for (auto it = _allComponents.begin(); it != _allComponents.end(); ++it) {
        if (name == it->first) {
            if (it->second->getType() != nts::INPUT)
                throw Error::Component::StateError("Invalid type", "Circuit::setState");
            it->second->setState(state);
        }
    }
}