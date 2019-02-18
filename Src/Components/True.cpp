/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** True methodes
*/

#include "True.hpp"
#include "Error.hpp"
#include "IComponent.hpp"

True::True() :
Component::MyComponent(nts::CTRUE)
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
        throw Error::Parser::FileError("No corresponding pin", "True::setLink");
    _output[pin] = {pin, nts::TRUE, &other, static_cast<int>(otherPin)};
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

void True::setInput(std::size_t, nts::IComponent &, std::size_t)
{
}

void True::setOutput(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    auto search = _output.find(pin);

    if (search == _output.end())
        throw Error::Parser::FileError("No corresponding pin", "True::setOutput");
    if (_output[pin].destinationName != nullptr)
        throw Error::Component::LinkError("Pin already linked", "True::setOutput");
    _output[pin] = {pin, nts::TRUE, &other, static_cast<int>(otherPin)};
}

void True::dump() const noexcept
{
    std::cout << std::endl << "-----------------------------------------------" << std::endl;
    std::cout << "True #" << _name << std::endl;

    for (auto it = _output.begin(); it != _output.end(); ++it) {
        std::cout << "\tpin #" << it->second.pin << std::endl <<
        "\t-> state: " << it->second.state << std::endl <<
        "\t-> linked to: " << it->second.destinationName->getName() <<
        " - pin #" << it->second.destinationPin << std::endl;
    }
}