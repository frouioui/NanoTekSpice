/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Output methodes
*/

#include "Output.hpp"
#include "Error.hpp"

Output::Output()
{
	_input.insert(std::pair<std::size_t, nts::Pin>(1, {1, nts::UNDEFINED, nullptr, -1}));
}

Output::~Output()
{
}

nts::Tristate Output::compute(std::size_t pin)
{
	return nts::UNDEFINED;
}

void Output::setLink(std::size_t pin , nts::IComponent &other, std::size_t otherPin)
{
	auto search = _input.find(pin);

	if (search == _input.end())
		throw Error::Parser::FileError("No corresponding pin", "Output::setLink");
	_input[pin] = {pin, nts::UNDEFINED, &other, static_cast<int>(otherPin)};
	other.setOutput(otherPin, *this, pin);
}

void Output::dump() const
{
	std::cout << _name << std::endl;
}

void Output::setInput(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	auto search = _input.find(pin);

	if (search == _input.end())
		throw Error::Parser::FileError("No corresponding pin", "Output::setInput");
	_input[pin] = {pin, nts::UNDEFINED, &other, static_cast<int>(otherPin)};
}

void Output::setOutput(std::size_t, nts::IComponent &, std::size_t)
{
}