/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Input methodes
*/

#include "Input.hpp"
#include "Error.hpp"

Input::Input()
{
	_output.insert(std::pair<std::size_t, nts::Pin>(1, {1, nts::UNDEFINED, nullptr, -1}));
}

Input::~Input()
{
}

nts::Tristate Input::compute(std::size_t pin)
{
	auto search = _output.find(pin);

	if (search == _output.end())
		throw Error::Component::ComputeError("No corresponding pin", " Input::compute");

	return search->second.state;
}

void Input::setLink(std::size_t pin , nts::IComponent &other, std::size_t otherPin)
{
	auto search = _output.find(pin);

	if (search == _output.end())
		throw Error::Parser::FileError("No corresponding pin", "Input::setLink");
	_output[pin] = {pin, nts::UNDEFINED, &other, static_cast<int>(otherPin)};
	other.setInput(otherPin, *this, pin);
}

void Input::dump() const
{
	std::cout << std::endl << "-----------------------------------------------" << std::endl;
	std::cout << "Input #" <<_name << std::endl;

	for (auto it = _output.begin(); it != _output.end(); ++it) {
		std::cout << "\tpin #" << it->second.pin << std::endl <<
		"\t-> state: " << it->second.state << std::endl <<
		"\t-> linked to: " << it->second.destinationName->getName() <<
		" - pin #" << it->second.destinationPin << std::endl;
	}
}

void Input::setInput(std::size_t, nts::IComponent &, std::size_t)
{
}

void Input::setOutput(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	auto search = _output.find(pin);

	if (search == _output.end())
		throw Error::Parser::FileError("No corresponding pin", "Input::setOutput");
	_output[pin] = {pin, nts::UNDEFINED, &other, static_cast<int>(otherPin)};
}

const std::string &Input::getName() const noexcept
{
	return _name;
}

void Input::setName(const std::string &name) noexcept
{
	_name = name;
}