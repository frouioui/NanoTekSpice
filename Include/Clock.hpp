/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Clock class
*/

#ifndef CLOCK_HPP_
    #define CLOCK_HPP_

#include "Component.hpp"
#include <iostream>
#include <map>

class Clock : public Component::MyComponent
{
    public:
        Clock();
        ~Clock();

        nts::Tristate compute(std::size_t pin = 1) override;
        void setLink(std::size_t pin , nts::IComponent &other, std::size_t otherPin) override;
        void dump() const noexcept override;

        void setInput(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;
        void setOutput(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;

        void setState(const std::string &state) final;

    private:
        std::map<size_t, nts::Pin> _output;
};

#endif /* !CLOCK_HPP_ */