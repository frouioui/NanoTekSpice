/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** C4008 methodes
*/

#include "C4008.hpp"
#include "Error.hpp"
#include "IComponent.hpp"

C4008::C4008() :
Component::MyComponent(nts::C4008)
{
    nts::Pin pin1 = {1, nts::UNDEFINED, nullptr, -1};
    nts::Pin pin2 = {2, nts::UNDEFINED, nullptr, -1};
    nts::Pin pin3 = {3, nts::UNDEFINED, nullptr, -1};
    nts::Pin pin4 = {4, nts::UNDEFINED, nullptr, -1};
    nts::Pin pin5 = {5, nts::UNDEFINED, nullptr, -1};
    nts::Pin pin6 = {6, nts::UNDEFINED, nullptr, -1};
    nts::Pin pin7 = {7, nts::UNDEFINED, nullptr, -1};
    nts::Pin pin8 = {8, nts::UNDEFINED, nullptr, -1};
    nts::Pin pin10 = {10, nts::UNDEFINED, nullptr, -1};
    nts::Pin pin11 = {11, nts::UNDEFINED, nullptr, -1};
    nts::Pin pin12 = {12, nts::UNDEFINED, nullptr, -1};
    nts::Pin pin13 = {13, nts::UNDEFINED, nullptr, -1};
    nts::Pin pin15 = {15, nts::UNDEFINED, nullptr, -1};

    _carryIn = {9, nts::UNDEFINED, nullptr, -1};
    _carryOut = {14, nts::UNDEFINED, nullptr, -1};

    _doors.insert(std::pair<std::size_t, nts::Door>(10, {pin6, pin7, pin10}));
    _doors.insert(std::pair<std::size_t, nts::Door>(11, {pin4, pin5, pin11}));
    _doors.insert(std::pair<std::size_t, nts::Door>(12, {pin2, pin3, pin12}));
    _doors.insert(std::pair<std::size_t, nts::Door>(13, {pin1, pin15, pin13}));
}

C4008::~C4008()
{
}

nts::Tristate C4008::computeInput(nts::Pin &pin)
{
    if (pin.destinationName == nullptr)
        return pin.state;
    try {
        pin.state = pin.destinationName->compute(pin.destinationPin);
    } catch (Error::Component::ComputeError e) {
        std::cerr << e.what() << " " << e.where() << std::endl;
    }
    return pin.state;
}

static nts::Tristate computeXor(nts::Tristate input1, nts::Tristate input2)
{
    nts::Tristate state = nts::UNDEFINED;

    if ((input1 == nts::FALSE && input2 == nts::TRUE) ||
        (input1 == nts::TRUE && input2 == nts::FALSE))
        state = nts::TRUE;
    else if ((input1 == nts::FALSE && input2 == nts::FALSE) ||
        (input1 == nts::TRUE && input2 == nts::TRUE))
        state = nts::FALSE;
    else
        state = nts::UNDEFINED;
    return state;
}

static nts::Tristate computeAnd(nts::Tristate input1, nts::Tristate input2)
{
    nts::Tristate state = nts::UNDEFINED;

    if (input1 == nts::TRUE && input2 == nts::TRUE)
        state = nts::TRUE;
    else if (input1 == nts::FALSE || input2 == nts::FALSE)
        state = nts::FALSE;

    return state;
}

static nts::Tristate computeOr(nts::Tristate input1, nts::Tristate input2)
{
    nts::Tristate state = nts::UNDEFINED;

    if (input1 == nts::TRUE || input2 == nts::TRUE)
        state = nts::TRUE;
    else if (input1 == nts::FALSE && input2 == nts::FALSE)
        state = nts::FALSE;

    return state;
}

void C4008::computeCarryOut(nts::Tristate input1, nts::Tristate input2)
{
    nts::Tristate and1 = nts::UNDEFINED;
    nts::Tristate and2 = nts::UNDEFINED;
    nts::Tristate and3 = nts::UNDEFINED;
    nts::Tristate or1 = nts::UNDEFINED;

    and1 = computeAnd(input1, input2);
    and2 = computeAnd(input1, _carryIn.state);
    and3 = computeAnd(input2, _carryIn.state);

    or1 = computeOr(and1, and2);
    _carryOut.state = computeOr(or1, and3);
}

void C4008::computeCarryIn()
{
    _carryIn.state = _carryOut.state;
}

nts::Tristate C4008::computeOutput(nts::Door &door)
{
    nts::Tristate input1State = computeInput(door.input1);
    nts::Tristate input2State = computeInput(door.input2);
    nts::Tristate state = nts::UNDEFINED;

    if (_carryIn.state == nts::UNDEFINED)
        computeInput(_carryIn);
    else
        computeCarryIn();
    state = computeXor(input1State, input2State);
    door.output.state = computeXor(state, _carryIn.state);

    computeCarryOut(input1State, input2State);

    return door.output.state;
}

nts::Tristate C4008::compute(std::size_t pin)
{
    nts::Tristate state = nts::UNDEFINED;
    bool found = false;

    for (auto it_d = _doors.begin(); it_d != _doors.end(); ++it_d) {
        if (pin == it_d->first) {
            state = computeOutput(it_d->second);
            found = true;
        }
        computeOutput(it_d->second);
    }
    if (found == true)
        return state;
    if (_carryOut.pin == pin)
        state = _carryOut.state;
    return state;
}

