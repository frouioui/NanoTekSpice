/*
** EPITECH PROJECT, 2019
** OOP_NanoTekSpice
** File description:
** Input class
*/

#ifndef INPUT_HPP_
    #define INPUT_HPP_

#include "Component.hpp"
#include <iostream>
#include <map>

class Input : public Component::MyComponent
{
    public:
        Input();
        ~Input();

        nts::Tristate compute(std::size_t pin = 1) override;
        void setLink(std::size_t pin , nts::IComponent &other, std::size_t otherPin) override;
        void dump() const noexcept override;

        void setInput(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;
        void setOutput(std::size_t pin, nts::IComponent &other, std::size_t otherPin) final;

        void setState(const std::string &state) final;

    private:
        std::map<size_t, nts::Pin> _output;
};

#endif /* !INPUT_HPP_ */