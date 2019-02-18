/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** C4514 methodes
*/

#include <cmath>
#include "C4514.hpp"
#include "Error.hpp"
#include "IComponent.hpp"

C4514::C4514() :
Component::MyComponent(nts::C4514)
{
    _inputs[1] = {1, nts::UNDEFINED, nullptr, -1};
    _inputs[2] = {2, nts::UNDEFINED, nullptr, -1};
    _inputs[3] = {3, nts::UNDEFINED, nullptr, -1};
    _inputs[21] = {21, nts::UNDEFINED, nullptr, -1};
    _inputs[22] = {22, nts::UNDEFINED, nullptr, -1};
    _inputs[23] = {23, nts::UNDEFINED, nullptr, -1};

    _outputs[11] = {0, nts::UNDEFINED, nullptr, -1};
    _outputs[9] = {1, nts::UNDEFINED, nullptr, -1};
    _outputs[10] = {2, nts::UNDEFINED, nullptr, -1};
    _outputs[8] = {3, nts::UNDEFINED, nullptr, -1};
    _outputs[7] = {4, nts::UNDEFINED, nullptr, -1};
    _outputs[6] = {5, nts::UNDEFINED, nullptr, -1};
    _outputs[5] = {6, nts::UNDEFINED, nullptr, -1};
    _outputs[4] = {7, nts::UNDEFINED, nullptr, -1};
    _outputs[18] = {8, nts::UNDEFINED, nullptr, -1};
    _outputs[17] = {9, nts::UNDEFINED, nullptr, -1};
    _outputs[20] = {10, nts::UNDEFINED, nullptr, -1};
    _outputs[19] = {11, nts::UNDEFINED, nullptr, -1};
    _outputs[14] = {12, nts::UNDEFINED, nullptr, -1};
    _outputs[13] = {13, nts::UNDEFINED, nullptr, -1};
    _outputs[13] = {13, nts::UNDEFINED, nullptr, -1};
    _outputs[16] = {14, nts::UNDEFINED, nullptr, -1};
    _outputs[15] = {15, nts::UNDEFINED, nullptr, -1};
}

C4514::~C4514()
{
}

nts::Tristate C4514::computeInput(nts::Pin &pin)
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

static size_t tranfsormBinaryToDecimal(nts::Tristate a, nts::Tristate b, nts::Tristate c, nts::Tristate d)
{
    size_t remainder = 0;
    size_t binary = a * 1000 + b * 100 + c * 10 + b;
    size_t result = 0;

    for (unsigned int i = 0; binary != 0; i++) {
        remainder = binary % 10;
        binary /= 10;
        result += remainder * std::pow(2, i);
    }
    return (result);
}

nts::Tristate C4514::computeOutput(nts::Pin &pin)
{
    size_t conv = 0;

    for (auto it = _inputs.begin(); it != _inputs.end(); ++it)
        computeInput(it->second);
    conv = tranfsormBinaryToDecimal(_inputs[2].state, _inputs[3].state, _inputs[21].state, _inputs[22].state);
    if (conv == pin.pin)
        pin.state = nts::TRUE;
    else
        pin.state = nts::FALSE;
    return pin.state;
}

nts::Tristate C4514::compute(std::size_t pin)
{
    if (_inputs[23].state == nts::TRUE)
        _outputs[pin].state = nts::FALSE;
    for (auto it = _outputs.begin(); it != _outputs.end(); ++it) {
        if (pin == it->first) {
            return computeOutput(it->second);
        }
    }
    return nts::UNDEFINED;
}

void C4514::checkSelfLink(std::size_t pin1, std::size_t pin2)
{
    bool input = false;
    bool output = false;

    for (auto it = _inputs.begin(); it != _inputs.end(); ++it) {
        if (it->first == pin1 || it->first == pin2)
            input = true;
    }
    for (auto it = _outputs.begin(); it != _outputs.end(); ++it) {
        if (it->first == pin1 || it->first == pin2)
            output = true;
    }
    if (!(input == true && output == true))
        throw Error::Parser::FileError("No corresponding pin", "C4514::checkSelfLink");
}

void C4514::setLink(std::size_t pin , nts::IComponent &other, std::size_t otherPin)
{
    bool find = false;

    if (this == &other)
        checkSelfLink(pin, otherPin);
    for (auto it = _inputs.begin(); it != _inputs.end() && find == false; ++it) {
        if (it->first == pin) {
            it ->second.destinationName = &other;
            it->second.destinationPin = otherPin;
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
            find = true;
        }
    }
    for (auto it = _outputs.begin(); it != _outputs.end() && find == false; ++it) {
        if (it->first == pin) {
            it ->second.destinationName = &other;
            it->second.destinationPin = otherPin;
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
            find = true;
        }
    }
    if (find == false)
        throw Error::Parser::FileError("No corresponding pin", "C4514::setLink");
}

void C4514::setInput(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    bool find = false;

    for (auto it = _inputs.begin(); it != _inputs.end() && find == false; ++it) {
        if (it->first == pin) {
            if (it->second.destinationName != nullptr)
                throw Error::Component::LinkError("Pin already linked", "C4514::setInput");
            it->second.destinationName = &other;
            it->second.destinationPin = otherPin;
            find = true;
        }
    }
    if (find == false)
        throw Error::Parser::FileError("No corresponding pin", "C4514::setInput");
}

void C4514::setOutput(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    bool find = false;

    for (auto it = _outputs.begin(); it != _outputs.end() && find == false; ++it) {
        if (it->first == pin) {
            it->second.destinationName = &other;
            it->second.destinationPin = otherPin;
            find = true;
        }
    }
    if (find == false)
        throw Error::Parser::FileError("No corresponding pin", "C4514::setOutput");
}

void C4514::dump() const noexcept
{
    std::cout << std::endl << "-----------------------------------------------" << std::endl;
    std::cout << "C4514 #" <<_name << std::endl;
    for (auto it = _inputs.begin(); it != _inputs.end(); ++it) {
        std::cout << "\tinput #" << it->second.pin << std::endl <<
        "\t\t-> state: " << it->second.state << std::endl;
        if (it->second.destinationName != nullptr)
            std::cout << "\t\t->linked to: " << it->second.destinationName->getName() <<
            " - pin #" << it->second.destinationPin << std::endl;
        else
            std::cout << "\t\t-> no linked" << std::endl;
    }
    for (auto it = _outputs.begin(); it != _outputs.end(); ++it) {
        std::cout << "\toutput #" << it->second.pin << std::endl <<
        "\t\t-> state: " << it->second.state << std::endl;
        if (it->second.destinationName != nullptr)
            std::cout << "\t\t->linked to: " << it->second.destinationName->getName() <<
            " - pin #" << it->second.destinationPin << std::endl;
        else
            std::cout << "\t\t-> no linked" << std::endl;
    }
}