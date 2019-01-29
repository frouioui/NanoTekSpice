/*
** EPITECH PROJECT, 2019
** OPP_NANOTEKSPICE_2018
** File description:
** Component
*/

#include "Component4001.hpp"

Component4001::Component4001() : _state(nts::UNDEFINED)
{
}

Component4001::~Component4001()
{
}


nts::Tristate Component4001::compute(std::size_t pin)
{

}

void Component4001::setLink(std::size_t pin , nts::IComponent &other, std::size_t otherPin)
{

}

void Component4001::dump() const
{
	std::cout << _state << std::endl;
}
