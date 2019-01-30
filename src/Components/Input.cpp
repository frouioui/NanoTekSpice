/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Input methodes
*/

#include "Input.hpp"
#include "Error.hpp"

Input::Input(const std::string &name) : _name(name)
{
	_output.insert(std::pair<std::size_t, nts::Pin>(1, {nts::UNDEFINED, nullptr, -1}));
}

Input::~Input()
{
}

nts::Tristate Input::compute(std::size_t pin)
{
	return nts::UNDEFINED;
}

void Input::setLink(std::size_t pin , nts::IComponent &other, std::size_t otherPin)
{
	auto search = _output.find(pin);

	if (search == _output.end())
		throw Error::Paser::FileError("No corresponding pin", "Input::setLink");
	_output[pin] = {nts::UNDEFINED, &other, static_cast<int>(otherPin)};
	other.setInput(otherPin, *this, pin);
}

void Input::dump() const
{
	std::cout << _name << std::endl;
}

void Input::setOutput(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	auto search = _output.find(pin);

	if (search == _output.end())
		throw Error::Paser::FileError("No corresponding pin", "Input::setOutput");
	_output[pin] = {nts::UNDEFINED, &other, static_cast<int>(otherPin)};
}