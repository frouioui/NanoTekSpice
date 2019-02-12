/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Output class
*/

#ifndef OUTPUT_HPP_
    #define OUTPUT_HPP_

#include "Component.hpp"
#include <iostream>
#include <map>

class Output : public Component::MyComponent
{
    public:
        Output();
        ~Output();

        nts::Tristate compute(std::size_t pin = 1) override;
        void setLink(std::size_t pin , nts::IComponent &other, std::size_t otherPin) override;
        void dump() const noexcept override;


        void setInput(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;
        void setOutput(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;

        void displayState(std::size_t pin) const noexcept override;

    private:

        std::map<size_t, nts::Pin> _input;
};

#endif /* !OUTPUT_HPP_ */