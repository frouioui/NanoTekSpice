/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** True methodes
*/

#include "True.hpp"
#include "Error.hpp"

True::True()
{
	_output.insert(std::pair<std::size_t, nts::Pin>(1, {1, nts::TRUE, nullptr, -1}));
}

True::~True()
{
}

nts::Tristate True::compute(std::size_t pin)
{
	auto search = _output.find(pin);

	if (search == _output.end())
		throw Error::Component::ComputeError("No corresponding pin", " Input::compute");

	return search->second.state;
}

void True::setLink(std::size_t pin , nts::IComponent &other, std::size_t otherPin)
{
	auto search = _output.find(pin);

	if (search == _output.end())
		throw Error::Paser::FileError("No corresponding pin", "True::setLink");
	_output[pin] = {pin, nts::TRUE, &other, static_cast<int>(otherPin)};
	other.setInput(otherPin, *this, pin);
}

void True::dump() const
{
	std::cout << _name << std::endl;
}

void True::setInput(std::size_t, nts::IComponent &, std::size_t)
{
}

void True::setOutput(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	auto search = _output.find(pin);

	if (search == _output.end())
		throw Error::Paser::FileError("No corresponding pin", "True::setOutput");
	_output[pin] = {pin, nts::TRUE, &other, static_cast<int>(otherPin)};
}