void C4008::checkSelfLink(std::size_t pin1, std::size_t pin2)
{
    bool input = false;
    bool output = false;

    for (auto it = _doors.begin(); it != _doors.end(); ++it) {
        if (((it->second.input1.pin == pin1 || it->second.input1.pin == pin2) ||
        (it->second.input2.pin == pin1 || it->second.input2.pin == pin2)) &&
        ((it->second.output.pin == pin1 || it->second.output.pin == pin2)))
            throw Error::Component::LinkError ("Door linked to itself", "C4008::checkSelfLink");

        if (it->second.input1.pin == pin1 || it->second.input1.pin == pin2)
            input = true;
        if (it->second.input2.pin == pin1 || it->second.input2.pin == pin2)
            input = true;
        if (it->second.output.pin == pin1 || it->second.output.pin == pin2)
            output = true;
    }
    if (!(input == true && output == true))
        throw Error::Parser::FileError("No corresponding pin", "C4008::checkSelfLink");
}

void C4008::setLink(std::size_t pin , nts::IComponent &other, std::size_t otherPin)
{
    bool find = false;

    if (this == &other)
        checkSelfLink(pin, otherPin);
    for (auto it = _doors.begin(); it != _doors.end() && find == false; ++it) {
        if (it->second.input1.pin == pin) {
            it ->second.input1.destinationName = &other;
            it->second.input1.destinationPin = otherPin;
            try {
                other.setOutput(otherPin, *this, pin);
            } catch (Error::Error e) {
                std::cerr << e.what() << " " << e.where() << std::endl;
                throw;
            }
            find = true;
        }
        if (it->second.input2.pin == pin) {
            it ->second.input2.destinationName = &other;
            it->second.input2.destinationPin = otherPin;
            try {
                other.setOutput(otherPin, *this, pin);
            } catch (Error::Error e) {
                std::cerr << e.what() << " " << e.where() << std::endl;
                throw;
            }
            find = true;
        }
        if (it->second.output.pin == pin) {
            it ->second.output.destinationName = &other;
            it->second.output.destinationPin = otherPin;
            try {
                other.setInput(otherPin, *this, pin);
            } catch (Error::Error e) {
                std::cerr << e.what() << " " << e.where() << std::endl;
                throw;
            }
            find = true;
        }
    }
    if (find == false)
        throw Error::Parser::FileError("No corresponding pin", "C4008::setLink");
}

void C4008::setInput(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    bool find = false;

    for (auto it = _doors.begin(); it != _doors.end() && find == false; ++it) {
        if (it->second.input1.pin == pin) {
            if (it->second.input1.destinationName != nullptr)
                throw Error::Component::LinkError("Pin already linked", "C4008::setInput");
            it ->second.input1.destinationName = &other;
            it->second.input1.destinationPin = otherPin;
            find = true;
        }
        if (it->second.input2.pin == pin) {
            if (it->second.input2.destinationName != nullptr)
                throw Error::Component::LinkError("Pin already linked", "C4008::setInput");
            it ->second.input2.destinationName = &other;
            it->second.input2.destinationPin = otherPin;
            find = true;
        }
    }
    if (_carryIn.pin == pin) {
        _carryIn.destinationName = &other;
        _carryIn.destinationPin = otherPin;
        find = true;
    }
    if (find == false)
        throw Error::Parser::FileError("No corresponding pin", "C4008::setInput");
}

void C4008::setOutput(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    bool find = false;

    for (auto it = _doors.begin(); it != _doors.end() && find == false; ++it) {
        if (it->second.output.pin == pin) {
            it ->second.output.destinationName = &other;
            it->second.output.destinationPin = otherPin;
            find = true;
        }
    }
    if (_carryOut.pin == pin) {
        _carryOut.destinationName = &other;
        _carryOut.destinationPin = otherPin;
        find = true;
    }
    if (find == false)
        throw Error::Parser::FileError("No corresponding pin", "C4008::setOutput");
}

void C4008::dump() const noexcept
{
    std::cout << std::endl << "-----------------------------------------------" << std::endl;
    std::cout << "C4008 #" <<_name << std::endl;

    std::cout << "\tcarry in #" << _carryIn.pin <<std::endl;
    std::cout << "\t\t->state: " << _carryIn.state << std::endl;
    if (_carryIn.destinationName != nullptr)
        std::cout << "\t\t->linked to: " << _carryIn.destinationName->getName() <<
        " - pin #" << _carryIn.destinationPin << std::endl;
    else
        std::cout << "\t\t-> no linked" << std::endl;

    for (auto it = _doors.begin(); it != _doors.end(); ++it) {
        std::cout << "\tdoor #" << it->first << std::endl;
        std::cout << "\t\tinput 1: pin #" << it->second.input1.pin << std::endl <<
        "\t\t\t-> state: " << it->second.input1.state << std::endl;
        if (it->second.input1.destinationName != nullptr)
            std::cout << "\t\t\t->linked to: " << it->second.input1.destinationName->getName() <<
            " - pin #" << it->second.input1.destinationPin << std::endl;
        else
            std::cout << "\t\t\t-> no linked" << std::endl;

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
    std::cout << "\tcarry out #" << _carryOut.pin << std::endl;
    std::cout << "\t\t->state: " << _carryOut.state << std::endl;
    if (_carryOut.destinationName != nullptr)
        std::cout << "\t\t->linked to: " << _carryOut.destinationName->getName() <<
        " - pin #" << _carryOut.destinationPin << std::endl;
    else
        std::cout << "\t\t-> no linked" << std::endl;
}