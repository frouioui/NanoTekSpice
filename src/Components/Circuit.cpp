/*
** EPITECH PROJECT, 2019
** OOP_Nanotekspice
** File description:
** Circuit methods
*/

#include "Circuit.hpp"
#include "Parser.hpp"
#include "Factory.hpp"

Circuit::Circuit()
{
}

Circuit::~Circuit()
{
}

std::map<std::string, nts::ptrIComponent_t> Circuit::createAllComponents(std::string path)
{
	std::vector<Component::ComponentSetting> settings = Parser::Parser(path).Parse();
	std::map<std::string, nts::ptrIComponent_t> _allComponents = Factory::Factory().createAllComponents(settings);
}