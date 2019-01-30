/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** C4001 methodes
*/

#include "C4001.hpp"
#include "Error.hpp"

C4001::C4001()
{
	_input.insert(std::pair<std::size_t, nts::Pin>(1, {nts::UNDEFINED, nullptr, -1}));
	_input.insert(std::pair<std::size_t, nts::Pin>(2, {nts::UNDEFINED, nullptr, -1}));
	_input.insert(std::pair<std::size_t, nts::Pin>(5, {nts::UNDEFINED, nullptr, -1}));
	_input.insert(std::pair<std::size_t, nts::Pin>(6, {nts::UNDEFINED, nullptr, -1}));
	_input.insert(std::pair<std::size_t, nts::Pin>(8, {nts::UNDEFINED, nullptr, -1}));
	_input.insert(std::pair<std::size_t, nts::Pin>(9, {nts::UNDEFINED, nullptr, -1}));
	_input.insert(std::pair<std::size_t, nts::Pin>(12, {nts::UNDEFINED, nullptr, -1}));
	_input.insert(std::pair<std::size_t, nts::Pin>(13, {nts::UNDEFINED, nullptr, -1}));

	_output.insert(std::pair<std::size_t, nts::Pin>(3, {nts::UNDEFINED, nullptr, -1}));
	_output.insert(std::pair<std::size_t, nts::Pin>(4, {nts::UNDEFINED, nullptr, -1}));
	_output.insert(std::pair<std::size_t, nts::Pin>(10, {nts::UNDEFINED, nullptr, -1}));
	_output.insert(std::pair<std::size_t, nts::Pin>(11, {nts::UNDEFINED, nullptr, -1}));
}

C4001::~C4001()
{
}


nts::Tristate C4001::compute(std::size_t pin)
{
	return nts::UNDEFINED;
}

void C4001::setLink(std::size_t pin , nts::IComponent &other, std::size_t otherPin)
{
	auto search = _input.find(pin);

	if (search  != _input.end()) {
		_input[pin] = {nts::UNDEFINED, &other, static_cast<int>(otherPin)};
		other.setOutput(otherPin, *this, pin);
	} else {
		search = _output.find(pin);
		if (search == _output.end())
			throw Error::Paser::FileError("No corresponding pin", "C4001::setLink");
		_output[pin] = {nts::UNDEFINED, &other, static_cast<int>(otherPin)};
		other.setInput(otherPin, *this, pin);
	}

}

void C4001::dump() const
{
	std::cout << _name << std::endl;
}

void C4001::setName(const std::string &name)
{
	_name = name;
}

void C4001::setInput(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	auto search = _input.find(pin);

	if (search == _input.end())
		throw Error::Paser::FileError("No corresponding pin", "C4001::setInput");
	_input[pin] = {nts::UNDEFINED, &other, static_cast<int>(otherPin)};
}

void C4001::setOutput(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	auto search = _output.find(pin);

	if (search == _output.end())
		throw Error::Paser::FileError("No corresponding pin", "C4001::setOutput");
	_output[pin] = {nts::UNDEFINED, &other, static_cast<int>(otherPin)};
}