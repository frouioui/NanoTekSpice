/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** False methodes
*/

#include "False.hpp"
#include "Error.hpp"

False::False()
{
	_output.insert(std::pair<std::size_t, nts::Pin>(1, {1, nts::FALSE, nullptr, -1}));
}

False::~False()
{
}

nts::Tristate False::compute(std::size_t pin)
{
	auto search = _output.find(pin);

	if (search == _output.end())
		throw Error::Component::ComputeError("No corresponding pin", " Input::compute");

	return search->second.state;
}

void False::setLink(std::size_t pin , nts::IComponent &other, std::size_t otherPin)
{
	auto search = _output.find(pin);

	if (search == _output.end())
		throw Error::Parser::FileError("No corresponding pin", "False::setLink");
	_output[pin] = {pin, nts::FALSE, &other, static_cast<int>(otherPin)};
	other.setInput(otherPin, *this, pin);
}

void False::dump() const
{
	std::cout << _name << std::endl;
}

void False::setInput(std::size_t, nts::IComponent &, std::size_t)
{
}

void False::setOutput(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	auto search = _output.find(pin);

	if (search == _output.end())
		throw Error::Parser::FileError("No corresponding pin", "False::setOutput");
	_output[pin] = {pin, nts::FALSE, &other, static_cast<int>(otherPin)};
}