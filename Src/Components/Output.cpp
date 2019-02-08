/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Output methodes
*/

#include "Output.hpp"
#include "Error.hpp"
#include "IComponent.hpp"

Output::Output() :
Component::MyComponent(nts::OUTPUT)
{
    _input.insert(std::pair<std::size_t, nts::Pin>(1, {1, nts::UNDEFINED, nullptr, -1}));
}

Output::~Output()
{
}

void Output::displayState(std::size_t pin) const noexcept
{
    auto search = _input.find(pin);

    std::cout << _name << "=" << search->second.state << std::endl;
}

nts::Tristate Output::compute(std::size_t pin)
{
    auto search = _input.find(pin);

    if (search == _input.end())
        throw Error::Component::ComputeError("No corresponding pin", "Output::compute");
    if (search->second.destinationName == nullptr) {
        return nts::UNDEFINED;
    }
    try {
        _input[pin].state = search->second.destinationName->compute(search->second.destinationPin);
    } catch (Error::Component::ComputeError e) {
        std::cerr << e.what() << " " << e.where() << std::endl;
        throw;
    }
    displayState(pin);
    return _input[pin].state;
}

void Output::setLink(std::size_t pin , nts::IComponent &other, std::size_t otherPin)
{
    auto search = _input.find(pin);

    if (search == _input.end())
        throw Error::Parser::FileError("No corresponding pin", "Output::setLink");
    _input[pin] = {pin, nts::UNDEFINED, &other, static_cast<int>(otherPin)};
    try {
        other.setOutput(otherPin, *this, pin);
    }
    catch (Error::Parser::FileError e) {
        std::cerr << e.what() << " " << e.where() << std::endl;
        throw;
    }
    catch (Error::Component::LinkError e) {
        std::cerr << e.what() << " " << e.where() << std::endl;
        throw;
    }
}

void Output::setInput(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    auto search = _input.find(pin);

    if (search == _input.end())
        throw Error::Parser::FileError("No corresponding pin", "Output::setInput");
    if (_input[pin].destinationName != nullptr)
        throw Error::Component::LinkError("Pin already linked", "Output::setInput");
    _input[pin] = {pin, nts::UNDEFINED, &other, static_cast<int>(otherPin)};
}

void Output::setOutput(std::size_t, nts::IComponent &, std::size_t)
{
}

void Output::dump() const noexcept
{
    std::cout << std::endl << "-----------------------------------------------" << std::endl;
    std::cout << "Output #" <<_name << std::endl;

    for (auto it = _input.begin(); it != _input.end(); ++it) {
        std::cout << "\tpin #" << it->second.pin << std::endl <<
        "\t-> state: " << it->second.state << std::endl <<
        "\t-> linked to: " << it->second.destinationName->getName() <<
        " - pin #" << it->second.destinationPin << std::endl;
    }
}