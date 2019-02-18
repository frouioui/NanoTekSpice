/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** False methodes
*/

#include "False.hpp"
#include "Error.hpp"

False::False() :
Component::MyComponent(nts::CFALSE)
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
    try {
      other.setInput(otherPin, *this, pin);
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

void False::setInput(std::size_t, nts::IComponent &, std::size_t)
{
}

void False::setOutput(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    auto search = _output.find(pin);

    if (search == _output.end())
        throw Error::Parser::FileError("No corresponding pin", "False::setOutput");
    if (_output[pin].destinationName != nullptr)
        throw Error::Component::LinkError("Pin already linked", "False::setOutput");
    _output[pin] = {pin, nts::FALSE, &other, static_cast<int>(otherPin)};
}

void False::dump() const noexcept
{
    std::cout << std::endl << "-----------------------------------------------" << std::endl;
    std::cout << "False #" << _name << std::endl;

    for (auto it = _output.begin(); it != _output.end(); ++it) {
        std::cout << "\tpin #" << it->second.pin << std::endl <<
        "\t-> state: " << it->second.state << std::endl <<
        "\t-> linked to: " << it->second.destinationName->getName() <<
        " - pin #" << it->second.destinationPin << std::endl;
    }
}