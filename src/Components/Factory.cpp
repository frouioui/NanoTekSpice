/*
** EPITECH PROJECT, 2019
** OPP_NANOTEKSPICE_2018
** File description:
** Factory functions
*/

#include "Factory.hpp"
#include "C4001.hpp"

Factory::Factory()
{
}

Factory::~Factory()
{
}


std::unique_ptr<nts::IComponent> create4001(const std::string &value)
{
	(void)value;
	std::unique_ptr<C4001> newC4001 = std::make_unique<C4001>();

	return newC4001;
}

// std::unique_ptr<nts::IComponent> create4008(const std::string &value)
// {
// 	std::unique_ptr<C4001> newC4008 = std::make_unique<C4008>(value);

// 	return newC4008;
// }

// std::unique_ptr<nts::IComponent> create4011(const std::string &value)
// {
// 	std::unique_ptr<C4011> newC4001 = std::make_unique<C4011>(value);

// 	return newC4011;
// }

// std::unique_ptr<nts::IComponent> create4013(const std::string &value)
// {

// }

// std::unique_ptr<nts::IComponent> create4017(const std::string &value)
// {

// }

// std::unique_ptr<nts::IComponent> create4030(const std::string &value)
// {

// }

// std::unique_ptr<nts::IComponent> create4040(const std::string &value)
// {

// }

// std::unique_ptr<nts::IComponent> create4069(const std::string &value)
// {

// }

// std::unique_ptr<nts::IComponent> create4071(const std::string &value)
// {

// }

// std::unique_ptr<nts::IComponent> create4081(const std::string &value)
// {

// }

// std::unique_ptr<nts::IComponent> create4094(const std::string &value)
// {

// }

// std::unique_ptr<nts::IComponent> create4514(const std::string &value)
// {

// }

// std::unique_ptr<nts::IComponent> create4801(const std::string &value)
// {

// }

// std::unique_ptr<nts::IComponent> create2716(const std::string &value)
// {

// }
