/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** C4001 methodes
*/

#include "C4001.hpp"
#include "Error.hpp"
#include "IComponent.hpp"

C4001::C4001() :
Component::MyComponent(nts::C4001)
{
	nts::Pin pin1 = {1, nts::UNDEFINED, nullptr, -1};
	nts::Pin pin2 = {2, nts::UNDEFINED, nullptr, -1};
	nts::Pin pin3 = {3, nts::UNDEFINED, nullptr, -1};
	nts::Pin pin4 = {4, nts::UNDEFINED, nullptr, -1};
	nts::Pin pin5 = {5, nts::UNDEFINED, nullptr, -1};
	nts::Pin pin6 = {6, nts::UNDEFINED, nullptr, -1};
	nts::Pin pin7 = {7, nts::UNDEFINED, nullptr, -1};
	nts::Pin pin8 = {8, nts::UNDEFINED, nullptr, -1};
	nts::Pin pin9 = {9, nts::UNDEFINED, nullptr, -1};
	nts::Pin pin10 = {10, nts::UNDEFINED, nullptr, -1};
	nts::Pin pin11 = {11, nts::UNDEFINED, nullptr, -1};
	nts::Pin pin12 = {12, nts::UNDEFINED, nullptr, -1};
	nts::Pin pin13 = {13, nts::UNDEFINED, nullptr, -1};
	nts::Pin pin14 = {14, nts::UNDEFINED, nullptr, -1};

	_doors.insert(std::pair<std::size_t, nts::Door>(3, {pin1, pin2, pin3}));
	_doors.insert(std::pair<std::size_t, nts::Door>(4, {pin5, pin6, pin4}));
	_doors.insert(std::pair<std::size_t, nts::Door>(10, {pin8, pin9, pin10}));
	_doors.insert(std::pair<std::size_t, nts::Door>(11, {pin12, pin13, pin11}));
}

C4001::~C4001()
{
}

nts::Tristate C4001::computeInput(nts::Pin pin)
{
	if (pin.destinationName == nullptr)
		return pin.state;
	pin.state = pin.destinationName->compute(pin.destinationPin);
	return pin.state;
}

nts::Tristate C4001::computeOutput(nts::Door door)
{
	nts::Tristate input1State = computeInput(door.input1);
	nts::Tristate input2State = computeInput(door.input2);

	if (input1State == nts::FALSE && input2State == nts::FALSE)
		return nts::TRUE;
	if (input1State == nts::TRUE || input2State == nts::TRUE)
		return nts::FALSE;
	return nts::UNDEFINED;
}

nts::Tristate C4001::compute(std::size_t pin)
{
	for (auto it_d = _doors.begin(); it_d != _doors.end(); ++it_d) {
		if (pin == it_d->first) {
			return computeOutput(it_d->second);
		}
	}
	for (auto it_d = _doors.begin(); it_d != _doors.end(); ++it_d) {
		if (pin == it_d->second.input1.pin)
			return computeInput(it_d->second.input1);
		else if (pin == it_d->second.input2.pin)
			return computeInput(it_d->second.input2);
	}
	return nts::UNDEFINED;
}

void C4001::checkSelfLink(std::size_t pin1, std::size_t pin2)
{
	bool input = false;
	bool output = false;

	for (auto it = _doors.begin(); it != _doors.end(); ++it) {
		if (it->second.input1.pin == pin1 || it->second.input1.pin == pin2)
			input = true;
		if (it->second.input2.pin == pin1 || it->second.input2.pin == pin2)
			input = true;
		if (it->second.output.pin == pin1 || it->second.output.pin == pin2)
			output = true;
	}
	if (!(input == true && output == true))
		throw Error::Parser::FileError("No corresponding pin", "C4001::checkSelfLink");
}

void C4001::setLink(std::size_t pin , nts::IComponent &other, std::size_t otherPin)
{
	bool find = false;

	if (this == &other)
		checkSelfLink(pin, otherPin);
	for (auto it = _doors.begin(); it != _doors.end() && find == false; ++it) {
		if (it->second.input1.pin == pin) {
			it ->second.input1.destinationName = &other;
			it->second.input1.destinationPin = otherPin;
			other.setOutput(otherPin, *this, pin);
			find = true;
		}
		if (it->second.input2.pin == pin) {
			it ->second.input2.destinationName = &other;
			it->second.input2.destinationPin = otherPin;
			other.setOutput(otherPin, *this, pin);
			find = true;
		}
		if (it->second.output.pin == pin) {
			it ->second.output.destinationName = &other;
			it->second.output.destinationPin = otherPin;
			other.setInput(otherPin, *this, pin);
			find = true;
		}
	}
	if (find == false)
		throw Error::Parser::FileError("No corresponding pin", "C4001::setLink");
}

void C4001::dump() const
{
	std::cout << std::endl << "-----------------------------------------------" << std::endl;
	std::cout << "C4001 #" <<_name << std::endl;
	for (auto it = _doors.begin(); it != _doors.end(); ++it) {
		std::cout << "\tdoor #" << it->first << std::endl;
		std::cout << "\t\tinput 1: pin #" << it->second.input1.pin << std::endl <<
		"\t\t\t-> state: " << it->second.input1.state << std::endl;
		if (it->second.input1.destinationName != nullptr)
			std::cout << "\t\t\t->linked to: " << it->second.input1.destinationName->getName() <<
			" - pin #" << it->second.input1.destinationPin << std::endl;
		else
			std::cout << "\t\t\t-> no linked" <<std::endl;

		std::cout << "\t\tinput 2: pin #" << it->second.input2.pin << std::endl <<
		"\t\t\t-> state: " << it->second.input2.state << std::endl;
		if (it->second.input2.destinationName != nullptr)
			std::cout << "\t\t\t->linked to: " << it->second.input2.destinationName->getName() <<
			" - pin #" << it->second.input2.destinationPin << std::endl;
		else
			std::cout << "\t\t\t-> no linked" <<std::endl;

		std::cout << "\t\toutput:  pin #" << it->second.output.pin << std::endl <<
		"\t\t\t-> state: " << it->second.output.state << std::endl;
		if (it->second.output.destinationName != nullptr)
			std::cout << "\t\t\t->linked to: " << it->second.output.destinationName->getName() <<
			" - pin #" << it->second.output.destinationPin << std::endl;
		else
			std::cout << "\t\t\t-> no linked" <<std::endl;
	}
}

void C4001::setInput(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	bool find = false;

	for (auto it = _doors.begin(); it != _doors.end() && find == false; ++it) {
		if (it->second.input1.pin == pin) {
			if (it->second.input1.destinationName != nullptr)
				throw Error::Component::LinkError("Pin already linked", "C4001::setInput");
			it ->second.input1.destinationName = &other;
			it->second.input1.destinationPin = otherPin;
			find = true;
		}
		if (it->second.input2.pin == pin) {
			if (it->second.input2.destinationName != nullptr)
				throw Error::Component::LinkError("Pin already linked", "C4001::setInput");
			it ->second.input2.destinationName = &other;
			it->second.input2.destinationPin = otherPin;
			find = true;
		}
	}
	if (find == false)
		throw Error::Parser::FileError("No corresponding pin", "C4001::setInput");
}

void C4001::setOutput(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	bool find = false;

	for (auto it = _doors.begin(); it != _doors.end() && find == false; ++it) {
		if (it->second.output.pin == pin) {
			it ->second.output.destinationName = &other;
			it->second.output.destinationPin = otherPin;
			find = true;
		}
	}
	if (find == false)
		throw Error::Parser::FileError("No corresponding pin", "C4001::setOutput");
}