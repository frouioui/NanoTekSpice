/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** True class
*/

#ifndef TRUE_HPP_
    #define TRUE_HPP_

#include "Component.hpp"
#include <iostream>
#include <map>

class True : public Component::MyComponent
{
    public:
        True();
        ~True();

        nts::Tristate compute(std::size_t pin = 1) override;
        void setLink(std::size_t pin , nts::IComponent &other, std::size_t otherPin) override;
        void dump() const noexcept override;

        void setInput(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;
        void setOutput(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;

    private:
        std::map<size_t, nts::Pin> _output;
};

#endif /* !TRUE_HPP_ */