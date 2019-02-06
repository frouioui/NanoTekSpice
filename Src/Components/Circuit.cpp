	/*
** EPITECH PROJECT, 2019
** OOP_Nanotekspice
** File description:
** Circuit methods
*/

#include "Circuit.hpp"
#include "Parser.hpp"
#include "Factory.hpp"
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

void Circuit::createAllComponents(std::string path)
{
	std::vector<Component::ComponentSetting> settings = Parser::Parser(path).Parse();
	Factory fact;

	for (auto it  = settings.begin(); it != settings.end(); ++it) {
		_allComponents[it->name] = fact.createComponent(it->type, it->value);
		_allComponents[it->name]->setName(it->name);
	}

	linkAllComponents(settings);
}

nts::Tristate Circuit::compute()
{
	for (auto it = _allComponents.begin(); it != _allComponents.end(); ++it) {
		if (it->second->getType() == nts::OUTPUT)
			return it->second->compute();
	}
	return nts::UNDEFINED;
}

void Circuit::dump() const
{
	for (auto it = _allComponents.begin(); it != _allComponents.end(); ++it) {
		it->second->dump();
	}
}